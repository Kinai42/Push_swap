#include "checker.h"

char			check_nbr(t_stack *a, char *str, int *dst)
{
	char	*tmp;
	char	neg;
	int		i;

	*dst = 0;
	neg = *str == '-' ? -1 : 1;
	if (!str[i = str[0] == '-' ? 1 : 0])
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
		*dst += *dst * 9 + str[i++] - '0';
	*dst *= neg;
	if (i == 0 || ft_strcmp(str, (tmp = ft_itoa(*dst))))
		return (0);
	free(tmp);
    i = 0;
	while (i < a->size)
    {
        if (a->stack[i++] == *dst)
			return (0);
    }
	return (1);
}

char			check(t_stack *a, t_stack *b)
{
	int		i;

	i = a->size;
	if (b->size)
		return (0);
	while (i-- > 1)
		if (a->stack[i] < a->stack[i - 1])
			return (0);
	return (1);
}
