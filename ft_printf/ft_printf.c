/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 02:17:59 by dju               #+#    #+#             */
/*   Updated: 2021/03/29 17:59:00 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	va;
	t_flag	f;

	ret = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
			ret += print_arg(&format, &va, &f);
		else
			ret += write(1, format++, 1);
	}
	va_end(va);
	return (ret);
}
