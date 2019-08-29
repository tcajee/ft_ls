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

/* int	ft_sort_lex(int argc, char **argv) */
/* { */
/* 	if (argc && argv) */
/* 		return (1); */
/* 	return (1); */
/* } */

/* int	ft_sort_mtime(int argc, char **argv) */
/* { */
/* 	if (argc && argv) */
/* 		return (1); */
/* 	return (1); */
/* } */

/* int	ft_sort_atime(int argc, char **argv) */
/* { */
/* 	if (argc && argv) */
/* 		return (1); */
/* 	return (1); */
/* } */

// merge function merges the sorted runs
void ft_sort_merge(int *flags, t_info *list, int l, int m, int r)
{
    // original array is broken in two parts
    // left and riight array
	int i;
	int j;
	int k;
	int len1;
	int len2;

	/* ft_putendl("merge"); */
	len1 = m - l + 2;
	len2 = r - m;

	t_info left[len1];
	t_info right[len2];
	
	i = 0;
	/* ft_putendl("left"); */
    while (i < len1)
	{
		left[i] = list[l + i];
		i++;
	}
	i = 0;
	/* ft_putendl("right"); */
    while (i < len2)
	{
		right[i] = list[m + 1 + i];
		i++;
	}
    i = 0;
    j = 0;
    k = l;
    // after comparing, we merge those two array
    // in larger sub array
	/* ft_putendl("merge:left right"); */
    while (i < len1 && j < len2)
    {
        if (ft_sort_comp(flags, list, i, j) <= 0)
        {
            list[k] = left[i];
            i++;
        }
        else // if (ft_sort_comp(flags, dirs, i, j) < 0)
        {
            list[k] = right[j];
            j++;
        }
        k++;
    }
    // copy remaining elements of left, if any
	/* ft_putendl("copy: left"); */
    while (i < len1)
    {
        list[k] = left[i];
        k++;
        i++;
    }
    // copy remaining element of right, if any
	/* ft_putendl("copy: right"); */
    while (j < len2)
    {
        list[k] = right[j];
        k++;
        j++;
    }
}


void ft_sort_ins(int *flags, t_info dirs[], int left, int right)
{
	int i;
	int j;
	t_info temp;

	/* ft_putendl("ins"); */
	i = left + 1;
	while (i <= right)
	{
		temp = dirs[i];
		j = i - 1;
		while (j >= left && ft_sort_comp(flags, dirs, i, j) > 0)
		{
			dirs[j + 1] = dirs[j];
			j--;
		}
		dirs[j + 1] = temp;
		i++;
	}
}

int	ft_sort_comp(int *flags, t_info *list, int i, int j)
{
	(void)flags;

	/* ft_putstr("comp:	"); */
	/* ft_putstr("["); */
	/* ft_putnbr(i); */
	/* ft_putstr("]"); */
	/* ft_putstr("	"); */
	/* ft_putstr(dirs[i].name); */
	/* ft_putstr("	"); */
	/* ft_putstr("["); */
	/* ft_putnbr(j); */
	/* ft_putstr("]"); */
	/* ft_putstr("	"); */
	/* ft_putstr(dirs[j].name); */
	/* ft_putstr("	"); */
	
	/* ft_putstr(dirs[i].name); */
	/* ft_putstr("		"); */
	/* ft_putstr(dirs[j].name); */
	/* ft_putendl(""); */
	/* ft_putendl(""); */

	int cmp = 0;
	
	if ((cmp = ft_strcmp(list->name, list->name)) > 0)
	{

		/* ft_putstr("["); */
		/* ft_putnbr(cmp); */
		/* ft_putstr("]"); */
		/* ft_putstr("	"); */
		/* ft_putstr("["); */
		/* ft_putnbr(j); */
		/* ft_putstr("]"); */
		/* ft_putendl(""); */
		
		return (j);
	}
	else if ((cmp = ft_strcmp(list->name, list->name)) < 0)
	{

		/* ft_putstr("["); */
		/* ft_putnbr(cmp); */
		/* ft_putstr("]"); */
		/* ft_putstr("	"); */
		/* ft_putstr("["); */
		/* ft_putnbr(i); */
		/* ft_putstr("]"); */
		/* ft_putendl(""); */

		return (i);
	}

	/* ft_putstr("["); */
	/* ft_putnbr(cmp); */
	/* ft_putstr("]"); */
	/* ft_putstr("	"); */
	/* ft_putstr("["); */
	/* ft_putnbr(j); */
	/* ft_putstr("]"); */
	/* ft_putendl(""); */

	return (j);
}


int	ft_pow2(int n)
{
	while (n--)
		if ((n & (-n)) == n)
			return (n);
	return (n);
}

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void ft_sort_tim(int *flags, t_info *list, int n)
{
	int i;
	int size;
	
	/* ft_putstr("tim	"); */
	// Sort individual subarrays of size F_u 
	if (ft_pow2(n) == n)
		size = n / 2;
	else 
		size = ft_pow2(n);
	
	/* ft_putstr("["); */
	/* ft_putnbr(size); */
	/* ft_putstr("]"); */
	/* ft_putendl(""); */

	i = 1;
    while (i + size < n) // here n is actuall y the number of directories, used to find min)
	{
        ft_sort_ins(flags, list, i, ft_sort_comp(flags, list, i + size - 1, n - 1));
		i += size;
	}
    
	
	
	/* int left; */
	/* int mid; */
	/* int right; */

	
	
	// start merging from size F_u (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    
	
	
	/* while (size < n) */
    /* { */
        /* // pick starting point of left sub array. We */
        /* // are going to merge arr[left..left+size-1] */
        /* // and arr[left+size, left+2*size-1] */
        /* // After every merge, we increase left by 2*size */
	/* 	left = 0; */
        /* while (left + 2 * size < n) */
        /* { */
            /* // find ending point of left sub array */
            /* // mid+1 is starting point of right sub array */
            /* mid = left + size - 1; */
	/* 		ft_putendl(dirs[left + 2 * size - 1].name); */
	/* 		ft_putendl(dirs[n - 1].name); */
            /* right = ft_sort_comp(flags, dirs, left + 2 * size - 1, n - 1); */ 
            /* // merge sub array arr[left.....mid] & */
            /* // arr[mid+1....right] */
           /* ft_sort_merge(flags, dirs, left, mid, right); */
        	/* left += 2 * size; */
        /* } */
    	/* size = 2 * size; */
    /* } */



}


void	ft_sorts(int *flags, t_dirs *dirs)
{

	/* ft_putstr("sorts	"); */
	/* ft_putstr("["); */
	/* ft_putnbr(dirs[0].dirc - 1); */
	/* ft_putstr("]"); */
	/* ft_putendl(""); */


	ft_sort_tim(flags, dirs->list, dirs->size);

}

/* {{{TITLE
 

const int RUN = 32 =  F_u
  
// this function sorts array from left index to 
// to right index which is of size atmost RUN 
void insertionSort(int arr[], int left, int right) 
{ 
    for (int i = left + 1; i <= right; i++) 
    { 
        int temp = arr[i]; 
        int j = i - 1; 
        while (arr[j] > temp && j >= left) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 
  
// merge function merges the sorted runs 
void merge(int arr[], int l, int m, int r) 
{ 
    // original array is broken in two parts 
    // left and right array 
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 
    for (int i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (int i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    int i = 0; 
    int j = 0; 
    int k = l; 
  
    // after comparing, we merge those two array 
    // in larger sub array 
    while (i < len1 && j < len2) 
    { 
        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // copy remaining elements of left, if any 
    while (i < len1) 
    { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    // copy remaining element of right, if any 
    while (j < len2) 
    { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
} 
  
// iterative Timsort function to sort the 
// array[0...n-1] (similar to merge sort) 
void timSort(int arr[], int n) 
{ 
    // Sort individual subarrays of size RUN 
    for (int i = 0; i < n; i+=RUN) 
        insertionSort(arr, i, min((i+31), (n-1))); 
  
    // start merging from size RUN (or 32). It will merge 
    // to form size 64, then 128, 256 and so on .... 
    for (int size = RUN; size < n; size = 2*size) 
    { 
        // pick starting point of left sub array. We 
        // are going to merge arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge, we increase left by 2*size 
        for (int left = 0; left < n; left += 2*size) 
        { 
            // find ending point of left sub array 
            // mid+1 is starting point of right sub array 
            int mid = left + size - 1; 
            int right = min((left + 2*size - 1), (n-1)); 
  
            // merge sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            merge(arr, left, mid, right); 
        } 
    } 
} 
  
 * }}} */
