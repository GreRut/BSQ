/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_metadata_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:46:49 by gruta             #+#    #+#             */
/*   Updated: 2024/09/11 23:16:41 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	is_custom_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	get_valid_number(char *buff_val, int i)
{
	int	c;
	int	rows_count;

	c = 0;
	rows_count = 0;
	while (c < i - 3)
	{
		if (buff_val[c] < '0' || buff_val[c] > '9')
			return (-1);
		if (rows_count > (INT_MAX / 10))
			return (-1);
		if (rows_count == (INT_MAX / 10)
			&& (buff_val[c] - '0') > (INT_MAX % 10))
			return (-1);
		rows_count = rows_count * 10 + (buff_val[c] - '0');
		c++;
	}
	return (rows_count);
}

int	check_metadata(char *buff_val, int i, t_map_data *map_data)
{
	char	empty;
	char	obstacle;
	char	full;

	if (i < 4)
		return (0);
	empty = buff_val[i - 3];
	obstacle = buff_val[i - 2];
	full = buff_val[i - 1];
	if (!(empty != obstacle && empty != full
			&& obstacle != full && is_custom_printable(empty)
			&& is_custom_printable(obstacle) && is_custom_printable(full)))
		return (0);
	map_data->rows = get_valid_number(buff_val, i);
	if (map_data->rows < 0)
		return (0);
	map_data->chars = ft_create_chars(empty, obstacle, full);
	if (!map_data->chars)
		return (0);
	return (1);
}

int	ft_find_metadata_line(char *buff_val,
	int file_size, int *line_start, t_map_data *map_data)
{
	int	i;

	i = 0;
	while (i < file_size)
	{
		if (buff_val[i] == '\n')
		{
			if (check_metadata(buff_val, i, map_data))
			{
				*line_start = i + 1;
				map_data->first_line_len = *line_start;
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (0);
}
