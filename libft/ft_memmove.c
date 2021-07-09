/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:41:01 by dju               #+#    #+#             */
/*   Updated: 2020/10/02 17:57:22 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	register size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i + 3 < len)
	{
		if (dst < src)
			*(int *)(dst + i) = *(int *)(src + i);
		else
			*(int *)(dst + len - 4 - i) = *(int *)(src + len - 4 - i);
		i = i + 4;
	}
	while (i < len)
	{
		if (dst < src)
			*(char *)(dst + i) = *(char *)(src + i);
		else
			*(char *)(dst + len - 1 - i) = *(char *)(src + len - 1 - i);
		i = i + 1;
	}
	return (dst);
}
