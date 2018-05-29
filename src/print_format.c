/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:27:15 by minakim           #+#    #+#             */
/*   Updated: 2018/05/28 16:06:08 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_format(t_args *format, va_list arg, int count)
{
	char	*newstr;

	if (format->conversion == 's' || format->conversion == 'S')
		newstr = format_s(format, arg);
	else if (format->conversion == 'd' || format->conversion == 'D' ||
			format->conversion == 'i')
		newstr = format_d(format, arg);
	else if (format->conversion == 'p')
		newstr = format_p(format, arg);
	else if (format->conversion == 'o' || format->conversion == 'O')
		newstr = format_o(format, arg);
	else if (format->conversion == 'u' || format->conversion == 'U')
		newstr = format_u(format, arg);
	else if (format->conversion == 'x' || format->conversion == 'X')
		newstr = format_x(format, arg);
	else if (format->conversion == 'c' || format->conversion == 'C')
		newstr = format_c(format, arg);
	else if (format->conversion == '%')
		newstr = format_percent(format);
	else
		return (0);
	ft_putstr(newstr);
	count += ft_strlen(newstr);
	free(newstr);
	return (count);
}
