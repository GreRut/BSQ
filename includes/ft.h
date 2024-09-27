/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:46:43 by frzeznic          #+#    #+#             */
/*   Updated: 2024/09/11 23:15:55 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <fcntl.h> // open()
# include <unistd.h> // read(), write(), close()
# include <stdlib.h> // malloc(), free(), exit()
# define INT_MAX 2147483647
# define ULIMITS 1024

typedef struct s_max_square
{
	int	row;
	int	col;
	int	size;
}	t_max_square;

typedef struct s_characters
{
	char	c_empty;
	char	c_obstacle;
	char	c_full;
}	t_characters;

typedef struct s_map_data
{
	int				rows;
	int				columns;
	int				max_square_size;
	int				first_line_len;
	char			*buff_val;
	t_characters	*chars;
	t_max_square	*max_square;
}	t_map_data;

char			*ft_read_input(char *file_path, int *file_size);
int				ft_find_metadata_line(char *buff_val,
					int file_size, int *line_start, t_map_data *map_data);
t_map_data		*ft_map_is_valid(char *file_path);
int				ft_refill_map_data(t_map_data *map_data);
char			**ft_load_map(t_map_data *map_data);
void			ft_compute_max_square(char **map, t_map_data *map_data);
void			ft_free_map(char **map, int n);
void			ft_free_map_data(t_map_data *map_data);
void			ft_print_map(char **map, t_map_data *map_data);
void			ft_close_file(int fd, char *file_path);
void			ft_print_error(char *message, char *file_path);
int				ft_strlen(char *str);
void			ft_fill_square(char **map, t_map_data *map_data);
t_map_data		*ft_create_map_data(void);
t_characters	*ft_create_chars(char empty, char obstacle, char full);
void			*ft_free_and_return(char *buff_val, t_map_data *map_data);
void			ft_buff_cpy(char *dest, char *src, int len);

#endif
