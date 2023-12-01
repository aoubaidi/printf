/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:20:30 by laoubaid          #+#    #+#             */
/*   Updated: 2023/11/30 11:01:16 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args, int *count)
{
	int	p;

	p = va_arg(args, int);
	write(1, &p, 1);
	(*count)++;
}

void	print_string(va_list args, int *count)
{
	char	*p;

	p = va_arg(args, char *);
	if (!p)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	write(1, p, ft_strlen(p));
	(*count) += ft_strlen(p);
}

void	print_number(va_list args, int *count)
{
	int	p;

	p = va_arg(args, int);
	ft_putnbr(p, count);
}

void	print_unsigned_nb(va_list args, int *count)
{
	unsigned int	p;

	p = va_arg(args, unsigned int);
	ft_putnbr(p, count);
}

void	print_adr(va_list args, int *count)
{
	void			*p;
	unsigned long	adr;

	p = va_arg(args, void *);
	adr = (unsigned long)p;
	if (!adr)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*count) += 2;
	hexrec(adr, count, 0);
}
