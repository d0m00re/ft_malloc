/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_search_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:29:29 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/13 17:08:08 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

/*
** ==============
** -- Research block with ptr
** =============
*/

/*
** found id of elemnts with data = ptr
** found position of ptr in structure
** for tiny or large
*/

int				found_id_mem_area_in_basic(void *ptr,\
		t_memory *block_ptr, int type)
{
	int			absolute_pos;

	absolute_pos = (int)(ptr - block_ptr->data);
	if (absolute_pos % g_mem_manage->memory_info[type].nb_octet)
		return (-1);
	return (absolute_pos / g_mem_manage->memory_info[type].nb_octet);
}

/*
** found memory area who contain addr (TINY - LARGE)
** [0, SIZE_BLOCK[
** ret : area who contain ptr
*/

t_memory		*found_mem_area_in_basic(void *ptr, int type)
{
	t_memory	*mem;

	if (!(mem = g_mem_manage->memory_chunk[type]))
		return (0);
	while (mem && mem->data != ptr)
	{
		if (mem->data <= ptr && ptr < mem->data \
		+ g_mem_manage->memory_info[type].total_octet)
			return (mem);
		mem = mem->link.next;
	}
	return (mem);
}

/*
** trouver l'element t_memory ayant data == ptr
** return : addr or null if error
*/

t_memory		*found_mem_area_in_large(void *ptr)
{
	t_memory	*mem_last;
	t_memory	*mem;

	if (!(mem = g_mem_manage->memory_chunk[LARGE]))
		return (0);
	if (mem->data == ptr)
		return (mem);
	while (mem && mem->data != ptr)
	{
		mem_last = mem;
		mem = mem->link.next;
	}
	if (!mem)
		return (0);
	return (mem_last);
}

/*
** return exact elememnt in t_memory large
*/

t_memory		*found_mem_area_in_large2(void *ptr)
{
	t_memory	*mem;

	mem = found_mem_area_in_large(ptr);
	if (mem && mem->link.next)
		mem = mem->link.next;
	return (mem);
}
