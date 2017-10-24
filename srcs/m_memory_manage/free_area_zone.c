/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_area_zone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:14:16 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/13 16:51:18 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

/*
** destroy and update linked list if successfull
*/

void			free_destroy_element_large(t_memory *elem)
{
	t_memory	*tmp;

	if (!elem)
		return ;
	if (!(elem->link.next))
	{
		memory_free_large(elem);
		g_mem_manage->memory_chunk[LARGE] = 0;
	}
	else
	{
		tmp = elem->link.next;
		elem->link.next = ((t_memory *)(elem->link.next))->link.next;
		memory_free_large(tmp);
	}
}

/*
** free les differentes zones
*/

void			free_area_zone(void *ptr)
{
	t_memory	*mem;
	int			pos;

	if (!ptr)
	{
		return ;
	}
	if ((mem = found_mem_area_in_large(ptr)))
	{
		free_destroy_element_large(mem);
	}
	else if ((mem = found_mem_area_in_basic(ptr, TINY)))
	{
		pos = found_id_mem_area_in_basic(ptr, mem, TINY);
		if (pos != -1)
			mem->mem_status[pos] = 0;
	}
	else if ((mem = found_mem_area_in_basic(ptr, MEDIUM)))
	{
		pos = found_id_mem_area_in_basic(ptr, mem, MEDIUM);
		if (pos != -1)
			mem->mem_status[pos] = 0;
	}
//	show_alloc_mem();
}
