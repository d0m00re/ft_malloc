/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_memory_spec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:59:51 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/13 17:09:40 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

static void	show_basic_type(int type)
{
	ft_putstr("Nb block : ");
	ft_putnbr(g_mem_manage->memory_info[type].nb_block);
	ft_putstr("\n\tNb_octet : ");
	ft_putnbr(g_mem_manage->memory_info[type].nb_octet);
	ft_putstr("\n");
}

void		show_memory_spec(void)
{
	ft_putstr("TINY:\n\t");
	show_basic_type(TINY);
	ft_putstr("MEDIUM:\n\t");
	show_basic_type(MEDIUM);
}
