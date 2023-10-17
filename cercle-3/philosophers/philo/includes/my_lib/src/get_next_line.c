/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:13:21 by anshimiy          #+#    #+#             */
/*   Updated: 2022/10/28 17:31:47 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

/*
	GET_NEXT_LINE
	-------------
	The function returns the next line from the [fd] with its respective '\n',
	or the last line of the file. It returns null if there's nothing to read
	or if an error occurs.
	AUXILIARY FUNCTIONS
	-------------------
	READ_FILE
	---------
	This function copies BUFFER_SIZE bytes from the string [buffer] to the
	static variable [stash] until a newline is found or the end of file is
	reached.
	GET_LINE
	--------
	If a newline is found in the cumulative buffer [stash], the contents until
	'\n' are copied to line and the rest is stored again in [stash]. If no
	newline is found, the whole content of [stash] is copied to line and [stash]
	points to NULL.
*/

void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*get_line(char **line, char **stash)
{
	char	*stash_temp;
	int		buff_nl_index;

	buff_nl_index = 0;
	stash_temp = *stash;
	while ((*stash)[buff_nl_index] != '\n' && (*stash)[buff_nl_index] != '\0')
		buff_nl_index++;
	if (ft_strchr(*stash, '\n'))
	{
		*line = ft_substr(*stash, 0, buff_nl_index + 1);
		*stash = ft_strdup(*stash + buff_nl_index + 1);
	}
	else
	{
		*line = ft_strdup(stash_temp);
		*stash = NULL;
	}
	free_ptr(stash_temp);
	return (*line);
}

int	read_file(int fd, char **buffer, char **stash, char **line)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(*stash, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temp = *stash;
		*stash = ft_strjoin(*stash, *buffer);
		free_ptr(temp);
	}
	free_ptr(*buffer);
	get_line(line, stash);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!stash)
		stash = ft_strdup("");
	if (read_file(fd, &buffer, &stash, &line) == 0 && *line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}
