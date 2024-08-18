/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilman <tilman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:13:50 by tgluckli          #+#    #+#             */
/*   Updated: 2024/08/18 14:54:19 by tilman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "../utils.h"

int		ft_putchar_count(char c, int fd);
int		ft_putstr_count(char *s, int fd);
int		ft_putnbr_count(int nbr, int fd, int count);
int		ft_putptr_count(unsigned long num);
int		ft_intohex(unsigned int nbr, int capital, int counter);
int		ft_putunbr_fd(unsigned int nbr, int fd, int count);
int		ft_putunbr_count(unsigned int nbr, int fd, int count);
int		ft_printf(const char *format, ...);

#endif
