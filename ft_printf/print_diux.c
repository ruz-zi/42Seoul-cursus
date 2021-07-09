/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:17:31 by dju               #+#    #+#             */
/*   Updated: 2021/03/29 18:15:55 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sint_len(signed long long n)
{
	int ret;

	if (!n)
		return (1);
	ret = 0;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static int	uint_len(unsigned long long u, int base)
{
	int ret;

	if (!u)
		return (1);
	ret = 0;
	while (u > 0)
	{
		u /= base;
		ret++;
	}
	return (ret);
}

static void	ft_putnbr_base(unsigned long long u, char *base)
{
	char	stack[40];
	int		sti;
	int		baselen;

	sti = 0;
	baselen = ft_strlen(base);
	if (!u)
		stack[++sti] = '0';
	while (u)
	{
		stack[++sti] = base[u % baselen];
		u /= baselen;
	}
	while (sti > 0)
		write(1, &stack[sti--], 1);
}

int			print_uint(unsigned long long u, t_flag *f, char *b)
{
	int	ret;

	ret = (f->flag & F_PREC) && !f->prec && !u ? 0 : uint_len(u, ft_strlen(b));
	f->width -= (f->prec > ret ? f->prec : ret);
	if ((f->flag & F_ADDR) || ((f->flag & F_HEXDEC) && u))
		f->width -= 2;
	if ((~f->flag & F_ALIGN) && ((~f->flag & F_ZERO) || (f->flag & F_PREC)))
		ret += print_pad(f->width, ' ');
	if ((f->flag & F_ADDR) || ((f->flag & F_HEXDEC) && u))
		ret += write(1, b[10] == 'a' ? "0x" : "0X", 2);
	if ((f->flag & F_ZERO) && (~f->flag & F_PREC))
		ret += print_pad(f->width, '0');
	if (f->flag & F_PREC)
		ret += print_pad(f->prec - ((f->flag & F_PREC)
		&& !f->prec && !u ? 0 : uint_len(u, ft_strlen(b))), '0');
	if ((~f->flag & F_PREC) || f->prec || u)
		ft_putnbr_base(u, b);
	if (f->flag & F_ALIGN)
		ret += print_pad(f->width, ' ');
	return (ret);
}

int			print_sint(signed long long n, t_flag *f)
{
	int	ret;

	ret = ((f->flag & F_PREC) && !f->prec && !n ? 0 : sint_len(n));
	f->width -= (f->prec > ret ? f->prec : ret);
	if (n < 0 || (f->flag & (F_SIGN | F_SPACE)))
		f->width -= 1;
	if ((~f->flag & F_ALIGN) && ((~f->flag & F_ZERO) || (f->flag & F_PREC)))
		ret += print_pad(f->width, ' ');
	if (n < 0)
		ret += write(1, "-", 1);
	else if (f->flag & (F_SIGN | F_SPACE))
		ret += write(1, f->flag & F_SIGN ? "+" : " ", 1);
	if ((f->flag & F_ZERO) && (~f->flag & F_PREC) && (~f->flag & F_ALIGN))
		ret += print_pad(f->width, '0');
	if (f->flag & F_PREC)
		ret += print_pad(f->prec - ((f->flag & F_PREC)
		&& !f->prec && !n ? 0 : sint_len(n)), '0');
	if ((~f->flag & F_PREC) || f->prec || n)
		ft_putnbr_base(n < 0 ? -n : n, B_DEC);
	if (f->flag & F_ALIGN)
		ret += print_pad(f->width, ' ');
	return (ret);
}
