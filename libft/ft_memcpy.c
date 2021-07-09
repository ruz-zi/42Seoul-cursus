/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:24:07 by dju               #+#    #+#             */
/*   Updated: 2020/10/03 00:52:43 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	register size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i + 7 < len)
	{
		*(unsigned long *)(dst + i) = *(unsigned long *)(src + i);
		i = i + 8;
	}
	while (i < len)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i = i + 1;
	}
	return (dst);
}
