/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 20:09:55 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:10:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

unsigned int		ft_strlen(char *str)
{
	int			c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void				ft_putnbr(int nb)
{
	unsigned int	nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > 9)
	{
		ft_putnbr(nbb / 10);
		ft_putnbr(nbb % 10);
	}
	else
	{
		ft_putchar(nbb + '0');
		nbb = 0;
	}
}

void				ft_putnbr_base(int nb, unsigned int base)
{
	unsigned int	nbb;

	nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb > base - 1)
	{
		ft_putnbr_base(nbb / base, base);
		ft_putnbr_base(nbb % base, base);
	}
	else
	{
		if (nbb < 10)
			ft_putchar(nbb + '0');
		else
			ft_putchar(nbb - 10 + 'A');
		nbb = 0;
	}
}
