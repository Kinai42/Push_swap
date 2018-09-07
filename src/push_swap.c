/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:26:34 by Damien            #+#    #+#             */
/*   Updated: 2018/07/05 17:18:54 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void    init(t_stack *a, t_stack *b, char **av)
{
    int size;
    int i;

    size = 0;
    i = !ft_strcmp(av[1], "-v") ? 1 : 2;
    while (av[++i])
    {
        size += count_number(av[i]);
    }
    printf("AC =  --- SIZE === []%d[]\n", size);
	a->stack = (int*)malloc(sizeof(int) * (unsigned int)(size));
	b->stack = (int*)malloc(sizeof(int) * (unsigned int)(size));
	a->size = 0;
	b->size = 0;
}

int				main(int ac, char **av)
{
	t_stack		a[1];
	t_stack		b[1];
	int 		v;

	if (ac <= 1)
		return (0);
    init(a, b, av);
	av += (v = !ft_strcmp(av[1], "-v"));
	while (*++av)
	{
	/*	if (!*/check_nbr(a, *av, &a->stack[a->size]);/*)*/
	//	{
			//write(2, "\e[31mError\e[38;5;252m\n", 23);
			//return (0);
	//	}
		a->size++;
	}
	if (v)
		info_pile(a, b);
    while (!ft_tri(a->stack, a->size) || b->size > 0)
        resolver(a, b, v);
	return (0);
}

void    info_pile(t_stack *a, t_stack *b)
{
    static int  len;
    int         i;

    len = 0;
    i = -1;
    if (len == 0)
        while(++i < a->size)
            if (len < ft_intlen(a->stack[i]))
            {
                len = ft_intlen(a->stack[i]);
                len += a->stack[i] < 0 ? 1 : 0;
            }
    i = -1;
    ft_printf("%sListe A%s (%d) %s: ", LEMON, VIOLET, a->size, DEFAULT);
    while(++i < a->size)
            ft_printf("%d%s", a->stack[i], i + 1 < a->size ? ", " : "");
    i = -1;
    write(1, "\n", 1);
    ft_printf("%sListe B%s (%d) %s: ", LEMON, VIOLET, b->size, DEFAULT);
    while(++i < b->size)
            ft_printf("%d%s", b->stack[i], i + 1 < b->size ? ", " : "");
    write(1, "\n", 1);
}
