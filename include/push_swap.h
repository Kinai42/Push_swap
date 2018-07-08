#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "printf.h"

# define DEFAULT "\e[38;5;252m"
# define GREEN "\e[38;5;82m"
# define RED "\e[38;5;196m"
# define ORANGE "\e[38;5;202m"
# define YELLOW "\e[38;5;226m"
# define BLUE "\e[38;5;69m"
# define CYAN "\e[38;5;123m"
# define WHITE "\e[38;5;15m"
# define BROWN "\e[38;5;202m"
# define VIOLET "\e[38;5;5m"
# define LEMON "\e[38;5;190m"

typedef	struct	s_stack
{
	int		size;
	int		*stack;
}				t_stack;

char		check_nbr(t_stack *a, char *str, int *dst);
char        check(t_stack *a, t_stack *b);
void        info_pile(t_stack *a, t_stack *b);
char        ft_tri(int *elem, int size);
void        resolver(t_stack *a, t_stack *b, int v);
void		swap(t_stack *elem);
void		push(t_stack *origin, t_stack *dest);
void		rotate(t_stack *elem, char reverse);
void		double_operator(char op, t_stack *a, t_stack *b);

#endif
