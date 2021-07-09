/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:31:49 by dju               #+#    #+#             */
/*   Updated: 2020/11/03 10:38:49 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	char	stack[40];
	int		sti;
	int		i;
	int		neg;

	neg = n < 0;
	sti = 0;
	if (n == 0)
		stack[++sti] = '0';
	while (n != 0)
	{
		stack[++sti] = (n < 0 ? -(n % 10) : n % 10) + '0';
		n /= 10;
	}
	if (neg)
		stack[++sti] = '-';
	if (!(res = malloc(sizeof(char) * (sti + (n < 0 ? 1 : 0) + 1))))
		return (NULL);
	i = 0;
	while (sti > 0)
		res[i++] = stack[sti--];
	res[i] = 0;
	return (res);
}
