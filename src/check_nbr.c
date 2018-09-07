#include "checker.h"

void    ft_error()
{
    write(2, "\e[31mError\e[38;5;252m\n", 23);
    exit (0);
}

char			check_nbr(t_stack *a, char *str, int *dst)
{
    char	*tmp;
    char	neg;
    int		i;

    *dst = 0;
    while (*str == ' ')
        str++;
    neg = *str == '-' ? -1 : 1;
    if (!str[i = str[0] == '-' ? 1 : 0])
        ft_error();
    while (str[i] <= '9' && str[i] >= '0')
        *dst += *dst * 9 + str[i++] - '0';
    *dst *= neg;
    if (str[i] && !(str[i] == ' ' && ft_isdigit(str[i - 1])))
        ft_error();
    neg = (char)i - 1;
    i = 0;
    while (i < a->size)
        if (a->stack[i++] == *dst)
            ft_error();
    while (str[++neg] == ' ');
    if (str[neg])
        check_nbr(a, &str[neg], &a->stack[a->size += 1]);
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

int count_number(char *av)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while(av[i])
    {
        while (av[i] == ' ')
            i++;
        printf("2 - AV [i] = [%c] i = [%d]\n", av[i], i);
        if (!av[i])
            return(count);
        count++;
        while (ft_isdigit(av[i]) || av[i] == '-')
            i++;
        if (av[i] && !(ft_isdigit(av[i]) || av[i] == ' '))
            return (0);
    }
    return (count);
}
