#include "push_swap.h"

int *search(int *stack, int size, int *nb)
{
    int i;

    i = -1;
    nb[0] = 0;
    nb[1] = size - 1;


    while(++i < size / 2)
    {
        if (stack[nb[0]] > stack[i])
            nb[0] = i;
        //printf("i = %d\n",i );

    }
    i = size;
    while(--i >= size / 2)
    {
        if (stack[nb[1]] > stack[i])
            nb[1] = i;
        //printf("i = %d\n",i );
    }
    return (nb);
}

char    ft_tri(int *elem, int size)
{
    int     i;

    i = -1;;
    while(++i < size - 1)
        if(elem[i] > elem[i + 1])
            return (0);
    return (1);
}

void    resolver(t_stack *a, t_stack *b, int v)
{
    int  index[2];
    int i;

    search(a->stack, a->size, index);
    i = a->stack[index[0]] <= a->stack[index[1]] ? index[0] : index[1];

    //printf("I = %d INDEX = %d-%d  SIZE = %d TRI=%d\n", i, index[0], index[1], a->size, ft_tri(a->stack, a->size));


    if (!ft_tri(a->stack, a->size) && i == 1)
    {
        printf("SA\n");
        swap(a);
    }
    else if (b->size && (b->stack[0] > a->stack[index[0]] || a->stack[index[1]] < b->stack[b->size - 1]))
    {
        printf("RB\n");
        rotate(b, 0);
    }
    else if (!ft_tri(a->stack, a->size) && i == 0)
    {
        printf("PA\n");
        push(a, b);
    }
    else if (ft_tri(a->stack, a->size) && b->stack[0] >= b->stack[b->size - 1] && b->size > 0)
    {
        printf("PB\n");
        push(b, a);
    }
    else if (!ft_tri(a->stack, a->size) && i > 1 && i < a->size / 2)
    {
        printf("RA\n");
        rotate(a, 0);
    }
    else if (!ft_tri(a->stack, a->size) && i >= ((a->size / 2)) && i < a->size)
    {
        printf("RRA\n");
        rotate(a, 1);
    }








    //RRA / RRB / RRR
   /* if (b->size && (b->stack[b->size - 1] > b->stack[0]) && (i > ((a->size / 2)) && !ft_tri(a->stack, a->size)))
    {
        printf("RRR\n");
        double_operator('R', a, b);
    }
    else if (i > ((a->size / 2)) && !ft_tri(a->stack, a->size))
    {
        printf("RRA\n");
        rotate(a, 1);
    }
    else if (b->size && b->stack[b->size - 1] > b->stack[0])
    {
        printf("RRB\n");
        rotate(b, 1);
    }



    //pour push en A
    else if (ft_tri(a->stack, a->size))
    {
        printf("PB\n");
        push(b, a);
    }
    //pour push le plus petit en B
    else if (i == 0 && (!ft_tri(a->stack, a->size)))
    {
        printf("PA\n");
        push(a, b);

    }
    //va chercher le 2ieme nombre
    else if (i == 1 && (!ft_tri(a->stack, a->size)))
    {
        printf("SA\n");
        swap(a);

    }




    else if ((a->stack[index[0]] < b->stack[b->size - 1] || a->stack[index[1]] < b->stack[b->size - 1]) && (i < ((a->size / 2) + 1) && !ft_tri(a->stack, a->size)))
    {
        printf("RR\n");
        double_operator('r', a, b);

    }
    //tri les plus grands a gauche si a->stack < b->stack
    else if (b->size > 1 && (a->stack[index[0]] < b->stack[b->size - 1] || a->stack[index[1]] < b->stack[b->size - 1]))
    {
        printf("RB\n");
        rotate(b, 0);

    }
    //va chercher les plus petits nombres 1er moitier
    else if (i < ((a->size / 2) + 1) && !ft_tri(a->stack, a->size))
    {
        printf("RA\n");
        rotate(a, 0);

    }*/


    if(v)
        info_pile(a, b);
    if (!ft_tri(a->stack, a->size) || b->size)
        resolver(a, b, v);
}
