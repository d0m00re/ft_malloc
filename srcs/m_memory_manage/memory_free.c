/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:24:05 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:17:43 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

/*
** purpose : free structure t_memory
** ret : 0 : ok | 1 : error
*/

int		memory_free_large(t_memory *memory)
{
	if (!memory)
		return (1);
	free_mem(memory->data, memory->mem_status[0]);
	free_mem(memory->mem_status, sizeof(int));
	free_mem(memory, sizeof(t_memory));
	memory = 0;
	return (0);
}
