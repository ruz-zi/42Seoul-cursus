/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 08:28:29 by dju               #+#    #+#             */
/*   Updated: 2021/01/25 09:44:55 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!(ret = malloc(len + 1)))
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
