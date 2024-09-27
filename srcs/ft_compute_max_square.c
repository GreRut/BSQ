/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_max_square.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frzeznic <frzeznic@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:49:05 by frzeznic          #+#    #+#             */
/*   Updated: 2024/09/11 23:02:41 by frzeznic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_try_create_square(char **map, t_map_data *map_data, int i, int j);
void	ft_set_max_square(t_map_data *map_data, t_max_square current_square);

void	ft_compute_max_square(char **map, t_map_data *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->rows - map_data->max_square->size)
	{
		j = 0;
		while (j < map_data->columns - map_data->max_square->size)
		{
			if (map[i][j] != map_data->chars->c_obstacle)
			{
				ft_try_create_square(map, map_data, i, j);
				if (map_data->max_square->size == map_data->max_square_size)
					return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_try_create_square(char **map, t_map_data *map_data, int i, int j)
{
	int				row;
	int				col;
	t_max_square	current_square;

	current_square.row = i++;
	current_square.col = j++;
	current_square.size = 1;
	while (i < map_data->rows && j < map_data->columns)
	{
		row = current_square.row;
		while (row <= i && map[row][j] != map_data->chars->c_obstacle)
			row++;
		if (row <= i)
			break ;
		col = current_square.col;
		while (col < j && map[i][col] != map_data->chars->c_obstacle)
			col++;
		if (col < j)
			break ;
		current_square.size++;
		i++;
		j++;
	}
	ft_set_max_square(map_data, current_square);
}

void	ft_set_max_square(t_map_data *map_data, t_max_square current_square)
{
	if (current_square.size <= map_data->max_square->size)
		return ;
	map_data->max_square->size = current_square.size;
	map_data->max_square->row = current_square.row;
	map_data->max_square->col = current_square.col;
}
