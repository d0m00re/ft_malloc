/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 21:34:44 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/17 15:58:18 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

/*
** taille de chaque zone de tiny et de medium
*/

static unsigned int		memory_basic_size_zone(int type, t_memory *mem)
{
	unsigned int		c;
	unsigned int		nb;

	nb = 0;
	c = 0;
	while (c < g_mem_manage->memory_info[type].nb_block)
	{
		nb += mem->mem_status[c];
		c++;
	}
	return (nb);
}

static void				show_reverse_type_area(int type,\
		int *nb_octet, t_memory *mem)
{
	int					nb;
	int					total_octet;

	if (mem->link.next)
		show_reverse_type_area(type, nb_octet, mem->link.next);
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
	ft_putstr("0x");
	ft_putnbr_base((int)(mem->data), 16);
	ft_putstr(" - 0x");
	ft_putnbr_base((int)(mem->data + total_octet), 16);
	ft_putstr(" : ");
	ft_putnbr_base(nb, 10);
	ft_putchar('\n');
	*nb_octet += nb;
}

static void				show_type_area(int type, int *nb_octet, char *name)
{
	t_memory			*mem;

	ft_putstr(name);
	ft_putnbr_base((int)(&(g_mem_manage[type])), 16);
	ft_putchar('\n');
	mem = g_mem_manage->memory_chunk[type];
	if (mem)
		show_reverse_type_area(type, nb_octet, mem);
}

void					show_alloc_mem(void)
{
	int					nb_octet;

	nb_octet = 0;
	if (!g_mem_manage)
	{
		ft_putstr("show_alloc_mem : nothing to display.\n");
		return ;
	}
	if (g_mem_manage->memory_chunk[TINY])
		show_type_area(TINY, &nb_octet, "TINY: 0x");
	if (g_mem_manage->memory_chunk[MEDIUM])
		show_type_area(MEDIUM, &nb_octet, "MEDIUM: 0x");
	if (g_mem_manage->memory_chunk[LARGE])
		show_type_area(LARGE, &nb_octet, "LARGE: 0x");
	ft_putstr("Total : ");
	ft_putnbr(nb_octet);
	ft_putchar('\n');
}
