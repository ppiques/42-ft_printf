/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:33:07 by ppiques           #+#    #+#             */
/*   Updated: 2021/07/09 16:13:46 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_char(t_flags *flags)
{
	char	c;

	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left = 1;
	}
	c = va_arg(flags->args, int);
	if (flags->left == 0)
	{
		ft_printspace(flags->width - 1, flags);
		ft_putchar(c, flags);
	}
	else
	{
		ft_putchar(c, flags);
		ft_printspace(flags->width - 1, flags);
	}
}
