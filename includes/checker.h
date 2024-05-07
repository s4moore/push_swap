/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:24 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 16:47:43 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define UP 1
# define DOWN -1
# define ERROR 3000000000

typedef struct s_cmd
{
	struct s_cmd	*next;
	char			*str;
}	t_cmd;

typedef struct s_stack
{
	t_cmd	*list;
	int		*a;
	int		*b;
	int		*sorted;
	int		total_nums;
	int		a_len;
	int		b_len;
	int		sorted_len;
}	t_stack;

void	check_result(t_stack *stx);
void	clear_and_exit(char *str, t_cmd *head);
int		compare(char *s1, char *s2);
void	free_list(t_cmd *list);
void	free_stack(t_stack *stx);
void	*ft_calloc(int nmemb, int size);
int		ft_sorted(t_stack *stx);
void	ft_make_sorted(t_stack *stx);
t_cmd	*get_instructions(void);
void	get_nums(int argc, char **argv, t_stack *stx);
void	init_stack(t_stack *stx, int argc);
void	pa(t_stack *stx);
void	pb(t_stack *stx);
void	pr(t_stack *stx);
void	push_to_b(t_stack *stx, int target, int thrid, int rem);
void	putstr(char *str);
void	ra(t_stack *stx);
void	rb(t_stack *stx);
void	rr(t_stack *stx);
void	rra(t_stack *stx);
void	rrb(t_stack *stx);
void	rrr(t_stack *stx);
void	sa(t_stack *stx);
void	sb(t_stack *stx);
void	ss(t_stack *stx);

#endif
