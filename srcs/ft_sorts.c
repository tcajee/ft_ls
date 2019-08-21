/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 14:16:47 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 10:54:56 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/incs/libft.h"

int	ft_sort_lex(int argc, char **argv)
{
	if (argc && argv)
		return (1);
	return (1);
}

int	ft_sort_mtime(int argc, char **argv)
{
	if (argc && argv)
		return (1);
	return (1);
}

int	ft_sort_atime(int argc, char **argv)
{
	if (argc && argv)
		return (1);
	return (1);
}

int	ft_sort_rev(int argc, char **argv)
{
	if (argc && argv)
		return (1);
	return (1);
}

int	ft_sorts(int argc, char **argv)
{
	if (argc && argv)
		return (1);
	return (1);
}






const int RUN = 32;

// this function sorts array from left index to
// to right index which is of size atmost RUN
void ft_sort_ins(t_info dirs[], int left, int right)
{
	int i;
	int j;
	t_info temp;

	i = left + 1;
	while (i <= right)
	{
		temp = dirs[i];
		j = i - 1;
		while (dirs[j].name[0] > temp.name[0] && j >= left)
		{
			dirs[j + 1].name = dirs[j].name;
			j--;
		}
		dirs[j + 1].name = temp.name;
		i++;
	}
}

// merge function merges the sorted runs
void ft_sort_merge(t_info dirs[], int l, int m, int r)
{
    // original array is broken in two parts
    // left and riight array
	int i;
	int j;
	int k;
	int len1;
	int len2;

	len1 = m - l + 1;
	len2 = r - m;

	t_info left[len1];
	t_info right[len2];

	i = 0;
    while (i < len1)
	{
		left[i] = dirs[l + i];
		i++;
	}
	i = 0;
    while (i < len2)
	{
		right[i] = dirs[m + 1 + i];
		i++;
	}

    i = 0;
    j = 0;
    k = l;

    // after comparing, we merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i].name <= right[j].name)
        {
            dirs[k] = left[i];
            i++;
        }
        else
        {
            dirs[k] = right[j];
            j++;
        }
        k++;
    }

    // copy remaining elements of left, if any
    while (i < len1)
    {
        dirs[k] = left[i];
        k++;
        i++;
    }

    // copy remaining element of right, if any
    while (j < len2)
    {
        dirs[k] = right[j];
        k++;
        j++;
    }
}

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void ft_sort_tim(t_info dirs[], int n)
{
	int i;
	int left;
	int mid;
	int right;
	int size;
    // Sort individual subarrays of size RUN
	i = 0;
    while (i < n)
	{
        ft_sort_ins(dirs, i, min((i+31), (n-1)));
		i += RUN;
	}

    // start merging from size RUN (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
	size = RUN;
    while (size < n)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
		left = 0;
        while (left < n)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            mid = left + size - 1;
            right = min((left + 2*size - 1), (n-1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            ft_sort_merge(dirs, left, mid, right);
        	left += 2*size;
        }
    	size = 2 * size;
    }
}

// utility function to print the Array
void ft_sort_print(t_info dirs[], int n)
{
	int i;

	i = 0;
    while (i < n)
	{
        printf("%d  ", dirs[i]);
		i++;
	}
    printf("\n");
}

// Driver program to test above function
int main()
{
    t_info dirs[1024];
    int n;
    n = sizeof(dirs)/sizeof(dirs[0]);
    printf("Given Array is\n");
    ft_sort_print(dirs, n);

    ft_sort_tim(dirs, n);

    printf("After Sorting Array is\n");
    ft_sort_print(dirs, n);
    return 0;
}
