/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:21:22 by laoubaid          #+#    #+#             */
/*   Updated: 2023/11/30 11:00:38 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long n, int *count)
{
	if (n < 0)
	{
		if (n == -2147483648)
			(*count) += write(1, "-2147483648", 11);
		else
		{
			n = n * -1;
			write(1, "-", 1);
			(*count)++;
			ft_putnbr(n, count);
		}
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else if (n == 0)
		(*count) += write(1, "0", 1);
	else
	{
		ft_putchar(n + '0');
		(*count)++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	hexrec(unsigned long p, int *count, int type)
{
	char	*base;

	base = NULL;
	if (!type)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (p < 16)
	{
		ft_putchar(base[p]);
		(*count)++;
	}
	else
	{
		hexrec(p / 16, count, type);
		ft_putchar(base[p % 16]);
		(*count)++;
	}
}
