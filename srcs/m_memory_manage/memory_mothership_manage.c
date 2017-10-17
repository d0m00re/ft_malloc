/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mothership_manage.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:19:31 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:19:31 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

void	*malloc(size_t size)
{
	if (!g_mem_manage)
		memory_manage_make();
	return (alloc_area_zone(size));
}

void	free(void *ptr)
{
	if (g_mem_manage)
		free_area_zone(ptr);
}

void	*realloc(void *ptr, size_t size)
{
	if (g_mem_manage)
		return (realloc_area_zone(ptr, size));
	return (0);
}
