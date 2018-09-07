#include "push_swap.h"

void    search(int *stack, int size, int *nb)
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
    //usleep(5000);
    if ((!ft_tri(a->stack, a->size) && i == 1))
    {
        write(1, "sa\n", 3);
        //printf("sa\n");
        swap(a);
    }
    else if (b->size && (b->stack[0] > a->stack[index[0]] || a->stack[index[1]] < b->stack[b->size - 1]))
    {
        write(1, "rb\n", 3);
        //printf("rb\n");
        rotate(b, 0);
    }
    else if (!ft_tri(a->stack, a->size) && i == 0)
    {
        write(1, "pb\n", 3);
        //printf("pb\n");
        push(a, b);
    }
    else if (ft_tri(a->stack, a->size) && b->stack[0] >= b->stack[b->size - 1] && b->size > 0)
    {
        write(1, "pa\n", 3);
        //printf("pa\n");
        push(b, a);
    }
    else if (!ft_tri(a->stack, a->size) && i > 1 && i < a->size / 2)
    {
        write(1, "ra\n", 3);
        //printf("ra\n");
        rotate(a, 0);
    }
    else if (!ft_tri(a->stack, a->size) && i >= ((a->size / 2)) && i < a->size)
    {
        write(1, "rra\n", 4);
        //printf("rra\n");
        rotate(a, 1);
    }
    if(v)
        info_pile(a, b);
}
