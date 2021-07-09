/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:39:01 by ruz               #+#    #+#             */
/*   Updated: 2020/11/04 18:26:17 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;
	size_t i;

	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (srclen + size);
	size -= dstlen + 1;
	i = 0;
	while (*dst)
		dst++;
	while (i < size && *src)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = 0;
	return (dstlen + srclen);
}
