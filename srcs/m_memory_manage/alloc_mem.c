/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:15:56 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:06:33 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"
#include <string.h>

void	*alloc_mem(size_t size)
{
	return (mmap(NULL, size, PROT_READ | PROT_WRITE,\
				MAP_ANON | MAP_SHARED, -1, 0));
}
