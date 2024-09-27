/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frzeznic <frzeznic@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:48:54 by frzeznic          #+#    #+#             */
/*   Updated: 2024/09/11 21:47:02 by frzeznic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void			ft_set_max_square_size(t_map_data *map_data);
t_max_square	*ft_create_max_square(void);

int	ft_refill_map_data(t_map_data *map_data)
{
	ft_set_max_square_size(map_data);
	map_data->max_square = ft_create_max_square();
	if (!map_data->max_square)
	{
		ft_free_map_data(map_data);
		return (0);
	}
	return (1);
}

void	ft_set_max_square_size(t_map_data *map_data)
{
	if (map_data-> rows < map_data->columns)
		map_data->max_square_size = map_data->rows;
	else
		map_data->max_square_size = map_data->columns;
}
