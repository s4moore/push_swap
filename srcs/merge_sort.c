/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:12:58 by samoore           #+#    #+#             */
/*   Updated: 2023/12/18 19:37:11 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*make_array(int *nums, int start, int size)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * size);
	while (i < size)
	{
		res[i] = nums[start + i];
		i++;
	}
	return (res);
}

void	merge(int *nums, int l, int m, int r)
{
	int	i;
	int	j;
	int	k;
	int	*left;
	int	*right;

	left = make_array(nums, l, (m - l + 1));
	right = make_array(nums, m + 1, (r - m));
	i = 0;
	j = 0;
	k = l;
	while (i < (m - l + 1) && j < (r - m))
	{
		if (left[i] <= right[j])
			nums[k++] = left[i++];
		else
			nums[k++] = right[j++];
	}
	while (i < (m - l + 1))
		nums[k++] = left[i++];
	while (j < (r - m))
		nums[k++] = right[j++];
	free (left);
	free (right);
}

void	merge_sort(int *nums, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort(nums, left, mid);
		merge_sort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

int	ft_check_dupes(int *nums, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (nums[i] == nums[i - 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_make_sorted(t_stack *stx, int **array, int len)
{
	merge_sort(*array, 0, len);
	stx->lowest = stx->sorted[0];
	stx->highest = stx->sorted[stx->a_len - 1];
	stx->sorted_len = stx->a_len;
	if (ft_check_dupes(stx->sorted, stx->a_len))
	{
		printf("Error\n");
		free_stack(stx);
		exit (1);
	}
}
