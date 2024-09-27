/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_to_buff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gruta <gruta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:17:13 by gruta             #+#    #+#             */
/*   Updated: 2024/09/11 23:23:09 by gruta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_expand_buffer(char *old_buffer, int total_size, int *size)
{
	char	*new_buffer;

	*size *= 2;
	new_buffer = malloc(*size);
	if (!new_buffer)
		return (NULL);
	ft_buff_cpy(new_buffer, old_buffer, total_size);
	free(old_buffer);
	return (new_buffer);
}

int	ft_read_data(int fd, char **file_content, int *total_size)
{
	char	buffer[ULIMITS];
	int		bytes_read;
	int		allocated_size;

	allocated_size = ULIMITS;
	while (1)
	{
		bytes_read = read(fd, buffer, ULIMITS);
		if (bytes_read <= 0)
			break ;
		if (*total_size + bytes_read > allocated_size)
		{
			*file_content = ft_expand_buffer(*file_content,
					*total_size, &allocated_size);
			if (!(*file_content))
				return (-1);
		}
		ft_buff_cpy(*file_content + *total_size, buffer, bytes_read);
		*total_size += bytes_read;
	}
	return (bytes_read);
}

void	*ft_return(char	*file_content)
{
	free(file_content);
	return (NULL);
}

char	*ft_read_file_content(int fd, int *total_size)
{
	char	*file_content;
	char	*final_content;

	file_content = malloc(ULIMITS);
	if (!file_content)
		return (NULL);
	if (ft_read_data(fd, &file_content, total_size) < 0)
		return (ft_return(file_content));
	final_content = malloc(*total_size);
	if (!final_content)
		return (ft_return(file_content));
	ft_buff_cpy(final_content, file_content, *total_size);
	free(file_content);
	return (final_content);
}

char	*ft_read_input(char *file_path, int *file_size)
{
	int		fd;
	char	*file_content;

	*file_size = 0;
	if (!file_path)
		fd = 0;
	else
		fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = ft_read_file_content(fd, file_size);
	close(fd);
	return (file_content);
}
