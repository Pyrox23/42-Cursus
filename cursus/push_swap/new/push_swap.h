/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:26:41 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/22 19:12:01 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define I_MIN "2147483648"
# define I_MAX "2147483647"
# define STK_A 1
# define STK_B 0
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				content;
	int				key;
}	t_list;

typedef struct s_stacks
{
	t_list	*stk_a;
	int		size_a;
	t_list	*stk_b;
	int		size_b;
}	t_stacks;

int		check_input(char **ls, int *size, t_list **stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1);
void	free_list(char ***arr, size_t len);
int		get_length(char **ls);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*sort_stack(t_stacks data);
t_list	*tiny_sort(t_stacks data);
void	stop_program(t_list *s_in, int ext_val);
void	swap(t_stacks *data, int stack);
void	push(t_stacks *data, int stack);
void	rotate(t_stacks *data, int stack);
void	reverse_rotate(t_stacks *data, int stack);
int		is_sorted(int *stack, int size);
void	swap_dirs(int *a, int *b);
int		*copy_stack(t_list *stack, int size);

/* void	print_stk(t_list *stack)
{
	t_list	*node;

	printf("stk_a:\n");
	node = stack;
	while (node)
	{
		printf("%d, key: %d\n", node->content, node->key);
		node = node->next;
	}
} */

//ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
//valgrind --leak-check=full ./push_swap ""

#endif