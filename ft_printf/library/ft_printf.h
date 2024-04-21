/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:32:57 by ajovanov          #+#    #+#             */
/*   Updated: 2024/04/21 10:33:33 by ajovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_argument_c(char c);
int	ft_argument_s(char *string);
int	ft_printnbr(int n);
int	ft_print_p(unsigned long long num);
int	ft_arg_unsignedint(unsigned int n);
int	ft_prt_hex(unsigned int n, const char format);
#endif
