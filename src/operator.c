#include "checker.h"

void		swap(t_stack *elem)
{
	int		tmp;

	if (elem->size < 2)
		return ;
	tmp = elem->stack[0];
	elem->stack[0] = elem->stack[1];
	elem->stack[1] = tmp;
}

void		push(t_stack *origin, t_stack *dest)
{
	int		i;

	if (!origin->size)
		return ;
	i = dest->size;
	while (i--)
		dest->stack[i + 1] = dest->stack[i];
	dest->stack[0] = origin->stack[0];
	dest->size++;
	origin->size--;
	i = 0;
	while (i++ < origin->size)
		origin->stack[i - 1] = origin->stack[i];
}

void		rotate(t_stack *elem, char reverse)
{
	int		tmp;
	int		i;

	if (elem->size < 2)
		return ;
	if (!reverse)
	{
		tmp = elem->stack[0];
		i = 0;
		while (i++ < elem->size)
			elem->stack[i - 1] = elem->stack[i];
		elem->stack[i - 2] = tmp;
	}
	else
	{
		tmp = elem->stack[elem->size - 1];
		i = elem->size;
		while (i--)
			elem->stack[i + 1] = elem->stack[i];
		elem->stack[0] = tmp;
	}
}

void		double_operator(char op, t_stack *a, t_stack *b)
{
	if (op == 's')
	{
		swap(a);
		swap(b);
	}
	else if (op == 'r')
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else if (op == 'R')
	{
		rotate(a, 1);
		rotate(b, 1);
	}
}
