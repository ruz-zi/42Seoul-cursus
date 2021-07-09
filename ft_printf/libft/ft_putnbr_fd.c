/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:34:55 by dju               #+#    #+#             */
/*   Updated: 2020/11/02 20:11:21 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	st[12];
	int		sti;
	int		neg;

	neg = n < 0 ? 1 : 0;
	sti = 0;
	if (!n)
		st[++sti] = 48;
	while (n)
	{
		st[++sti] = (n < 0 ? -(n % 10) : n % 10) + 48;
		n /= 10;
	}
	if (neg)
		st[++sti] = '-';
	while (sti > 0)
		write(fd, &st[sti--], 1);
}