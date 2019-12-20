/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:48:14 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/12 16:16:44 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_manage.h"

int main(void)
{
  char *addr_tiny[10];
  char *addr_middle[10];
  char *addr_large[5];
  int tiny = 0;
  int middle = 0;
  int large = 0;
  char *tmp;

  while (tiny < 10)
  {
    addr_tiny[tiny] = (char *)(malloc(5));
    tiny++;
  }
  while (middle < 10)
  {
    addr_middle[middle] = (char *)(malloc(10));
    middle++;
  }
  while (large < 5)
  {
    addr_large[large] = (char *)(malloc(200));
    large++;
  }
  ft_putstr("Art\n");
  tmp = realloc_area_zone(addr_tiny[1], 80);
  ft_putstr("Extra\n");
  show_alloc_mem();
  return (1);
}
