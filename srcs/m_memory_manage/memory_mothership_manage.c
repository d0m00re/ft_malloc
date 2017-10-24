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
//	ft_putstr("MALLOC BEGIN : "); ft_putnbr(size); ft_putstr("\n");
	if (!g_mem_manage)
	{
//		ft_putstr("MALLOC OUI\n");
		memory_manage_make();
//		ft_putstr("Fucking MALLOC\n");
	}
//	ft_putstr("--> go in alloc area zone : "); ft_putnbr(size); ft_putstr("\n");
	return (alloc_area_zone(size));
}

void	free(void *ptr)
{
//	ft_putstr("FREE\n");
	if (g_mem_manage)
		free_area_zone(ptr);
}

void	*realloc(void *ptr, size_t size)
{
//	ft_putstr("REALLOC : "); ft_putnbr(size); ft_putstr("\n");
	if (g_mem_manage)
	{
//		ft_putstr("\tBegin realloc area zone \n");
		return (realloc_area_zone(ptr, size));
	}
	return (0);
}
