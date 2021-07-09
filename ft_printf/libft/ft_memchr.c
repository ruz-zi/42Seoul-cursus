/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:53:23 by dju               #+#    #+#             */
/*   Updated: 2020/10/02 18:01:28 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	register size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(unsigned char*)(b + i) == (unsigned char)c)
			return ((void*)(b + i));
		i = i + 1;
	}
	return (NULL);
}
