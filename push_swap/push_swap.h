#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <../Libft/libft.h>
#include <../Printf/ft_printf.h>


typedef struct s_node
{
    int value;
    int index;
    int push_cost;
    bool median;
    bool  cheapest;

    struct s_node   *target_node;
    struct s_node   *next;
}   t_node;

//error handling

//stack initialization

//node initialization

//stack operations

//command operations

//algorithm 










// int		ft_printf(const char *s, ...);
// int		ft_putchar(const char c);
// int		ft_putstr(const char *s);
// int		ft_signed(long long s);
// int		ft_convcheck(char s);
// int		ft_putnbr_base(unsigned int num, const char *s, unsigned int base);
// int		ft_funcfetch(va_list args, const char *s);
// int		ft_putptr(unsigned long long num, char *s, size_t base);

// size_t	ft_strlen(const char *s);

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// int		ft_strncmp(const char *s1, const char *s2, size_t n);

// char	*ft_strdup(const char *s1);
// int		ft_atoi(const char *str);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);

// char	**ft_split(char const *s, char c);
// char	*ft_itoa(int n);

// t_list	*ft_lstnew(void *content);

// int		ft_lstsize(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);
 
#endif