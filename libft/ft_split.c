/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:38:51 by dju               #+#    #+#             */
/*   Updated: 2020/11/03 10:38:37 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sdup(char const *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		cnt;

	if (!s)
		return (NULL);
	i = 0;
	cnt = (!s[0] || s[0] == c ? 0 : 1);
	while (s[i] && s[++i])
		if (s[i - 1] == c && s[i] != c)
			cnt++;
	res = malloc(sizeof(char*) * (cnt + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (*s && *s != c)
		res[i++] = sdup(s, c);
	while (*s && *++s)
		if (*(s - 1) == c && *s != c)
			res[i++] = sdup(s, c);
	res[i] = NULL;
	return (res);
}
