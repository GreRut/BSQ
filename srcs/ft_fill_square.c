/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frzeznic <frzeznic@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:14:56 by gruta             #+#    #+#             */
/*   Updated: 2024/09/10 21:58:49 by frzeznic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_fill_square(char **map, t_map_data *map_data)
{
	int	i;
	int	j;
	int	row;
	int	col;

	i = map_data->max_square->row;
	j = map_data->max_square->col;
	row = 0;
	while (row < map_data->max_square->size)
	{
		col = 0;
		while (col < map_data->max_square->size)
		{
			map[i + row][j + col] = map_data->chars->c_full;
			col++;
		}
		row++;
	}
}
