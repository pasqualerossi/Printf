/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:14:00 by prossi            #+#    #+#             */
/*   Updated: 2021/11/10 13:17:09 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

void	ifchar(t_print *arg_count);
void	ifstring(t_print *arg_count);
void	ifpointer(t_print *arg_count);
void	ifhex(t_print *arg_count, char c);
void	ifint(t_print *arg_count);
void	ifunsignedint(t_print *arg_count);
int		ft_printf(const char *str, ...);

#endif
