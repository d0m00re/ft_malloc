/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_area_zone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:54:03 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/13 19:38:52 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Found free space emplacement or create it
*/

#include "memory_manage.h"

/*
** purpose : found id of free zone
*/

static int		found_free_zone_id(int *mem_status, int size)
{
	int			c;

	c = 0;
	if (!mem_status)
		return (-1);
	while (c < size)
	{
		if (mem_status[c] == 0)
			return (c);
		c++;
	}
	return (-1);
}

/*
** trouver si il y a une place disponible dns le block actuel
*/

static void		*find_free_space_area(t_memory *memory,\
		t_memory_info info, int nb_octet)
{
	int			id;
	void		*addr;

	id = 0;
	if ((id = found_free_zone_id(memory->mem_status, info.nb_block)) < 0)
		return (0);
	memory->mem_status[id] = nb_octet;
	addr = &(memory->data[id * info.nb_octet]);
	return (addr);
}

/*
** partie de rechercher un espace libre dans tout les blocs de cette zone
** tiny : tiny1, ...., tinyn+1
*/

static void		*find_free_space_all_area(t_memory *memory,\
		t_memory_info info, int nb_octet)
{
	void		*addr;
	int			begin;

	addr = 0;
	begin = 1;
	while (begin || (!addr && memory))
	{
		begin = 0;
		addr = (t_memory *)(find_free_space_area(memory, info, nb_octet));
		memory = memory->link.next;
	}
	return (addr);
}

/*
** same like malloc
** create new memory or take existant space  and return it
*/

t_memory		*alloc_area_zone(unsigned int nb_octet)
{
	int			type;
	t_memory	*actual;
	t_memory	*addr;

	ft_putstr("begin alloc area zone\n");
	if ((type = memory_found_type(nb_octet)) < TINY)
		return (0);
	addr = 0;
	actual = g_mem_manage->memory_chunk[type];
	ft_putstr("Middle area zone alloc\n");
	if (type < LARGE)
	{
		ft_putstr("TINY OR MEDIUM ZONE ...\n");
		if ((addr = find_free_space_all_area(actual,\
		g_mem_manage->memory_info[type], nb_octet)))
			return (addr);
	}
	if (type == LARGE && !(g_mem_manage->memory_chunk[LARGE]))
	{
		g_mem_manage->memory_chunk[LARGE] =\
		memory_create_large_block(nb_octet);
		return (g_mem_manage->memory_chunk[LARGE]->data);
	}
	actual = memory_create_type_block(type, nb_octet);
	actual->mem_status[0] = nb_octet;
	actual->link.next = g_mem_manage->memory_chunk[type];
	g_mem_manage->memory_chunk[type] = actual;
	ft_putstr("ENDOUILLE\n");
	return (g_mem_manage->memory_chunk[type]->data);
}
