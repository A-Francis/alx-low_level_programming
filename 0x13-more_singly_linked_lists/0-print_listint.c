#include "lists.h"

/**
 * print_listint- prints the elements of a linked list
 * @h:listint_t list to print
 * Return:number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h != NULL)
	{
	printf("%d -> ", h->n); /*Print the data of the current node*/
	h = h->next; /* Move to the next node*/
	num++; /*Increment the count*/
	}
	return (num);
}