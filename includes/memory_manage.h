/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <alhelson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:30:01 by alhelson          #+#    #+#             */
/*   Updated: 2017/10/17 15:43:01 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGE_H
# define MEMORY_MANAGE_H
# include <sys/mman.h>
# include <unistd.h>

# define GET_PAGE_SIZE getpagesize()

# define TINY_NB_OCTET_BY_BLOCK 64
# define MEDIUM_NB_OCTET_BY_BLOCK 256

# define TINY_SIZE_TOTAL TINY_NB_BLOCK * TINY_NB_OCTET_BY_BLOCK
# define MEDIUM_SIZE_TOTAL MEDIUM_NB_BLOCK * MEDIUM_NB_OCTET_BY_BLOCK

# define TINY_NB_BLOCK GET_PAGE_SIZE / TINY_NB_OCTET_BY_BLOCK
# define MEDIUM_NB_BLOCK GET_PAGE_SIZE / MEDIUM_NB_OCTET_BY_BLOCK

typedef struct s_memory_info	t_memory_info;
typedef struct s_memory			t_memory;
typedef struct s_linked			t_linked;
typedef struct s_memory_manage	t_memory_manage;

enum	e_type_memory {TINY, MEDIUM, LARGE};

struct							s_memory_info
{
	int							type;
	unsigned int				nb_block;
	unsigned int				nb_octet;
	unsigned int				total_octet;
};

struct							s_linked
{
	void						*next;
	void						*last;
};

struct							s_memory
{
	t_linked					link;
	void						*data;
	int							*mem_status;
	unsigned int				total_octet_mem;
};

int								memory_free_large(t_memory *memory);

struct							s_memory_manage
{
	t_memory_info				memory_info[3];
	t_memory					**memory_chunk;
};

t_memory_manage					*g_mem_manage;

void							*malloc(size_t size);
void							free(void *ptr);
void							*realloc(void *ptr, size_t size);

/*
** purpose : allocate zone in memory manage and return addr
*/

t_memory						*alloc_area_zone(unsigned int nb_octet);
void							free_area_zone(void *ptr);

/*
** purpose : allocate memories
** input : nb octect
** output : addr of allocate zone
*/

void							*alloc_mem(size_t size);

/*
** purpose : free memories area
** input : addr memories area, size of zone
** output : error code
*/

int								free_mem(void *mem, size_t size);

/*
** purpose : create t_memory block
** enter : num of zone
*/

t_memory						*memory_create_tiny_block(void);
t_memory						*memory_create_medium_block(void);
t_memory						*memory_create_large_block\
									(unsigned int nb_octet);
t_memory						*memory_create_block(unsigned int nb_block,\
		unsigned int nb_octet);
t_memory						*memory_create_type_block(int type,\
		unsigned int nb_octet);

/*
** purpose: create t_memory_manage
*/

void							memory_manage_make(void);

/*
** purpose : found type of memory_manage_make
*/

int								memory_found_type(int nb_octet);

void							init_int_tab(int *tab, unsigned int size);

/*
** search elem block with ptr on data
*/

int								found_id_mem_area_in_basic(void *ptr,\
		t_memory *block_ptr, int type);
t_memory						*found_mem_area_in_basic(void *ptr, int type);
t_memory						*found_mem_area_in_large(void *ptr);

/*
** return exact elememnt in t_memory large
*/

t_memory						*found_mem_area_in_large2(void *ptr);

/*
** manage REALLOC
*/

void							*realloc_area_zone(void *ptr,\
		unsigned int size);

/*
** display mem
*/

void							show_alloc_mem(void);
void							show_memory_spec(void);

void							show_memory_tab_status(t_memory *mem,\
		unsigned int type);
void							show_all_memory_tab_status(unsigned int type);

void							show_memory_data_status(t_memory *mem,\
		unsigned int type);

void							show_all_memory_data_status(unsigned int type,\
		unsigned int depth);

/*
** manage number
*/

void							ft_putchar(char c);
void							ft_putnbr(int nb);
void							ft_putnbr_base(int nb, unsigned int base);
void							ft_putstr(char *str);
unsigned int					ft_strlen(char *str);

void							memory_manage_reset(void);

unsigned int					calcul_nb_octet(void);

#endif
