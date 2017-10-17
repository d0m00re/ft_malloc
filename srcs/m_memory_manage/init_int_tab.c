/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:54:36 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/10 20:14:29 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

void				init_int_tab(int *tab, unsigned int size)
{
	unsigned int	c;

	c = 0;
	while (c < size)
	{
		tab[c] = 0;
		c++;
	}
}
