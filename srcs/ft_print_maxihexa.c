/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_maxihexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:32:27 by ppiques           #+#    #+#             */
/*   Updated: 2021/07/09 16:22:09 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_maxihexa(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left = 1;
	}
	if (flags->prec < 0)
	{
		flags->prec = 0;
		flags->dot = 0;
	}
	if (flags->left == 0)
		print_maxihexa_right(flags);
	else if (flags->left == 1)
		print_maxihexa_left(flags);
}

void	print_maxihexa_padding(int i, t_flags *flags)
{
	if (i == 0 && flags->width < flags->prec && flags->prec < flags->len)
		ft_printspace(flags->width - flags->len, flags);
	if (i == 0 && flags->prec == 0 && flags->dot == 1)
		ft_printspace(flags->width, flags);
	if (i == 0 && flags->prec > 0 && flags->dot == 1
		&& (flags->prec - flags->len <= 0))
		ft_printspace(flags->width - flags->len, flags);
	if (flags->dot == 0)
		ft_printzero(flags->width - flags->len, flags);
	if (flags->width > flags->prec && flags->dot == 1
		&& flags->prec > flags->len)
		ft_printspace(flags->width - flags->prec, flags);
	if (flags->dot == 1 && i != 0 && (flags->prec - flags->len <= 0))
		ft_printspace(flags->width - flags->len, flags);
	if (flags->prec - flags->len > 0 && flags->left == 0)
		ft_printzero(flags->prec - flags->len, flags);
}

void	print_maxihexa_right(t_flags *flags)
{
	int	i;

	i = va_arg(flags->args, unsigned long);
	flags->len = ft_lnbr_len(i, "0123456789ABCDEF");
	if (i < 0)
		flags->len = flags->len / 2;
	if (flags->pad == 1)
		print_maxihexa_padding(i, flags);
	else if (flags->prec >= flags->width && flags->prec > flags->len)
		ft_printzero(flags->prec - flags->len, flags);
	else if (flags->width > flags->prec && flags->prec > flags->len)
	{
		ft_printspace(flags->width - flags->prec, flags);
		ft_printzero(flags->prec - flags->len, flags);
	}
	else if (flags->width > flags->len)
	{
		ft_printspace(flags->width - flags->len, flags);
		if (flags->dot == 1 && flags->prec == 0 && i == 0)
			ft_printspace(flags->dot, flags);
	}
	else if (flags->width >= 1 && i == 0 && flags->prec == 0 && flags->dot == 1)
		ft_printspace(flags->len, flags);
	ft_put_lnbr_base(i, "0123456789ABCDEF", flags);
}

void	print_maxihexa_left(t_flags *flags)
{
	int	i;

	i = va_arg(flags->args, unsigned long);
	flags->len = ft_lnbr_len(i, "0123456789ABCDEF");
	if (i < 0)
		flags->len = flags->len / 2;
	if (flags->prec > flags->len)
		ft_printzero(flags->prec - flags->len, flags);
	ft_put_lnbr_base(i, "0123456789ABCDEF", flags);
	if (flags->pad == 1)
		print_maxihexa_padding(i, flags);
	else if (flags->width >= flags->prec && flags->prec > flags->len)
		ft_printspace(flags->width - flags->prec, flags);
	else if (flags->width > flags->len && flags->width > flags->prec)
	{
		ft_printspace(flags->width - flags->len, flags);
		if (flags->dot == 1 && flags->prec == 0 && i == 0)
			ft_printspace(flags->dot, flags);
	}
	else if (flags->width >= 1 && i == 0 && flags->prec == 0 && flags->dot == 1)
		ft_printspace(flags->len, flags);
}
