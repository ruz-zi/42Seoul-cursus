/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:08:16 by dju               #+#    #+#             */
/*   Updated: 2021/03/29 18:04:12 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_len(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
		write(1, &s[i++], 1);
}

int			print_pad(int width, char c)
{
	int	ret;

	ret = 0;
	while (width-- > 0)
		ret += write(1, &c, 1);
	return (ret);
}

int			print_char(char c, t_flag *f)
{
	int ret;

	ret = 0;
	f->width--;
	if (~f->flag & F_ALIGN)
		ret += print_pad(f->width, f->flag & F_ZERO ? '0' : ' ');
	ret += write(1, &c, 1);
	if (f->flag & F_ALIGN)
		ret += print_pad(f->width, ' ');
	return (ret);
}

int			print_str(char *s, t_flag *f)
{
	int	ret;
	int	len;

	if (!s)
		s = "(null)";
	len = (int)ft_strlen(s);
	if (f->flag & F_PREC && len > f->prec)
		len = f->prec;
	ret = len;
	f->width -= len;
	if (~f->flag & F_ALIGN)
		ret += print_pad(f->width, f->flag & F_ZERO ? '0' : ' ');
	ft_putstr_len(s, len);
	if (f->flag & F_ALIGN)
		ret += print_pad(f->width, ' ');
	return (ret);
}

int			print_addr(unsigned long long p, t_flag *f)
{
	f->flag |= F_ADDR;
	return (print_uint(p, f, "0123456789abcdef"));
}
