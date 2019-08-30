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

/* // merge function merges the sorted runs */
/* void ft_sort_merge(int *flags, t_dirs *dirs, int l, int m, int r) */
/* { */
/*     // original array is broken in two parts */
/*     // left and riight array */
/* 	int i; */
/* 	int j; */
/* 	int k; */
/* 	int len1; */
/* 	int len2; */
/* 	(void)flags; */
/* 	/1* ft_putendl("merge"); *1/ */
/* 	len1 = m - l + 2; */
/* 	len2 = r - m; */
/* 	t_info left[len1]; */
/* 	t_info right[len2]; */
/* 	i = 0; */
/* 	/1* ft_putendl("left"); *1/ */
/*     while (i < len1) */
/* 	{ */
/* 		left[i] = dirs->list[l + i]; */
/* 		i++; */
/* 	} */
/* 	i = 0; */
/* 	/1* ft_putendl("right"); *1/ */
/*     while (i < len2) */
/* 	{ */
/* 		right[i] = dirs->list[m + 1 + i]; */
/* 		i++; */
/* 	} */
/*     i = 0; */
/*     j = 0; */
/*     k = l; */
/*     // after comparing, we merge those two array */
/*     // in larger sub array */
/* 	/1* ft_putendl("merge:left right"); *1/ */
/*     while (i < len1 && j < len2) */
/*     { */
/*         /1* if (ft_sort_comp(flags, dirs->list, i, j) <= 0) *1/ */
/*         { */
/*             dirs->list[k] = left[i]; */
/*             i++; */
/*         } */
/*         /1* else // if (ft_sort_comp(flags, dirs, i, j) < 0) *1/ */
/*         { */
/*             dirs->list[k] = right[j]; */
/*             j++; */
/*         } */
/*         k++; */
/*     } */
/*     // copy remaining elements of left, if any */
/* 	/1* ft_putendl("copy: left"); *1/ */
/*     while (i < len1) */
/*     { */
/*         dirs->list[k] = left[i]; */
/*         k++; */
/*         i++; */
/*     } */
/*     // copy remaining element of right, if any */
/* 	/1* ft_putendl("copy: right"); *1/ */
/*     while (j < len2) */
/*     { */
/*         dirs->list[k] = right[j]; */
/*         k++; */
/*         j++; */
/*     } */
/* } */


/* void ft_sort_ins(int *flags, t_dirs *dirs, t_info *left, t_info *right) */
/* { */
/* 	t_info  *i; */
/* 	t_info *j; */
/* 	t_info *temp; */
/* 	t_info *list; */
/* 	/1* ft_putendl("ins"); *1/ */
/* 	i = left->next; */
/* 	list = dirs->list; */
/* 	while (list != right) */
/* 	{ */
/* 		temp = i; */
/* 		j = i->prev; */
/* 		while (j != left && ft_sort_comp(flags, dirs, i, j) > 0) */
/* 		{ */
/* 			/1* dirs[j + 1] = dirs[j]; *1/ */
/* 			j = j->prev; */
/* 		} */
/* 		/1* dirs[j + 1] = temp; *1/ */
/* 		i++; */
/* 	} */
/* } */
/* t_info	*ft_sort_comp(int *flags, t_dirs *dirs, t_info *i, t_info *j) */
/* { */
/* 	(void)flags; */
/* 	/1* ft_putstr("comp:	"); *1/ */
/* 	/1* ft_putstr("["); *1/ */
/* 	/1* ft_putnbr(i); *1/ */
/* 	/1* ft_putstr("]"); *1/ */
/* 	/1* ft_putstr("	"); *1/ */
/* 	/1* ft_putstr(dirs[i].name); *1/ */
/* 	/1* ft_putstr("	"); *1/ */
/* 	/1* ft_putstr("["); *1/ */
/* 	/1* ft_putnbr(j); *1/ */
/* 	(void)dirs; */
/* 	/1* ft_putstr("]"); *1/ */
/* 	/1* ft_putstr("	"); *1/ */
/* 	/1* ft_putstr(dirs[j].name); *1/ */
/* 	/1* ft_putstr("	"); *1/ */
/* 	/1* ft_putstr(dirs[i].name); *1/ */
/* 	/1* ft_putstr("		"); *1/ */
/* 	/1* ft_putstr(dirs[j].name); *1/ */
/* 	/1* ft_putendl(""); *1/ */
/* 	/1* ft_putendl(""); *1/ */
/* 	if (!i) */
/* 		return (j); */
/* 	if (!j) */
/* 		return (i); */
/* 	int cmp = 0; */
/* 	if ((cmp = ft_strcmp(i->name, j->name)) > 0) */
/* 	{ */
/* 		/1* ft_putstr("["); *1/ */
/* 		/1* ft_putnbr(cmp); *1/ */
/* 		/1* ft_putstr("]"); *1/ */
/* 		/1* ft_putstr("	"); *1/ */
/* 		/1* ft_putstr("["); *1/ */
/* 		/1* ft_putnbr(j); *1/ */
/* 		/1* ft_putstr("]"); *1/ */
/* 		/1* ft_putendl(""); *1/ */
/* 		return (j); */
/* 	} */
/* 	else if ((cmp = ft_strcmp(i->name, j->name)) < 0) */
/* 	{ */
/* 		/1* ft_putstr("["); *1/ */
/* 		/1* ft_putnbr(cmp); *1/ */
/* 		/1* ft_putstr("]"); *1/ */
/* 		/1* ft_putstr("	"); *1/ */
/* 		/1* ft_putstr("["); *1/ */
/* 		/1* ft_putnbr(i); *1/ */
/* 		/1* ft_putstr("]"); *1/ */
/* 		/1* ft_putendl(""); *1/ */
/* 		return (i); */
/* 	} */
/* 	/1* ft_putstr("["); *1/ */
/* 	/1* ft_putnbr(cmp); *1/ */
/* 	/1* ft_putstr("]"); *1/ */
/* 	/1* ft_putstr("	"); *1/ */
/* 	/1* ft_putstr("["); *1/ */
/* 	/1* ft_putnbr(j); *1/ */
/* 	/1* ft_putstr("]"); *1/ */
/* 	/1* ft_putendl(""); *1/ */
/* 	return (j); */
/* } */


int	ft_pow2(int n)
{
	while (n--)
		if ((n & (-n)) == n)
			return (n);
	return (n);
}

// iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void ft_sort_tim(int *flags, t_dirs *dirs, int size)
{
	t_info *list;
	int run;
	
	/* ft_putstr("tim	"); */
	// Sort individual subarrays of size F_u 
	if (ft_pow2(size) == size)
		run = size / 2;
	else 
		run = ft_pow2(size);
	
	/* ft_putstr("["); */
	/* ft_putnbr(size); */
	/* ft_putstr("]"); */
	/* ft_putendl(""); */

	list = dirs->list;
    while ( list->i < dirs->size - run) // here n is actuall y the number of directories, used to find min)
	{
        


		ft_sort_ins(flags, dirs, list, ft_sort_comp(flags, dirs, dirs->array[list->i + run - 1], dirs->array[size - 1]));

		list = dirs->array[list->i + run];
	}
    
	
	
	t_info *left;
	t_info *mid;
	t_info *right;

	
	// start merging from size F_u (or 32). It will merge
    // to form size 64, then 128, 256 and so on ....
    
	
	
	while (run < size)
    {
        // pick starting point of left sub array. We
        // are going to merge arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we increase left by 2*size
		left = dirs->size;
        while (left + 2 * run < size)
        {
            // find ending point of left sub array
            // mid+1 is starting point of right sub array
            mid = left + run - 1;
			ft_putendl(dirs[left + 2 * run - 1].name);
			ft_putendl(dirs[size - 1].name);
    


			/* right = ft_sort_comp(flags, dirs, left + 2 * run - 1, size - 1); */ 
            


			// merge sub array arr[left.....mid] &
            // arr[mid+1....right]
           ft_sort_merge(flags, dirs, left, mid, right);
        	left += 2 * run;
        }
    	run = 2 * run;
    }



}

using namespace std; 
  
// Node of a doubly linked list 
struct Node { 
    int data; 
    struct Node* prev, *next; 
}; 
  
// function to create and return a new node 
// of a doubly linked list 
struct Node* getNode(int data) 
{ 
    // allocate node 
    struct Node* newNode =  
          (struct Node*)malloc(sizeof(struct Node)); 
  
    // put in the data 
    newNode->data = data; 
    newNode->prev = newNode->next = NULL; 
    return newNode; 
} 
  
// function to insert a new node in sorted way in 
// a sorted doubly linked list 
void sortedInsert(struct Node** head_ref, struct Node* newNode) 
{ 
    struct Node* current; 
  
    // if list is empty 
    if (*head_ref == NULL) 
        *head_ref = newNode; 
  
    // if the node is to be inserted at the beginning 
    // of the doubly linked list 
    else if ((*head_ref)->data >= newNode->data) { 
        newNode->next = *head_ref; 
        newNode->next->prev = newNode; 
        *head_ref = newNode; 
    } 
  
    else { 
        current = *head_ref; 
  
        // locate the node after which the new node 
        // is to be inserted 
        while (current->next != NULL &&  
               current->next->data < newNode->data) 
            current = current->next; 
  
        /*Make the appropriate links */
  
        newNode->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            newNode->next->prev = newNode; 
  
        current->next = newNode; 
        newNode->prev = current; 
    } 
} 
  
// function to sort a doubly linked list using insertion sort 
void insertionSort(struct Node** head_ref) 
{ 
    // Initialize 'sorted' - a sorted doubly linked list 
    struct Node* sorted = NULL; 
  
    // Traverse the given doubly linked list and 
    // insert every node to 'sorted' 
    struct Node* current = *head_ref; 
    while (current != NULL) { 
  
        // Store next for next iteration 
        struct Node* next = current->next; 
  
        // removing all the links so as to create 'current' 
        // as a new node for insertion 
        current->prev = current->next = NULL; 
  
        // insert current in 'sorted' doubly linked list 
        sortedInsert(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted doubly linked list 
    *head_ref = sorted; 
} 
  
// function to print the doubly linked list 
void printList(struct Node* head) 
{ 
    while (head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
} 
  
// function to insert a node at the beginning of 
// the doubly linked list 
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
         (struct Node*)malloc(sizeof(struct Node)); 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  
    /* change prev of head node to new node */
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
// Driver program to test above 
int main() 
{ 
    /* start with the empty doubly linked list */
    struct Node* head = NULL; 
  
    // insert the following data 
    push(&head, 9); 
    push(&head, 3); 
    push(&head, 5); 
    push(&head, 10); 
    push(&head, 12); 
    push(&head, 8); 
  
    cout << "Doubly Linked List Before Sortingn"; 
    printList(head); 
  
    insertionSort(&head); 
  
    cout << "nDoubly Linked List After Sortingn"; 
    printList(head); 
  
    return 0; 
} 
Java
filter_none
edit
play_arrow

brightness_4
// Java implementation for insertion Sort  
// on a doubly linked list  
class Solution 
{ 
  
// Node of a doubly linked list  
static class Node  
{  
    int data;  
    Node prev, next;  
};  
  
// function to create and return a new node  
// of a doubly linked list  
static Node getNode(int data)  
{  
    // allocate node  
    Node newNode = new Node(); 
  
    // put in the data  
    newNode.data = data;  
    newNode.prev = newNode.next = null;  
    return newNode;  
}  
  
// function to insert a new node in sorted way in  
// a sorted doubly linked list  
static Node sortedInsert(Node head_ref, Node newNode)  
{  
    Node current;  
  
    // if list is empty  
    if (head_ref == null)  
        head_ref = newNode;  
  
    // if the node is to be inserted at the beginning  
    // of the doubly linked list  
    else if ((head_ref).data >= newNode.data) 
    {  
        newNode.next = head_ref;  
        newNode.next.prev = newNode;  
        head_ref = newNode;  
    }  
  
    else
    {  
        current = head_ref;  
  
        // locate the node after which the new node  
        // is to be inserted  
        while (current.next != null &&  
            current.next.data < newNode.data)  
            current = current.next;  
  
        //Make the appropriate links / 
  
        newNode.next = current.next;  
  
        // if the new node is not inserted  
        // at the end of the list  
        if (current.next != null)  
            newNode.next.prev = newNode;  
  
        current.next = newNode;  
        newNode.prev = current;  
    }  
    return head_ref; 
}  
  
// function to sort a doubly linked list using insertion sort  
static Node insertionSort(Node head_ref)  
{  
    // Initialize 'sorted' - a sorted doubly linked list  
    Node sorted = null;  
  
    // Traverse the given doubly linked list and  
    // insert every node to 'sorted'  
    Node current = head_ref;  
    while (current != null) 
    {  
  
        // Store next for next iteration  
        Node next = current.next;  
  
        // removing all the links so as to create 'current'  
        // as a new node for insertion  
        current.prev = current.next = null;  
  
        // insert current in 'sorted' doubly linked list  
        sorted=sortedInsert(sorted, current);  
  
        // Update current  
        current = next;  
    }  
  
    // Update head_ref to point to sorted doubly linked list  
    head_ref = sorted; 
      
    return head_ref; 
}  
  
// function to print the doubly linked list  
static void printList(Node head)  
{  
    while (head != null)  
    {  
        System.out.print(head.data + " ");  
        head = head.next;  
    }  
}  
  
// function to insert a node at the beginning of  
// the doubly linked list  
static Node push(Node head_ref, int new_data)  
{  
    // allocate node / 
    Node new_node = new Node();  
  
    // put in the data / 
    new_node.data = new_data;  
  
    // Make next of new node as head and previous as null / 
    new_node.next = (head_ref);  
    new_node.prev = null;  
  
    // change prev of head node to new node / 
    if ((head_ref) != null)  
        (head_ref).prev = new_node;  
  
    // move the head to point to the new node / 
    (head_ref) = new_node; 
      
    return head_ref; 
}  
  
// Driver code  
public static void main(String args[]) 
{  
    // start with the empty doubly linked list / 
    Node head = null;  
  
    // insert the following data  
    head=push(head, 9);  
    head=push(head, 3);  
    head=push(head, 5);  
    head=push(head, 10);  
    head=push(head, 12);  
    head=push(head, 8);  
  
    System.out.println( "Doubly Linked List Before Sorting\n");  
    printList(head);  
  
    head=insertionSort(head);  
  
    System.out.println("\nDoubly Linked List After Sorting\n");  
    printList(head);  
  
}  
} 
  



void	ft_sorts(int *flags, t_dirs *dirs)
{

	/* ft_putstr("sorts	"); */
	/* ft_putstr("["); */
	/* ft_putnbr(dirs[0].dirc - 1); */
	/* ft_putstr("]"); */
	/* ft_putendl(""); */


	ft_sort_tim(flags, dirs, dirs->size);

}

/* {{{TITLEzo
 

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

