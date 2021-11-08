/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:14:00 by prossi            #+#    #+#             */
/*   Updated: 2021/11/08 14:56:19 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_print
{
	va_list args;
	int		count;
}	t_print;

void	ifchar(t_print *arg_count);
void	ifstring(t_print *arg_count);
void	ifpointer(t_print *arg_count);
void	ifhex(t_print *arg_count);
void	ifint(t_print *arg_count);
void	ifunsignedint(t_print *arg_count);
int		ft_printf(const char *str, ...);

#endif
