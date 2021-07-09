/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:57:33 by dju               #+#    #+#             */
/*   Updated: 2020/10/03 00:22:27 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	register size_t	i;

	i = 0;
	while (i < len)
	{
		if (*(unsigned char*)(b1 + i) != *(unsigned char*)(b2 + i))
			return (*(unsigned char*)(b1 + i) - *(unsigned char*)(b2 + i));
		i++;
	}
	return (0);
}
