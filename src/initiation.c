/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:21:54 by minakim           #+#    #+#             */
/*   Updated: 2018/05/29 17:23:57 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_args		*initialization(void)
{
	t_args	*format;

	format = (t_args*)malloc(sizeof(t_args));
	format->space = 0;
	format->zero = 0;
	format->minus = 0;
	format->plus = 0;
	format->hash = 0;
	format->width = 0;
	format->count = 0;
	format->precis_dot = 0;
	format->precis = 0;
	format->conversion = '\0';
	format->flag = 0;
	return (format);
}

intmax_t	get_number(t_args *format, va_list arg)
{
	intmax_t	digit;

	printf("get_number_conv : |%c|\n", format->conversion);
	printf("get_number_flag : |%d|\n", format->flag);
	if (format->conversion != 'D' && format->flag == 1)
	{
		digit = (short int)va_arg(arg, int);
		printf("digit is short int : |%jd|\n", digit);
	}
	else if (format->flag == 2)
	{
		digit = (char)va_arg(arg, int);
		printf("digit is char signed : |%jd|\n", digit);
	}
	else if (format->conversion == 'D' || format->flag == 3)
	{
		digit = va_arg(arg, long);
		printf("digit is long : |%jd|\n", digit);
	}
	else if (format->flag == 4)
	{
		digit = va_arg(arg, long long);
		printf("digit is long long : |%jd|\n", digit);
	}
	else if (format->flag == 5)
	{
		digit = va_arg(arg, intmax_t);
		printf("digit is intmax_t : |%jd|\n", digit);
	}
	else if (format->flag == 6)
	{
		digit = va_arg(arg, size_t);
		printf("digit is size_t : |%jd|\n", digit);
	}
	else
	{
		digit = (int)va_arg(arg, intmax_t);
		printf("digit is int : |%jd|\n", digit);
	}
		return (digit);
}

uintmax_t	get_u_number(t_args *format, va_list arg)
{
	uintmax_t	digit;

	if (format->flag == 1 && format->conversion != 'U' &&
			format->conversion != 'O')
		digit = (unsigned short)va_arg(arg, int);
	else if (format->flag == 2)
		digit = (unsigned char)va_arg(arg, int);
	else if (format->conversion == 'O' || format->conversion == 'U' ||
			format->flag == 3)
		digit = va_arg(arg, unsigned long);
	else if (format->flag == 4)
		digit = va_arg(arg, unsigned long long);
	else if (format->flag == 5)
		digit = va_arg(arg, uintmax_t);
	else if (format->flag == 6)
		digit = va_arg(arg, size_t);
	else
		digit = va_arg(arg, unsigned int);
	return (digit);
}
