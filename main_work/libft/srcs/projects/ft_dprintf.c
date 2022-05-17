/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:15:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/04/10 08:42:49 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_print_parse_fd(va_list ap, char fc, int fd)
{
	int	count;

	count = 0;
	if (fc == 's')
		count += ft_int_putstr_fd(va_arg(ap, char *), fd);
	else if (fc == 'c')
		count += ft_int_putchar_fd(va_arg(ap, int), fd);
	else if (fc == 'd' || fc == 'i')
		count += ft_int_putnbr_fd(va_arg(ap, int), fd);
	else if (fc == 'u')
		count += ft_int_putnbr_base_fd(va_arg(ap, unsigned int), BASEDEC, fd);
	else if (fc == 'x')
		count += ft_int_putnbr_base_fd(va_arg(ap, unsigned int), LOWERHEX, fd);
	else if (fc == 'X')
		count += ft_int_putnbr_base_fd(va_arg(ap, unsigned int), UPPERHEX, fd);
	else if (fc == 'p')
		count += ft_int_putptr_fd((unsigned long long)va_arg(ap, void *), fd);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;
	size_t	a;

	count = 0;
	a = 0;
	va_start(ap, format);
	while (format[a])
	{
		if (format[a] == '%')
		{
			a++;
			if (format[a] == '%')
				count += ft_int_putchar_fd(format[a], fd);
			else if (ft_ischarset(format[a], PRINTFCSET))
				count += ft_print_parse_fd(ap, format[a], fd);
			else if (!format[a])
				break ;
		}
		else
			count += ft_int_putchar_fd(format[a], fd);
		a++;
	}
	va_end(ap);
	return (count);
}
