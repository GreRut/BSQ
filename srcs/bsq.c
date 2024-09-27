/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:03:57 by gruta             #+#    #+#             */
/*   Updated: 2024/09/11 23:21:28 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_read_stdin(void);
void	ft_process_files(int n, char **files);
void	ft_process_map(char *file_path, t_map_data *map_data);
void	ft_bsq(char **map, t_map_data *map_data, char *file_path);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_read_stdin();
		return (0);
	}
	argc--;
	argv++;
	ft_process_files(argc, argv);
	return (0);
}

void	ft_process_files(int n, char **files)
{
	int			i;
	t_map_data	*map_data;

	i = 0;
	while (i < n)
	{
		map_data = ft_map_is_valid(files[i]);
		if (map_data)
			ft_process_map(files[i], map_data);
		else
			ft_print_error("Invalid map.", files[i]);
		i++;
	}
}

void	ft_read_stdin(void)
{
	t_map_data	*map_data;

	map_data = ft_map_is_valid(NULL);
	if (map_data)
		ft_process_map("Standard input", map_data);
	else
		ft_print_error("Invalid map.", "Standard input");
}

void	ft_process_map(char *file_path, t_map_data *map_data)
{
	char	**map;

	if (!ft_refill_map_data(map_data))
	{
		ft_print_error("Error reading map data.", file_path);
		return ;
	}
	map = ft_load_map(map_data);
	if (!map)
	{
		ft_print_error("Load map error.", file_path);
		ft_free_map_data(map_data);
		return ;
	}
	ft_bsq(map, map_data, file_path);
}

void	ft_bsq(char **map, t_map_data *map_data, char *file_path)
{
	ft_compute_max_square(map, map_data);
	if (map_data->max_square->size > 0)
	{
		ft_fill_square(map, map_data);
		ft_print_map(map, map_data);
	}
	else
		ft_print_error("No empty space to place a square.", file_path);
	ft_free_map(map, map_data->rows);
	ft_free_map_data(map_data);
}
