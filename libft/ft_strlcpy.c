/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:02:51 by dju               #+#    #+#             */
/*   Updated: 2020/11/04 19:01:31 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	register size_t	i;
	size_t			src_len;

	if (!src)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (!dst || !dstsize)
		return (src_len);
	while (i + 1 < dstsize && i < src_len)
	{
		*(dst + i) = *(src + i);
		i = i + 1;
	}
	*(dst + i) = 0;
	return (src_len);
}
