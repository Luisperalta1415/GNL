/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:15:46 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/03 11:37:32 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *res)
{
	int		i;
	char	*line;

	if (!res || !*res)
		return (NULL);
	if (!ft_strchr(res) && res && *res)
	{
		line = ft_strdup(res);
		free(res);
		return (line);
	}
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	line = ft_substr(res, i);
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
		return (NULL);
	}
	save = ft_strdup(res + i + 1);
	free(res);
	if(save && save[0] == 0)
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buffer;
	char		*line;
	int			bytes_read;

	if ((BUFFER_SIZE <= 0) || (fd <= 0))
		return(NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(res))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer),NULL);
		buffer[bytes_read] = '\0';
		res = ft_strjoin(res, buffer);
	}
	line = ft_extract_line(res);
	res = ft_save(res);
	free (buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*prueba;
	int		i;

	i = 8;
	prueba = NULL;
	fd = open("mariallora.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	while (i--)
	{
		prueba = get_next_line(fd);
		printf("%s", prueba);
		if (!prueba)
			printf("\n");
		free(prueba);
	}
	close(fd);
	return (0);
}
