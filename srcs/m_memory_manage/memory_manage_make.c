/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage_make.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:50:54 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/13 17:05:22 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

static void	init_memory_info(t_memory_info *memory_info)
{
	memory_info[TINY].type = TINY;
	memory_info[TINY].nb_block = TINY_NB_BLOCK;
	memory_info[TINY].nb_octet = TINY_NB_OCTET_BY_BLOCK;
	memory_info[TINY].total_octet = TINY_SIZE_TOTAL;
	memory_info[MEDIUM].type = MEDIUM;
	memory_info[MEDIUM].nb_block = MEDIUM_NB_BLOCK;
	memory_info[MEDIUM].nb_octet = MEDIUM_NB_OCTET_BY_BLOCK;
	memory_info[MEDIUM].total_octet = MEDIUM_SIZE_TOTAL;
	memory_info[LARGE].type = LARGE;
	memory_info[LARGE].nb_block = 1;
	memory_info[LARGE].nb_octet = 0;
	memory_info[LARGE].total_octet = 0;
}

/*
** t_memory_manage
*/

void		memory_manage_make(void)
{
	g_mem_manage = (t_memory_manage *)(alloc_mem(sizeof(t_memory_manage)));
	init_memory_info(g_mem_manage->memory_info);
	g_mem_manage->memory_chunk =\
	(t_memory **)alloc_mem(sizeof(t_memory *) * 3);
	g_mem_manage->memory_chunk[TINY] = memory_create_tiny_block();
	g_mem_manage->memory_chunk[MEDIUM] = memory_create_medium_block();
	g_mem_manage->memory_chunk[LARGE] = 0;
}
