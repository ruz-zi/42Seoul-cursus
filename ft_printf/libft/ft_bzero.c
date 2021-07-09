/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 22:15:06 by dju               #+#    #+#             */
/*   Updated: 2020/10/02 16:51:22 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	register size_t	i;

	i = 0;
	while (i + 3 < len)
	{
		*(unsigned int *)(b + i) = 0;
		i = i + 4;
	}
	while (i < len)
	{
		*(unsigned char *)(b + i) = 0;
		i = i + 1;
	}
}
