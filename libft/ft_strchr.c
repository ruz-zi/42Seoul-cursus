/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:03:13 by dju               #+#    #+#             */
/*   Updated: 2020/10/03 00:28:04 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	register char	*p;

	p = (char *)s;
	while (*p)
		if (*p++ == c)
			return (p - 1l);
	if (*p == c)
		return (p);
	return (NULL);
}
