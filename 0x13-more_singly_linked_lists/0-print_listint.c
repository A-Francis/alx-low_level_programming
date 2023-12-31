#include "lists.h"

/**
 * print_listint- prints the elements of a linked list
 * @h:listint_t list to print
 * Return:number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
	printf("%d\n", h->n);
	h = h->next; /* Move to the next node*/
	num++; /*Increment the count*/
	}
	return (num);
}
