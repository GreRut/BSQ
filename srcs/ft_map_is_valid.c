/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:02:32 by gruta             #+#    #+#             */
/*   Updated: 2024/09/11 23:18:04 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	val_map_chars(char *buff_val, int line_start,
	int file_size, t_map_data *map_data)
{
	int	i;

	i = line_start;
	while (i < file_size)
	{
		if (!(buff_val[i] == map_data->chars->c_empty
				|| buff_val[i] == map_data->chars->c_obstacle
				|| buff_val[i] == map_data->chars->c_full
				|| buff_val[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	update_max_row_length(int current_row_length,
	int row_count, int max_row_length)
{
	if (row_count == 0)
		return (current_row_length);
	if (current_row_length != max_row_length)
		return (-1);
	return (max_row_length);
}

int	process_row_end(int i, int *row_start, int *row_count, int *max_row_length)
{
	int	current_row_length;

	current_row_length = i - *row_start;
	*max_row_length = update_max_row_length(current_row_length,
			*row_count, *max_row_length);
	if (*max_row_length == -1)
		return (0);
	*row_start = i + 1;
	(*row_count)++;
	return (1);
}

int	validate_row_lengths(char *buff_val, int file_size, t_map_data *map_data)
{
	int	i;
	int	row_start;
	int	row_count;
	int	max_row_length;
	int	current_row_length;

	row_start = map_data->first_line_len;
	i = map_data->first_line_len;
	row_count = 0;
	max_row_length = 0;
	while (i < file_size)
	{
		if (buff_val[i] == '\n')
			if (!process_row_end(i, &row_start, &row_count, &max_row_length))
				return (0);
		i++;
	}
	if (i > row_start)
	{
		current_row_length = i - row_start;
		if (current_row_length != max_row_length)
			return (0);
	}
	map_data->columns = max_row_length;
	return (1);
}

t_map_data	*ft_map_is_valid(char *file_path)
{
	char		*buff_val;
	int			file_size;
	t_map_data	*map_data;
	int			line_start;

	map_data = ft_create_map_data();
	if (!map_data)
		return (NULL);
	buff_val = ft_read_input(file_path, &file_size);
	if (!buff_val)
		return (ft_free_and_return(buff_val, map_data));
	if (!ft_find_metadata_line(buff_val, file_size, &line_start, map_data))
		return (ft_free_and_return(buff_val, map_data));
	if (!validate_row_lengths(buff_val, file_size, map_data))
		return (ft_free_and_return(buff_val, map_data));
	if (!val_map_chars(buff_val, line_start, file_size, map_data))
		return (ft_free_and_return(buff_val, map_data));
	map_data->buff_val = buff_val;
	return (map_data);
}
