/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 23:32:01 by blorin            #+#    #+#             */
/*   Updated: 2021/04/05 16:12:02 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		a;

	a = 0;
	if (s1 == NULL)
		i = ft_strlen(s2);
	else
		i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s1 && s1[a] != '\0')
		str[i++] = s1[a++];
	a = 0;
	while (s2 && s2[a] != '\0')
		str[i++] = s2[a++];
	str[i] = '\0';
	return (str);
}

void	ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

char	*ft_strdup_n(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src && src[i] != '\0' && src[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src && src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
