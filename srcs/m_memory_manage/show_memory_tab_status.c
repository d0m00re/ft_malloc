/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_memory_tab_status.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 15:39:05 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/17 16:00:59 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

/*
** show string data
*/

void				show_memory_tab_status(t_memory *mem, unsigned int type)
{
	unsigned int	c;
	unsigned int	nb_block;

	if (type == LARGE)
		nb_block = 1;
	else
		nb_block = g_mem_manage->memory_info[type].nb_block;
	c = 0;
	ft_putchar('[');
	while (c < nb_block)
	{
		ft_putnbr(mem->mem_status[c]);
		c++;
		if (c != nb_block)
			ft_putstr(", ");
	}
	ft_putstr("]\n");
}

void				show_all_memory_tab_status(unsigned int type)
{
	t_memory		*mem;
	int				c;

	c = 0;
	mem = g_mem_manage->memory_chunk[type];
	while (mem)
	{
		ft_putnbr(c);
		ft_putstr(" : ");
		show_memory_tab_status(mem, type);
		mem = mem->link.next;
		c++;
	}
}

/*
** show int data
*/

void				show_memory_data_status(t_memory *mem, unsigned int type)
{
	int				c;
	int				size;

	c = 0;
	if (type == LARGE)
		size = mem->mem_status[0];
	else
		size = g_mem_manage->memory_info[type].total_octet;
	while (c < size)
	{
		ft_putchar(*((char *)(&(mem->data[c]))));
		c++;
	}
}

void				show_all_memory_data_status(unsigned int type,\
		unsigned int depth)
{
	t_memory		*mem;
	unsigned int	c;

	c = 0;
	mem = g_mem_manage->memory_chunk[type];
	while (mem && c < depth)
	{
		ft_putnbr(c);
		ft_putstr(" : ");
		show_memory_data_status(mem, type);
		ft_putchar('\n');
		mem = mem->link.next;
		c++;
	}
}

void				memory_manage_reset(void)
{
	g_mem_manage = 0;
}
