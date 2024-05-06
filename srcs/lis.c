#include "../includes/push_swap.h"

void	get_lis(t_stack *stx)
{
	int	i;
	int	j;
	int	k;
	int	**lis;
	int	**res;

	k = 0;
	res = ft_calloc(sizeof(int *), stx->a_len);
	lis = ft_calloc(sizeof(int *), stx->a_len);
	k = 0;
	while (k <= stx->a_len - 1)
	{
		lis[k] = ft_calloc(sizeof(int), stx->a_len);
		i = 0;
		res[k] = ft_calloc(sizeof(int), 2);
		j = 0;		
		i = k - 1;
		if (i == -1)
			i = stx->a_len - 1;
		while (i != k)
		{
			j = k;
			while (j != i)
			{
				if (stx->a[i] > stx->a[j])
					lis[k][i] = max(lis[k][i], lis[k][j] + 1);
				if (lis[k][i] > res[k][0])
				{
					res[k][0] = lis[k][i];
					res[k][1] = i;
				}
				j--;
				if (j < 0)
					j = stx->a_len + j;
			}
			i--;
			if (i == -1)
				i = stx->a_len - 1;

		}
		k++;
	}
	i = 0;
	j = 0;
	while (i < stx->a_len)
	{
		if (res[i][0] > res[j][0])
			j = i;
		i++;
	}
//	printf("res[0] %d   res[1]  %d   j %d\n", res[j][0], res[j][1], j);
	stx->lis = malloc(sizeof(int) * (res[j][0] + 1));
	stx->lis_len = res[j][0] + 1;
	i = res[j][1];
//	printf("res[0] %d\n", res[j][0]);
	k = 0;
	while (k < stx->lis_len)
	{
		if (i == stx->a_len)
			i = 0;
		if (lis[j][i] == stx->lis_len - k - 1)
		{	
		//	if (k > 0 && stx->a[i] < stx->lis[k - 1])
	//			k--;
			stx->lis[k++] = stx->a[i];
		}
		i++;
	}
//	print_arr(stx->a, stx->a_len);
//	print_arr(stx->lis, stx->lis_len);
	if (stx->lis_len < 2)
	{
		stx->lis_len = 2;
		stx->lis[0] = stx->sorted[0];
		stx->lis[1] = stx->sorted[1];
	}
}