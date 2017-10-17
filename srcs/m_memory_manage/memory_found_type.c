/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_found_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:48:44 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:16:51 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

int	memory_found_type(int nb_octet)
{
	if (nb_octet < 1)
		return (-1);
	if (nb_octet <= TINY_NB_OCTET_BY_BLOCK)
		return (TINY);
	if (nb_octet <= MEDIUM_NB_OCTET_BY_BLOCK)
		return (MEDIUM);
	return (LARGE);
}
