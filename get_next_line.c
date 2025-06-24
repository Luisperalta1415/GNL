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

char	*get_next_line(int fd)
{
	char		*get_next_line(int fd)
    static char	*res;
    char		*buffer;
    char		*line;
    int			bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
       return (NULL);

    while (!ft_strchr(res)) 
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            return(NULL);
        buffer[bytes_read] = '\0';
        res = ft_strjoin(residual, buffer);  // junta lo leído
    }

    line = ft_extract_line(res);               // saca hasta el '\n'
    res = ft_save_remainder(res);         // guarda lo que sobra

    free(buffer);
    return (line);
}

char	*ft_extract_line(char *res)
{
	int		i;
	char	*line;

	if (!res || !*res)
		return (NULL);

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;

	// Incluir el '\n' si está
	if (res[i] == '\n')
		i++;

	line = ft_substr(res, 0, i);
	return (line);
}

char	*ft_save_remainder(char *res)
{
	int		i;
	char	*remainder;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;

	if (!res[i])  // No hay '\n', liberar y devolver NULL
	{
		free(residual);
		return (NULL);
	}

	// Saltamos el '\n'
	remainder = ft_strdup(res + i + 1);
	free(res);
	return (remainder);
}


