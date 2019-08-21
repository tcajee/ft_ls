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

/* template */
/* constexpr const T& min (const T& a, const T& b, Compare comp); */
/* Here, a and b are the numbers to be compared. */
/* comp: Binary function that accepts two values of type T as arguments, */
/* and returns a value convertible to bool. The value returned indicates whether the */ 
/* element passed as first argument is considered less than the second. */
/* The function shall not modify any of its arguments. */
/* This can either be a function pointer or a function object. */
/* Returns: Smaller of the two values. */

/* int	ft_sort_min(t_flags *flags, t_info dir_a, t_info dir_b) */
/* { */
/* 	F(*flags & F_1, ft_print_def(flags, dirs[i])); */
/* 	_F(*flags & F_t, ft_print_lst(flags, dirs[i])); */
/* 	_F(*flags & F_u, ft_print_lst(flags, dirs[i])); */
/* 	return (1); */
/* } */

// this function sorts array from left index to
// to right index which is of size atmost F_r

/* void ft_sort_ins(t_info dirs[], int left, int right) */
/* { */
/* 	int i; */
/* 	int j; */
/* 	t_info temp; */
/* 	i = left + 1; */
/* 	while (i <= right) */
/* 	{ */
/* 		temp = dirs[i]; */
/* 		j = i - 1; */
/* 		while (dirs[j].name[0] > temp.name[0] && j >= left) */
/* 		{ */
/* 			dirs[j + 1].name = dirs[j].name; */
/* 			j--; */
/* 		} */
/* 		dirs[j + 1].name = temp.name; */
/* 		i++; */
/* 	} */
/* } */

/* // merge function merges the sorted runs */
/* void ft_sort_merge(t_info dirs[], int l, int m, int r) */
/* { */
/*     // original array is broken in two parts */
/*     // left and riight array */
/* 	int i; */
/* 	int j; */
/* 	int k; */
/* 	int len1; */
/* 	int len2; */
/* 	len1 = m - l + 1; */
/* 	len2 = r - m; */
/* 	t_info left[len1]; */
/* 	t_info right[len2]; */
/* 	i = 0; */
/*     while (i < len1) */
/* 	{ */
/* 		left[i] = dirs[l + i]; */
/* 		i++; */
/* 	} */
/* 	i = 0; */
/*     while (i < len2) */
/* 	{ */
/* 		right[i] = dirs[m + 1 + i]; */
/* 		i++; */
/* 	} */
/*     i = 0; */
/*     j = 0; */
/*     k = l; */
/*     // after comparing, we merge those two array */
/*     // in larger sub array */
/*     while (i < len1 && j < len2) */
/*     { */
/*         if (left[i].name <= right[j].name) */
/*         { */
/*             dirs[k] = left[i]; */
/*             i++; */
/*         } */
/*         else */
/*         { */
/*             dirs[k] = right[j]; */
/*             j++; */
/*         } */
/*         k++; */
/*     } */
/*     // copy remaining elements of left, if any */
/*     while (i < len1) */
/*     { */
/*         dirs[k] = left[i]; */
/*         k++; */
/*         i++; */
/*     } */
/*     // copy remaining element of right, if any */
/*     while (j < len2) */
/*     { */
/*         dirs[k] = right[j]; */
/*         k++; */
/*         j++; */
/*     } */
/* } */

/* // iterative Timsort function to sort the */
/* // array[0...n-1] (similar to merge sort) */
/* void ft_sort_tim(t_info dirs[], int n) */
/* { */
/* 	int i; */
/* 	t_info left; */
/* 	t_info mid; */
/* 	t_info right; */
/* 	int size; */
/* 	// Sort individual subarrays of size F_r */
/* 	i = 0; */
/*     while (i < n) // here n is actuall y the number of directories, used to find min) */
/* 	{ */
/*         ft_sort_ins(dirs, i, min((i+31), (n-1))); // min is the smallest value of the sort tpe */
/* 		i += F_r; */
/* 	} */
/*     // start merging from size F_r (or 32). It will merge */
/*     // to form size 64, then 128, 256 and so on .... */
/* 	size = F_r; */
/*     while (size < n) */
/*     { */
/*         // pick starting point of left sub array. We */
/*         // are going to merge arr[left..left+size-1] */
/*         // and arr[left+size, left+2*size-1] */
/*         // After every merge, we increase left by 2*size */
/* 		left = 0; */
/*         while (left < n) */
/*         { */
/*             // find ending point of left sub array */
/*             // mid+1 is starting point of right sub array */
/*             mid = left + size - 1; */
/*             right = min((left + 2*size - 1), (n-1)); // min is the smallest value of the sort type */
/*             // merge sub array arr[left.....mid] & */
/*             // arr[mid+1....right] */
/*             ft_sort_merge(dirs, left, mid, right); */
/*         	left += 2*size; */
/*         } */
/*     	size = 2 * size; */
/*     } */
/* } */

/* int	ft_sorts(t_flags *flags, t_info dirs[]) */
/* { */
/* 	ft_sort_tim(dirs, dirs[0].dirc); */
/* 	return (1); */
/* } */

/* {{{TITLE
 

const int RUN = 32; 
  
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
  
// utility function to print the Array 
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d  ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {5, 21, 7, 23, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Given Array is\n"); 
    printArray(arr, n); 
  
    timSort(arr, n); 
  
    printf("After Sorting Array is\n"); 
    printArray(arr, n); 
    return 0; 
} 
  	
 
 * }}} */


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


