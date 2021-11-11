/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex-pointer-string-character.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:08:22 by prossi            #+#    #+#             */
/*   Updated: 2021/11/11 13:30:59 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*numberlength(unsigned long number, int *length)
{
	char	*string;

	while (number >= 16)
	{
		number = number / 16;
		*length += 1;
	}
	string = (char *)malloc((*length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[*length] = '\0';
	return (string);
}

void	ifhex(t_print *arg_count, char character)
{
	unsigned int	number;
	int				length;
	char			*string;

	number = va_arg(arg_count->args, unsigned int);
	length = 1;
	string = numberlength(number, &length);
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (character == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (character == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}

void	ifpointer(t_print *arg_count)
{
	int				len;
	char			*str;
	unsigned long	num;

	num = va_arg(arg_count->args, unsigned long);
	len = 1;
	str = numberlength(num, &len);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	len--;
	while (len >= 0)
	{
		if (num % 16 <= 10)
			str[len] = '0' + (num % 16);
		else
			str[len] = 'W' + (num % 16);
		num = num / 16;
		len--;
		arg_count->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ifcharacter(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->counter++;
}

void	ifstring(t_print *arg_count)
{
	char	*string;
	int		length;

	string = va_arg(arg_count->args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		arg_count->counter += 6;
	}
	else
	{
		length = ft_strlen(string);
		ft_putstr_fd(string, 1);
		arg_count->counter += length;
	}
}
