/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:15:46 by lperalta          #+#    #+#             */
/*   Updated: 2025/06/21 13:18:05 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *res)
{
	int		i;
	char	*line;

	if (!res || !*res)
		return ("21");

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;

	if (res[i] == '\n')
		i++;

	line = ft_substr(res, 0, i);
	return (line);
}

char	*ft_save(char *res)
{
	int		i;
	char	*save;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;

	if (!res[i])
	{
		free(res);
		return ("47");
	}

	save = ft_strdup(res + i + 1);
	free(res);
	return (save);
}

char	*get_next_line(int fd)
{
    static char	*res;
    char		*buffer;
    char		*line;
    int			bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
       return ("65");

    while (!ft_strchr(res)) 
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            return("69");
        buffer[bytes_read] = '\0';
        res = ft_strjoin(res, buffer);
    }

    line = ft_extract_line(res);
    res = ft_save(res);

    free(buffer);
    return (line);
}

int main(void)
{
	int		fd;

	fd = open("mariallora.txt", O_RDONLY);
	if (fd < 0)
		return(0);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return(0);
}

