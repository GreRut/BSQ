/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:14:32 by gruta             #+#    #+#             */
/*   Updated: 2024/09/11 23:38:56 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_print_error(char *message, char *file_path)
{
	write(2, message, ft_strlen(message));
	write(2, " File path: ", 12);
	write(2, file_path, ft_strlen(file_path));
	write(2, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_close_file(int fd, char *file_path)
{
	if (close(fd) == -1)
		ft_print_error("File close error.", file_path);
}

void	*ft_free_and_return(char *buff_val, t_map_data *map_data)
{
	if (buff_val)
		free(buff_val);
	ft_free_map_data(map_data);
	return (NULL);
}

void	ft_buff_cpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len && *src)
	{
		*dest++ = *src++;
		i++;
	}
}
