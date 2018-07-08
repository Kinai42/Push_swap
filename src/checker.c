/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Damien <dbauduin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 14:26:34 by Damien            #+#    #+#             */
/*   Updated: 2018/07/05 17:18:54 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "checker.h"

void    init(t_stack *a, t_stack *b, int ac)
{
	a->stack = (int*)malloc(sizeof(int) * (unsigned int)(ac - 1));
	b->stack = (int*)malloc(sizeof(int) * (unsigned int)(ac - 1));
	a->size = 0;
	b->size = 0;
}

static char		exec(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb"))
		swap(cmd[1] == 'a' ? a : b);
	else if (!ft_strcmp(cmd, "ss"))
		double_operator('s', a, b);
	else if (!ft_strcmp(cmd, "pa") || !ft_strcmp(cmd, "pb"))
		cmd[1] == 'a' ? push(b, a) : push(a, b);
	else if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rb"))
		rotate(cmd[1] == 'a' ? a : b, 0);
	else if (!ft_strcmp(cmd, "rr"))
		double_operator('r', a, b);
	else if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb"))
		rotate(cmd[2] == 'a' ? a : b, 1);
	else if (!ft_strcmp(cmd, "rrr"))
		double_operator('R', a, b);
	else
		return (0);
	return (1);
}

static char		ft_read(t_stack *a, t_stack *b, char v)
{
	char	*buf;
    int     rd;

    buf = malloc(sizeof(char) * 5);
	while (ft_printf("%sAction %s: ", ORANGE, DEFAULT) && (rd = read(0, buf, 4)))
	{
        buf[rd - 1] = 0;
		if (!exec(buf, a, b))
		{
			write(2, "\x1b[31mError\e[38;5;252m\n", 23);
			return (0);
		}
		if (v)
		    info_pile(a, b);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char		v;

	if (ac <= 1)
		return (0);
    init(&a, &b, ac);
	av += (v = !ft_strcmp(av[1], "-v"));
	while (*++av)
	{
		if (!check_nbr(&a, *av, &a.stack[a.size]))
		{
			write(2, "\e[31mError\e[38;5;252m\n", 23);
			return (0);
		}
		a.size++;
	}
	if (v)
		info_pile(&a, &b);
	ft_read(&a, &b, v); 
    ft_printf("%s\n%sResult   %s\n", v == 1 ? "Finish" : "", ORANGE, check(&a, &b) ? "\e[32mOK" : "\e[31mKO");
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
