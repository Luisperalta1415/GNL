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
	static char	moñeco;
	int	bytesread = read(fd, BUFFER_SIZE, &moñeco);
	
	if(bytesread < 1 && (!moñeco))
		return(NULL);
	linea = malloc (sizeof char * BUFFER_SIZE + 2);
	ft_substr()
	
}

int	read_to_buffer(int fd, char **buffer)
{}

char	*extract_line(char **buffer)
{}

void	update_buffer(char **buffer)
{}

void	free_buffer(char **buffer)
{}
