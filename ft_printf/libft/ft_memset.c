/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 21:48:12 by dju               #+#    #+#             */
/*   Updated: 2020/10/03 01:47:33 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	register size_t			i;
	register unsigned long	u;

	i = 0;
	u = c & 255;
	u |= u << 8;
	u |= u << 16;
	u |= u << 32;
	while (i + 15 < len)
	{
		*(unsigned long *)(dst + i) = u;
		*(unsigned long *)(dst + i + 8) = u;
		i = i + 16;
	}
	while (i < len)
	{
		*(unsigned char *)(dst + i) = c;
		i = i + 1;
	}
	return (dst);
}
