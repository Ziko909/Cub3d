/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:30:45 by rel-hach          #+#    #+#             */
/*   Updated: 2022/10/09 00:51:58 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_get_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] && buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_remaining_part(char *old_buffer)
{
	int		i;
	int		j;
	int		l;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (old_buffer[i] && old_buffer[i] != '\n')
		i++;
	if (!old_buffer[i])
		return (free (old_buffer), NULL);
	if (old_buffer[i] == '\n')
		i++;
	l = i;
	while (old_buffer[i] != '\0')
		i++;
	new_buffer = (char *)malloc((i - l) + 1);
	if (!new_buffer)
		return (NULL);
	while (old_buffer[l])
		new_buffer[j++] = old_buffer[l++];
	new_buffer[j] = '\0';
	free (old_buffer);
	return (new_buffer);
}

char	*ft_read(int fd, char *buffer)
{
	char	*temp_str;
	int		read_bytes;
	int		BUFFER_SIZE = 1;

	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_check_newline(buffer))
	{
		temp_str = ft_calloc((BUFFER_SIZE + 1), sizeof(char ));
		read_bytes = read(fd, temp_str, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(temp_str);
			return (NULL);
		}
		if (read_bytes == 0)
		{
			free (temp_str);
			break ;
		}
		temp_str[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, temp_str);
		free (temp_str);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			BUFFER_SIZE;
	static char	*buffer;

	BUFFER_SIZE = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read (fd, buffer);
	line = ft_get_line (buffer);
	buffer = get_remaining_part (buffer);
	return (line);
}
