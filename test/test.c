#include "memory_manage.h"
#include <string.h>

        int tiny_size = TINY_NB_OCTET_BY_BLOCK - 1;
        int medium_size = MEDIUM_NB_OCTET_BY_BLOCK - 1;
        int large_size = MEDIUM_NB_OCTET_BY_BLOCK + 10;


void	display_result(char *name_test, int value)
{
	memory_manage_reset();
	if (value)
		ft_putstr("Good : ");
	else
		ft_putstr("Error : ");
	ft_putstr(name_test);
	ft_putchar('\n');
}

/*
** type : gen
** malloc : test size alloc
*/

int test_gen_malloc(int nb_octet, int nb_block)
{
	int c;
	unsigned int size;

	c = 0;
	size = nb_octet * nb_block;
	while (c < nb_block)
	{
		malloc(nb_octet);
		c++;
	}
	return (size == calcul_nb_octet());
}

/*
** type gen
** malloc : test free zone
*/
int test_gen_free(int nb_octet, int nb_block)
{
	int c;
	int size;
	char *addr[1000];

	c = 0;
	while (c < nb_block)
	{
		addr[c] = malloc(nb_octet);
		c++;
	}
	c = 0;
	while (c < nb_block)
	{
		free(addr[c]);
		c++;
	}
	return (!calcul_nb_octet());
}

/*
** type : gen
** test : realloc
*/
int test_gen_realloc(int nb_octet, unsigned int octet_to_realloc, int nb_block)
{
	int c;
	int size;
	char *addr[1000];

	c = 0;
	while (c < nb_block)
	{
		addr[c] = malloc(nb_octet);
		c++;
	}
	c = 0;
	while (c < nb_block)
	{
		addr[c] = realloc(addr[c], octet_to_realloc);
		c++;
	}
	return (calcul_nb_octet() == nb_block * octet_to_realloc);
}

void test_malloc_zero(char *name)
{
		void *addr;

		addr = malloc(0);
		if (addr)
			ft_putstr("Error : ");
		else
			ft_putstr("Good : ");
		ft_putstr(name);
		ft_putchar('\n');
}

void test_free_null()
{
	int a;

	free(NULL);
	free(&a);
}

void show_mem_data(int show)
{
	if (!show)
		return;
	show_all_memory_data_status(TINY, 2);
	show_all_memory_data_status(MEDIUM, 2);
	show_all_memory_data_status(LARGE, 2);
}

int test_malloc_add_str(int show)
{
	int c;
	char *addr[10];

	c = 0;
	addr[0] = malloc(10);
	addr[1] = malloc(14);
	addr[2] = malloc(medium_size);
	addr[3] = malloc(large_size);
	addr[4] = malloc(large_size);
	strcpy(addr[0], "Salope !!!!");
	strcpy(addr[1], "MIAOU567890123");
	strcpy(addr[2], "Coucou ma grosse salope de malloc :), on test les zone medium.\n");
	strcpy(addr[3], "Miaou Miaou Miaou !?@$%^&%??$?#?%?^??&??%??$?#?$?^?^?&??^?%?#??%?^?&?%??#??$123456789");
	strcpy(addr[4], "C est la ou la vie ca jouer avec vous et ou vous allez sombrer pendant un certain moment!");
	show_mem_data(show);
	if (!strcmp(addr[0], "Salope !!!!") && !strcmp(addr[1], "MIAOU567890123") && !strcmp(addr[2], "Coucou ma grosse salope de malloc :), on test les zone medium.\n")\
	&& !strcmp(addr[3], "Miaou Miaou Miaou !?@$%^&%??$?#?%?^??&??%??$?#?$?^?^?&??^?%?#??%?^?&?%??#??$123456789") &&\
	!strcmp(addr[4], "C est la ou la vie ca jouer avec vous et ou vous allez sombrer pendant un certain moment!"))
		return (1);
	return (0);
}

/*
** type : gen
** test data realloc
*/
int test_gen_realloc_add_str(int show, int size_init, int size_realloc, char *ori, int size_test)
{
        int c;
        char *addr[10];
        char *addr_t[10];

        c = 0;
        while (c < 10)
        {
                addr[c] = malloc(size_init);
                strcpy(addr[c], ori);
                c++;
        }
	c = 0;
	while (c < 10)
	{
		addr_t[c] = realloc(addr[c], size_realloc);
                if (strncmp(addr_t[c], ori, size_test))
			return (0);
		c++;
	}
        show_mem_data(show);
        return (1);
}

/*
** test of not the good addr to free or realloc
*/
int test_wrong_addr_free_realloc(int show, int size_alloc)
{
	char *addr[10];
	int c;
	int init_size;

	c = 0;
	while(c < 10)
	{
		addr[c] = malloc(size_alloc);
		c++;
	}
	init_size = calcul_nb_octet();
	free(addr[1] + 5);
	addr[9] = realloc(addr[1] + 5, 200);
	if (addr[9] || init_size != calcul_nb_octet())
		return (0);
	free(addr[1]);
	return (1);
}

#include <stdio.h>

int main()
{
	int c;
	void *addr[100];
	void *addr2[100];


	//addr[0] = malloc
	int *x = malloc(12);
        *x = 4;
           x[1] = 5;
	x[2] = 244;
                printf("%p - %p - %p\n", &x[0], &x[1], &x[2]);
                x = realloc(x, 16000);
                printf("%p - %p - %p\n", &x[0], &x[1], &x[2]);
                return 0;
/*	c = 0;
	while (c < 100)
	{
		addr[c] = malloc(10);
		c++;
	}
	c = 0;
	while (c < 100)
	{
		addr2[c] = realloc(addr[c], 1000);
		c++;
	}
	return (1);
*/
}

int main2(void)
{
	//int tiny_size = TINY_NB_OCTET_BY_BLOCK - 1;
	//int medium_size = MEDIUM_NB_OCTET_BY_BLOCK - 1;
	//int large_size = MEDIUM_NB_OCTET_BY_BLOCK + 10;
	//test_gen_malloc(char *name_test, int nb_octet, int nb_block);
	/*
	** test d allocation de zone basic
	*/

	display_result("1) malloc tiny --> 10 blocks", test_gen_malloc(tiny_size, 10));
	display_result("2) malloc tiny --> 100 blocks", test_gen_malloc(tiny_size, 100));
	display_result("3) malloc tiny --> 1000 blocks\n", test_gen_malloc(tiny_size, 1000));

	display_result("4) malloc medium --> 10 blocks", test_gen_malloc(medium_size, 10));
	display_result("5) malloc medium --> 100 blocks", test_gen_malloc(medium_size, 100));
	display_result("6) Test malloc medium --> 1000 blocks\n", test_gen_malloc(medium_size, 1000));

	display_result("7) malloc large  --> 10 blocks", test_gen_malloc(large_size, 10));
	display_result("8) malloc large  --> 100 blocks", test_gen_malloc(large_size, 100));
	display_result("9) malloc large  --> 1000 blocks\n", test_gen_malloc(large_size, 1000));

	/*
	** test de free de zone basic
	*/
	display_result("10) free tiny --> 10 blocks", test_gen_free(tiny_size, 10));
	display_result("11) free tiny --> 100 blocks", test_gen_free(tiny_size, 100));
	display_result("12) free tiny --> 1000 blocks\n", test_gen_free(tiny_size, 1000));

	display_result("13) free medium --> 10 blocks", test_gen_free(medium_size, 10));
	display_result("14) free medium --> 100 blocks", test_gen_free(medium_size, 100));
	display_result("15) free medium --> 1000 blocks\n", test_gen_free(medium_size, 1000));

	display_result("16) free large  --> 10 blocks", test_gen_free(large_size, 10));
	display_result("17) free large  --> 100 blocks", test_gen_free(large_size, 100));
	display_result("18) free large  --> 1000 blocks\n", test_gen_free(large_size, 1000));

	/*
	** test de realloc
	*/
	//test_gen_realloc(char *name_test, int nb_octet, int nb_block, unsigned int octet_to_realloc)
	display_result("19) realloc tiny --> tiny --> 10 blocks", test_gen_realloc(tiny_size / 2, tiny_size, 10));
	display_result("20) realloc tiny --> tiny --> 100 blocks", test_gen_realloc(tiny_size / 2, tiny_size, 100));
	display_result("21) realloc tiny --> tiny --> 1000 blocks\n", test_gen_realloc(tiny_size / 2, tiny_size, 1000));

	display_result("22) realloc medium --> medium --> 10 blocks", test_gen_realloc(medium_size - 10, medium_size, 10));
	display_result("23) realloc medium --> medium --> 100 blocks", test_gen_realloc(medium_size - 10, medium_size, 100));
	display_result("24) realloc medium --> medium --> 1000 blocks\n", test_gen_realloc(medium_size - 10, medium_size, 1000));

	display_result("25) realloc large --> large --> 100 blocks", test_gen_realloc(large_size, large_size + 100, 10));
	display_result("26) realloc large --> large --> 100 blocks", test_gen_realloc(large_size, large_size + 100, 100));
	display_result("27) realloc large --> large --> 1000 blocks\n", test_gen_realloc(large_size, large_size + 100, 1000));

	display_result("28) realloc tiny --> medium --> 10 blocks", test_gen_realloc(tiny_size, medium_size, 10));
	display_result("29) realloc tiny --> medium --> 100 blocks", test_gen_realloc(tiny_size, medium_size, 100));
	display_result("30) realloc tiny --> medium --> 1000 blocks\n", test_gen_realloc(tiny_size, medium_size, 1000));

	display_result("31) realloc tiny --> large --> 10 blocks", test_gen_realloc(tiny_size, large_size, 10));
	display_result("32) realloc tiny --> large --> 100 blocks", test_gen_realloc(tiny_size, large_size, 100));
	display_result("33) realloc tiny --> large --> 1000 blocks\n", test_gen_realloc(tiny_size, large_size, 1000));

	display_result("34) realloc medium --> large --> 10 blocks", test_gen_realloc(medium_size, large_size, 10));
	display_result("35) realloc medium --> large --> 100 blocks", test_gen_realloc(medium_size, large_size, 100));
	display_result("36) realloc medium --> large --> 1000 blocks\n", test_gen_realloc(medium_size, large_size, 1000));

	//test_malloc_zero("37) malloc size 0 octet\n");
	//test_free_null();
	//display_result("38) malloc test str add", test_malloc_add_str(1));
	//test_realloc_add_str();

	display_result("39) realloc test str | realloc 100octet to 2000 octet", test_gen_realloc_add_str(0, 1000, 2000, "MON TEST", 2000));
        display_result("40) realloc test str | realloc 100octet to 200 octet", test_gen_realloc_add_str(0, 1000, 200, "MON TEST", 200));
        display_result("41) realloc test str | realloc 100octet to 20 octet", test_gen_realloc_add_str(0, 1000, 20, "MON TEST", 20));
        display_result("42) realloc test str | realloc 100octet to 2 octet", test_gen_realloc_add_str(0, 1000, 2, "MON TEST", 2));

	display_result("43) free and realloc false addr", test_wrong_addr_free_realloc(1, 50));

	show_alloc_mem();
	//test_gen_realloc_add_str(int show, int size_init, int size_realloc, char *ori)
	//display_result("39) realloc test str | realloc 100octet to 2 octet", test_gen_realloc_add_str(1, 1000, 2, "MA BITE", 2));
	return (1);
}
