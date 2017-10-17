/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_nb_octet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 18:58:21 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/17 15:44:26 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

static unsigned int	memory_basic_size_zone(int type, t_memory *mem)
{
	unsigned int	c;
	unsigned int	nb;

	nb = 0;
	c = 0;
	while (c < g_mem_manage->memory_info[type].nb_block)
	{
		nb += mem->mem_status[c];
		c++;
	}
	return (nb);
}

static void			show_reverse_check_area(int type,\
		int *nb_octet, t_memory *mem)
{
	int				nb;
	int				total_octet;

	if (mem->link.next)
		show_reverse_check_area(type, nb_octet, mem->link.next);
	if (type != LARGE)
	{
		nb = memory_basic_size_zone(type, mem);
		total_octet = g_mem_manage->memory_info[type].total_octet;
	}
	else
	{
		nb = mem->mem_status[0];
		total_octet = nb;
	}
	*nb_octet += nb;
}

static void			show_type_area(int type, int *nb_octet)
{
	t_memory		*mem;

	mem = g_mem_manage->memory_chunk[type];
	if (mem)
		show_reverse_check_area(type, nb_octet, mem);
}

unsigned int		calcul_nb_octet(void)
{
	int				nb_octet;

	nb_octet = 0;
	show_type_area(TINY, &nb_octet);
	show_type_area(MEDIUM, &nb_octet);
	show_type_area(LARGE, &nb_octet);
	return (nb_octet);
}
