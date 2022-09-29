/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:26:24 by mbjaghou          #+#    #+#             */
/*   Updated: 2022/09/28 13:16:38 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	if (!t)
		return (0);
	while (*t != (unsigned char)c && *t)
		t++;
	if (*t == (unsigned char)c)
	{
		return ((char *)t);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	l1;
	size_t	l2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = (char *)malloc(l1 + l2 + 1);
	if (result != NULL)
	{
		ft_memcpy(result, s1, l1);
		ft_memcpy(result + l1, s2, l2 + 1);
	}
	free(s1);
	return (result);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*lol1;
	unsigned char	*lol2;
	int				i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	lol1 = (unsigned char *)src;
	lol2 = (unsigned char *)dst;
	while (n > 0)
	{
		lol2[i] = lol1[i];
		n--;
		i++;
	}
	return (dst);
}
