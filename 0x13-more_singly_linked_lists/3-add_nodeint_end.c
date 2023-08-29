#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nw;
	listint_t *temp = *head;

	nw = malloc(sizeof(listint_t));
	if (!nw)
		return (NULL);

	nw->n = n;
	nw->next = NULL;

	if (*head == NULL)
	{
		*head = nw;
		return (nw);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = nw;

	return (nw);
}

