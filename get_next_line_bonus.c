/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donchoi <donchoi.student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:14:34 by donchoi           #+#    #+#             */
/*   Updated: 2022/03/16 14:34:34 by donchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*separate_line(char **backup)
{
	int		idx;
	char	*line;
	char	*old_backup;

	idx = 0;
	while ((*backup)[idx] != '\n')
		idx++;
	old_backup = *backup;
	line = ft_substr(old_backup, 0, idx + 1);
	*backup = ft_strdup(&(*backup)[idx + 1]);
	free(old_backup);
	return (line);
}

static int	read_file(int fd, char **buffer, char **backup)
{
	int		byte;
	char	*old_backup;

	byte = 1;
	while (!ft_strchr(*backup, '\n') && byte)
	{
		byte = read(fd, *buffer, BUFFER_SIZE);
		if (byte == -1)
			return (byte);
		(*buffer)[byte] = '\0';
		old_backup = *backup;
		*backup = ft_strjoin(old_backup, *buffer);
		free(old_backup);
	}
	return (byte);
}

static char	*get_line(int fd, char **buffer, char **backup)
{
	int		byte;
	char	*last_line;

	byte = read_file(fd, buffer, backup);
	if (!**backup || byte == -1)
	{
		free_ptr(backup);
		return (NULL);
	}
	if (ft_strchr(*backup, '\n'))
		return (separate_line(backup));
	last_line = ft_strdup(*backup);
	free_ptr(backup);
	return (last_line);
}

char	*get_next_line(int fd)
{
	static char	*backup[256];
	char		*buffer;
	char		*result;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	result = get_line(fd, &buffer, &backup[fd]);
	free(buffer);
	return (result);
}
