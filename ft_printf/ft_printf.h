/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 02:12:30 by dju               #+#    #+#             */
/*   Updated: 2021/03/29 18:13:01 by dju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

# define F_ALIGN	1
# define F_SIGN		2
# define F_ZERO		4
# define F_HEXDEC	8
# define F_SPACE	16
# define F_PREC		32
# define F_ADDR		64

# define B_DEC		"0123456789"
# define B_LHEX		"0123456789abcdef"
# define B_UHEX		"0123456789ABCDEF"

typedef struct	s_flag
{
	int	flag;
	int	width;
	int	prec;
}				t_flag;

int				ft_printf(const char *format, ...);
int				print_arg(const char **s, va_list *va, t_flag *f);
int				print_char(char c, t_flag *f);
int				print_str(char *s, t_flag *f);
int				print_sint(signed long long n, t_flag *f);
int				print_uint(unsigned long long u, t_flag *f, char *base);
int				print_addr(unsigned long long p, t_flag *f);
int				print_pad(int width, char c);

#endif
