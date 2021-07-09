/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 22:26:11 by dju               #+#    #+#             */
/*   Updated: 2020/11/03 10:38:20 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		l;
	int		r;
	int		i;

	if (!s1 || !set)
		return (NULL);
	l = 0;
	r = ft_strlen(s1);
	while (l < r && check(s1[l], set))
		l++;
	while (l < r && check(s1[r - 1], set))
		r--;
	ret = malloc(sizeof(char) * (r - l + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (l < r)
		ret[i++] = s1[l++];
	ret[i] = 0;
	return (ret);
}
