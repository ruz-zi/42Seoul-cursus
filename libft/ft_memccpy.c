/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:32:02 by dju               #+#    #+#             */
/*   Updated: 2020/10/03 12:04:09 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t l)
{
	register size_t	i;

	i = 0;
	while (i < l)
	{
		if ((*(char *)(d + i) = *(char *)(s + i)) == (char)c)
			return (d + i + 1);
		i = i + 1;
	}
	return (NULL);
}
