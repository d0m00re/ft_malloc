/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_area_zone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:34:34 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/17 15:49:06 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

void			*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	char		*dest2;
	const char	*src2;

	dest2 = (char *)dst;
	src2 = (char *)src;
	while (n > 0)
	{
		*dest2 = *src2;
		if (n > 1)
		{
			dest2++;
			src2++;
		}
		n--;
	}
	return (dst);
}

/*
** ptr : target ptr (TIINY, MEDIUM or LARGE)
** size : size of the new zones
** rea
*/

void			*realloc_basic_zone(void *ptr, unsigned int size,\
				int type, t_memory *mem)
{
	t_memory	*new_mem;
	int			pos;

	pos = found_id_mem_area_in_basic(ptr, mem, type);
	if (pos != -1)
	{
		if (size <= g_mem_manage->memory_info[type].nb_octet)
		{
			mem->mem_status[pos] = size;
			return (ptr);
		}
		else
		{
			if (!(new_mem = alloc_area_zone(size)))
				return (0);
			ft_memcpy(new_mem, (const void *)(mem->data),\
					mem->mem_status[pos]);
			free_area_zone(ptr);
			return (new_mem->data);
		}
	}
	return (0);
}

/*
** http://www.cplusplus.com/reference/cstdlib/realloc/
*/

void			*realloc_zero_case(void *ptr)
{
	free_area_zone(ptr);
	return (alloc_area_zone(1));
}

void			*realloc_area_zone(void *ptr, unsigned int size)
{
	t_memory	*mem;
	t_memory	*new_mem;

	mem = 0;
	new_mem = 0;
	if (!ptr)
		return (0);
	if (size == 0)
		return (realloc_zero_case(ptr));
	if ((mem = found_mem_area_in_large2(ptr)))
	{
		if (!(new_mem = alloc_area_zone(size)))
			return (0);
		if (size > MEDIUM_NB_OCTET_BY_BLOCK)
			ft_memcpy(new_mem, (const void *)(mem->data), mem->mem_status[0]);
		else
			ft_memcpy(new_mem, (const void *)(mem->data), size);
		free_area_zone(ptr);
		return (new_mem);
	}
	else if ((mem = found_mem_area_in_basic(ptr, TINY)))
		return (realloc_basic_zone(ptr, size, TINY, mem));
	else if ((mem = found_mem_area_in_basic(ptr, MEDIUM)))
		return (realloc_basic_zone(ptr, size, MEDIUM, mem));
	return (0);
}
