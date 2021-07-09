/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 08:28:29 by dju               #+#    #+#             */
/*   Updated: 2021/05/26 17:43:10 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	register size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	register char	*p;

	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	p = ret;
	while (s1 && *s1)
		*p++ = *s1++;
	while (s2 && *s2)
		*p++ = *s2++;
	*p = 0;
	return (ret);
}

char	*ft_strdup(const char *c)
{
	register size_t	i;
	size_t			len;
	char			*ret;

	len = ft_strlen(c);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(ret + i) = *(c + i);
		i = i + 1;
	}
	*(ret + i) = 0;
	return (ret);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
