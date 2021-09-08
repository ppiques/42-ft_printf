/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:30:44 by ppiques           #+#    #+#             */
/*   Updated: 2021/07/04 12:51:23 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_percent(t_flags *flags)
{
	if (flags->left == 0)
	{
		if (flags->pad == 0)
			ft_printspace(flags->width - 1, flags);
		if (flags->pad == 1)
			ft_printzero(flags->width - 1, flags);
		ft_putchar('%', flags);
	}
	else
	{
		ft_putchar('%', flags);
		ft_printspace(flags->width - 1, flags);
	}
}
