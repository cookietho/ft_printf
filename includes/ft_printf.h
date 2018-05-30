/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:01:11 by minakim           #+#    #+#             */
/*   Updated: 2018/05/29 17:20:44 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include "../libft/libft.h"

typedef struct	s_args
{
	int								space;
	int								zero;
	int								minus;
	int								plus;
	int								hash;
	int								width;
	int								count;
	enum {null, h, hh, l, ll, j, z}	flag;
	int								precis_dot;
	int								precis;
	char							conversion;
}				t_args;

/*
**	initiation.c
*/

t_args			*initialization(void);
intmax_t		get_number(t_args *format, va_list arg);
uintmax_t		get_u_number(t_args *format, va_list arg);

/*
**	trim.c
*/

char			*cut_left(char *str, int n);
char			*cut_right(char *str, int n);
char			*to_left(char *str, int n, char c);
char			*to_right(char *str, int n, char c);

/*
**	check.c
*/

char			**check_flag(char **argstr, t_args *format);
char			**check_precision(char **argstr, t_args *format, va_list arg);
char			**check_width(char **argstr, t_args *format, va_list arg);
char			**check_extra(char **argstr, t_args *format);
char			**check_conversion(char **argstr, t_args *format);

/*
**	specifier1.c
*/

char			*format_big_s(t_args *format, va_list arg);
char			*format_s(t_args *format, va_list arg);
char			*format_d(t_args *format, va_list arg);
char			*format_p(t_args *format, va_list arg);

/*
**	specifier2.c
*/

char			*format_o(t_args *format, va_list arg);
char			*format_u(t_args *format, va_list arg);
char			*u_with_flag(t_args *format, char *ascii);
char			*format_x(t_args *format, va_list arg);

/*
**	specifier3.c
*/

int				format_c_2(t_args *format);
char			*format_c(t_args *format, va_list arg);
char			*format_percent(t_args *format);

/*
**	printf_format.c
*/

int				print_format(t_args *format, va_list arg, int count);

/*
**	ft_printf.c
*/

int				parsing(va_list arg, char **str, int count);
int				ft_printf(char *string, ...);

#endif
