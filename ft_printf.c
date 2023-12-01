/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:21:39 by laoubaid          #+#    #+#             */
/*   Updated: 2023/11/30 17:25:30 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(va_list args, int *count, int type)
{
	unsigned int	p;

	p = va_arg(args, unsigned int);
	hexrec(p, count, type);
}

void	handle_specifier(char c, va_list args, int *i, int *count)
{
	if (c == 'c')
		print_char(args, count);
	else if (c == 's')
		print_string(args, count);
	else if (c == 'd' || c == 'i')
		print_number(args, count);
	else if (c == 'u')
		print_unsigned_nb(args, count);
	else if (c == 'p')
		print_adr(args, count);
	else if (c == 'x')
		print_hexa(args, count, 0);
	else if (c == 'X')
		print_hexa(args, count, 1);
	else if (c == '%')
		(*count) += write(1, "%", 1);
	else
	{
		write(1, "%", 1);
		(*i)--;
		(*count)++;
	}
	(*i)++;
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			handle_specifier(str[i + 1], args, &i, &count);
			count -= 2;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (i + count);
}
