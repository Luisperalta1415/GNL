/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:16:05 by lperalta          #+#    #+#             */
/*   Updated: 2025/06/23 12:41:41 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return(len);
}

char	*ft_strchr(const char *s)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return(NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*dest;

	if (!s1 && !s2)
		return(NULL);
	if (!s1)
		return(ft_strdup(s2));
	if (!s2)
		return(ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *) malloc (len * sizeof (char *));
	if (!dest)
		return(NULL);
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = 0;
	dest -= len;
	return (dest);
}

char *ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;

	/*if (start > ft_strlen(s))
		return(ft_strdup("")); //se puede hacer con *dest = 0;?*/
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = (char *) malloc (len + 1 * sizeof (char *));
	if (!dest)
		return(NULL);

	dest[start + len] = 0;
	while (s[start + len] && len--)
		dest[len] = s[start + len];
	return(dest);  
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t 	len;

	len = ft_strlen(s) + 1;
	str = (char *) malloc (len * sizeof(char *));
	if (!str)
		return(NULL);
	str[len - 1] = 0;
	while (--len)
			str[len] = s[len];
	return(str);
}
// Por qué no puedo usar memchr, (bloques de memoria?)
