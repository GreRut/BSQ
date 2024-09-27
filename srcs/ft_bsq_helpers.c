/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frzeznic <frzeznic@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:49:08 by frzeznic          #+#    #+#             */
/*   Updated: 2024/09/11 22:49:30 by frzeznic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	**ft_load_map(t_map_data *map_data)
{
	char	**map;
	char	*row;
	int		i;
	int		offset;

	i = 0;
	offset = map_data->first_line_len;
	map = malloc(sizeof(char *) * map_data->rows);
	if (!map)
		return (NULL);
	while (i < map_data->rows)
	{
		row = malloc(map_data->columns);
		if (!row)
		{
			ft_free_map(map, i);
			return (NULL);
		}
		ft_buff_cpy(row, &map_data->buff_val[offset], map_data->columns);
		offset = offset + map_data->columns + 1;
		map[i++] = row;
	}
	return (map);
}

void	ft_free_map(char **map, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(map[i++]);
	free(map);
}

void	ft_free_map_data(t_map_data *map_data)
{
	if (map_data->chars)
		free(map_data->chars);
	if (map_data->max_square)
		free(map_data->max_square);
	if (map_data->buff_val)
		free(map_data->buff_val);
	free(map_data);
}

void	ft_print_map(char **map, t_map_data *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->rows)
	{
		write(1, map[i], map_data->columns);
		write(1, "\n", 1);
		i++;
	}
}
