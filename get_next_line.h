/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:16:16 by lperalta          #+#    #+#             */
/*   Updated: 2025/06/21 13:27:02 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_extract_line(char *res);
char	*ft_save_remainder(char *res);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#endif
