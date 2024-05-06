/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:39:24 by samoore           #+#    #+#             */
/*   Updated: 2023/12/19 16:47:43 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define UP 1
# define DOWN -1
# define ERROR 3000000000

typedef struct s_stack
{
	int	*a;
	int	a_len;
	int	*b;
	int	b_len;
	int	*sorted;
	int	sorted_len;
	int	*lis;
	int	lis_len;
	int	*nums_to_split;
	int	nums_to_split_len;
	int	total_nums;
	int	moves;
	int	lowest;
	int	highest;
	int	max_p;
	int	i;
	int	j;
	int	move_a;
	int	move_b;
	int	a_up_down;
	int	b_up_down;
}	t_stack;

typedef struct s_move
{
	int	moves;
	int	i;
	int	j;
	int	move_a;
	int	move_b;
	int	a_up_down;
	int	b_up_down;
}	t_move;

void	check_cost(t_stack *stx, int j, t_move *mov);
int		down_a_down_b_up(t_move *m, int b_len);
int		down_a_up_b_down(t_move *m, int b_len);
void	down_down(t_stack *stx);
void	find_best(t_stack *stx, t_move *mov);
int		find_low(t_stack *stx);
void	ft_pre_sort(t_stack *stx);
int		find_high(t_stack *stx);
int		find_pos(int *array, int num, int len);
int		find_target_a(t_stack *stx, int j);
void	free_stack(t_stack *stx);
void	*ft_calloc(int nmemb, int size);
int		ft_sorted(t_stack *stx);
void	ft_make_sorted(t_stack *stx, int **array, int len);
void	get_lis(t_stack *stx);
void	get_nums(int argc, char **argv, t_stack *stx);
int		in_set(int target, int *set, int size);
int		max(int a, int b);
int		min(int a, int b);
void	pa(t_stack *stx);
void	pb(t_stack *stx);
void	pr(t_stack *stx);
void	print_arr(int *arr, int len);
void	push_to_b(t_stack *stx, int high_nums);
void	putstr(char *str);
void	ra(t_stack *stx);
void	rb(t_stack *stx);
void	rr(t_stack *stx);
void	rra(t_stack *stx);
void	rrb(t_stack *stx);
void	rrr(t_stack *stx);
void	sa(t_stack *stx);
void	set_m(t_move *m, char a_or_b, int up_down, int moves);
void	sb(t_stack *stx);
void	sort_last(t_stack *stx);
void	ss(t_stack *stx);
int		top(t_stack *stx);
int		up_a_up_b_down(t_move *m, int b_len);
int		up_b_up_a_down(t_move *m, int a_len, int b_len);
void	up_up(t_stack *stx);
int		up_or_down(int *nums, int *set, int len, int size);

#endif
