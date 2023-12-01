/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laoubaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:31:36 by laoubaid          #+#    #+#             */
/*   Updated: 2023/11/30 10:38:26 by laoubaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(int c);
void	ft_putnbr(long n, int *count);
int		ft_strlen(char *str);
void	hexrec(unsigned long p, int *count, int type);
void	print_char(va_list args, int *count);
void	print_string(va_list args, int *count);
void	print_number(va_list args, int *count);
void	print_unsigned_nb(va_list args, int *count);
void	print_adr(va_list args, int *count);
void	print_hexa(va_list args, int *count, int type);
void	handle_specifier(char c, va_list args, int *i, int *count);
int		ft_printf(const char *str, ...);

#endif
