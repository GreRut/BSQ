/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_data_builders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:49:02 by frzeznic          #+#    #+#             */
/*   Updated: 2024/09/11 23:20:48 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

t_max_square	*ft_create_max_square(void)
{
	t_max_square	*max_square;

	max_square = malloc(sizeof(t_max_square));
	if (!max_square)
		return (NULL);
	max_square->size = 0;
	max_square->row = 0;
	max_square->col = 0;
	return (max_square);
}

t_map_data	*ft_create_map_data(void)
{
	t_map_data	*map_data;

	map_data = malloc(sizeof(t_map_data));
	if (!map_data)
		return (NULL);
	map_data->buff_val = NULL;
	map_data->chars = NULL;
	map_data->max_square = NULL;
	return (map_data);
}

t_characters	*ft_create_chars(char empty, char obstacle, char full)
{
	t_characters	*chars;

	chars = malloc(sizeof(t_characters));
	if (!chars)
		return (NULL);
	chars->c_empty = empty;
	chars->c_obstacle = obstacle;
	chars->c_full = full;
	return (chars);
}
