/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 00:21:50 by dju               #+#    #+#             */
/*   Updated: 2020/10/02 22:46:37 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 0x20 || (c >= 0x09 && c <= 0x0d));
}

int			ft_atoi(const char *s)
{
	register size_t	i;
	long long		r;
	int				n;

	i = 0;
	r = 0;
	n = 0;
	while (ft_isspace(*(s + i)))
		i++;
	if (*(s + i) == '-' || *(s + i) == '+')
		if (*(s + i++) == '-')
			n = 1;
	while (*(s + i) >= '0' && *(s + i) <= '9')
	{
		if (r >= 922337203685477580 && *(s + i) >= 8)
			return (n ? 0 : -1);
		r = r * 10 + (*(s + i++) & 15);
	}
	return (n ? (int)-r : (int)r);
}
