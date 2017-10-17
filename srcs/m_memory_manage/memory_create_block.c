/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_create_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:36:39 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:16:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

t_memory		*memory_create_block(unsigned int nb_block,\
		unsigned int nb_octet)
{
	t_memory	*memory;

	memory = (t_memory *)(alloc_mem(sizeof(t_memory)));
	memory->data = alloc_mem(nb_block * nb_octet);
	memory->mem_status = (int *)(alloc_mem(sizeof(int) * nb_block));
	init_int_tab(memory->mem_status, nb_block);
	memory->link.next = 0;
	memory->link.last = 0;
	return (memory);
}

t_memory		*memory_create_tiny_block(void)
{
	return (memory_create_block(TINY_NB_BLOCK, TINY_NB_OCTET_BY_BLOCK));
}

t_memory		*memory_create_medium_block(void)
{
	return (memory_create_block(MEDIUM_NB_BLOCK, MEDIUM_NB_OCTET_BY_BLOCK));
}

t_memory		*memory_create_large_block(unsigned int nb_octet)
{
	t_memory	*mem;

	mem = memory_create_block(1, nb_octet);
	mem->mem_status[0] = nb_octet;
	return (mem);
}

t_memory		*memory_create_type_block(int type, unsigned int nb_octet)
{
	if (type == TINY)
		return (memory_create_tiny_block());
	else if (type == MEDIUM)
		return (memory_create_medium_block());
	else if (type == LARGE)
		return (memory_create_large_block(nb_octet));
	return (0);
}
