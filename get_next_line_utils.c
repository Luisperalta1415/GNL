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

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return(len);
}

char	*ft_strchr(char *str)
{
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
	{
		free(s1);
		return(ft_strdup(s1));
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *) malloc (len * sizeof (char));
	if (!dest)
		return(NULL);
	dest[len] = 0;
	while (s2[len--])
		dest[len] = s2[len];
	while (s1[len--])
		dest[len] = s1[len];
	free(s1);
	return (dest);
}

char *ft_substr(char *s, int start, int len)
{
	char	*dest;

	/*if (start > ft_strlen(s))
		return(ft_strdup("")); //se puede hacer con *dest = 0;?*/
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = (char *) malloc (len + 1 * (sizeof (char)));
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
	int 	len;

	len = ft_strlen(s);
	str = (char *) malloc (len * sizeof(char) + 1);
	if (!str)
		return(NULL);
	while (len--)
		str[len] = s[len];
	return(str);
}
// Por qué no puedo usar memchr, (bloques de memoria?)
