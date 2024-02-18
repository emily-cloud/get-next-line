/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:57:42 by hai               #+#    #+#             */
/*   Updated: 2024/02/18 15:58:26 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    static char     *left;

    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(buffer);
        free(left);
        buffer = NULL;
        left = NULL;
        return (NULL);
    }
    if (!buffer)
        return (NULL);
    line = read_line(fd, left, buffer);
    free(buffer);
    buffer = NULL;
    if(!line)
        return (NULL);
    left = set_line(line);
    return(line);
}

char    *read_line(int fd, char *left, char *buffer)
{
    int  bytes_read;
    char *temp;

    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(left);
            left = NULL;
            return (NULL);
        }    
        else if (bytes_read == 0)//read the whole file already
				break;
		buffer[bytes_read] = 0;
		if(!left)
		    left = ft_strdup("");
		temp = left;
		left = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (left);
 }

char *set_line(char *line)
{
    size_t i;
    char    *left;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    if (line[i] == '\0')
        return (NULL);
    left = ft_substr(line, i + 1, ft_strlen(line) - i -1);
    line[i + 1] = '\0';
    if (*left == '\0')
    {
        free(left);
        left = NULL;
     }
    return (left);
}
