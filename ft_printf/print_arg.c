/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:51:04 by dju               #+#    #+#             */
/*   Updated: 2021/03/29 19:12:41 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isflag(int x)
{
	if (x == '-')
		return (F_ALIGN);
	else if (x == '+')
		return (F_SIGN);
	else if (x == '0')
		return (F_ZERO);
	else if (x == '#')
		return (F_HEXDEC);
	else if (x == ' ')
		return (F_SPACE);
	return (0);
}

static int	check_flag(const char **s, va_list *va, t_flag *f)
{
	while (isflag(*(++(*s))))
		f->flag |= isflag(**s);
	if (ft_isdigit(**s))
		while (ft_isdigit(**s))
			f->width = f->width * 10 + (*(*s)++ & 15);
	else if (**s == '*' && (*s)++)
		f->width = va_arg(*va, unsigned);
	if (f->width < 0)
	{
		f->width = -f->width;
		f->flag |= F_ALIGN;
	}
	if (**s == '.' && (*s)++)
	{
		f->flag |= F_PREC;
		if (ft_isdigit(**s))
			while (ft_isdigit(**s))
				f->prec = f->prec * 10 + (*(*s)++ & 15);
		else if (**s == '*' && (*s)++)
			f->prec = va_arg(*va, unsigned);
		if (f->prec < 0)
			f->flag &= ~F_PREC;
	}
	return (**s && ft_strchr("cspndiuxXh%", **s) ? *(*s)++ : -1);
}

static int	error_flag(t_flag *f)
{
	t_flag	tmp;
	int		ret;

	ft_memset(&tmp, 0, sizeof(t_flag));
	ret = write(1, "%", 1);
	if (f->flag & F_HEXDEC)
		ret += write(1, "#", 1);
	if (f->flag & F_SIGN)
		ret += write(1, "+", 1);
	if (f->flag & F_ALIGN)
		ret += write(1, "-", 1);
	if (f->width > 0)
		ret += print_sint(f->width, &tmp);
	if (f->flag & F_PREC)
	{
		ret += write(1, ".", 1);
		if (f->prec > 0)
			ret += print_sint(f->prec, &tmp);
	}
	return (ret);
}

static int	print_short(char specifier, va_list *va, t_flag *f)
{
	if (specifier == 'd' || specifier == 'i')
		return (print_sint((short)va_arg(*va, int), f));
	else if (specifier == 'u')
		return (print_uint((short)va_arg(*va, unsigned), f, B_DEC));
	else if (specifier == 'x')
		return (print_uint((short)va_arg(*va, unsigned), f, B_LHEX));
	else if (specifier == 'X')
		return (print_uint((short)va_arg(*va, unsigned), f, B_UHEX));
	return (0);
}

int			print_arg(const char **s, va_list *va, t_flag *f)
{
	int specifier;

	ft_memset(f, 0, sizeof(t_flag));
	if ((specifier = check_flag(s, va, f)) < 0)
		return (error_flag(f));
	if (specifier == 'c')
		return (print_char(va_arg(*va, int), f));
	else if (specifier == 's')
		return (print_str(va_arg(*va, char*), f));
	else if (specifier == 'd' || specifier == 'i')
		return (print_sint(va_arg(*va, int), f));
	else if (specifier == 'u')
		return (print_uint(va_arg(*va, unsigned), f, B_DEC));
	else if (specifier == 'x')
		return (print_uint(va_arg(*va, unsigned), f, B_LHEX));
	else if (specifier == 'X')
		return (print_uint(va_arg(*va, unsigned), f, B_UHEX));
	else if (specifier == '%')
		return (print_char('%', f));
	else if (specifier == 'p')
		return (print_addr(va_arg(*va, unsigned long long), f));
	else if (specifier == 'h' && ft_strchr("ndiuxX", **s) && (*s)++)
		return (print_short(*(*s - 1), va, f));
	return (0);
}
