/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:49 by rpaparon          #+#    #+#             */
/*   Updated: 2024/10/28 19:54:30 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	*ft_type(const char c, va_list value, int *counter)
{
	if (c == 'c')
	{
		*counter++;
		ft_putchar(va_arg(value, int));
	}
	else if (c  == 's')
		ft_putstr(va_arg(value, int), counter);
	else if (c == 'p')
		ft_printp();
}

int	*ft_printf(char const *str, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			counter += ft_putchar(str[0]);
		else
			ft_type(*str++, args, &counter);
		str++;
	}
	ve_end(args);
	return(counter);
}