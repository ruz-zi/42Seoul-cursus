/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:07:16 by dju               #+#    #+#             */
/*   Updated: 2020/11/02 19:39:59 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	register size_t	i;
	char			*r;

	i = 0;
	r = NULL;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			r = (char*)(s + i);
		i = i + 1;
	}
	if (*(s + i) == c)
		r = (char *)(s + i);
	return (r);
}
