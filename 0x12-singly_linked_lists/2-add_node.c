#include "lists.h"
#include <string.h>
#include <stdlib.h>
/**
 * add_node - add a new noode at the beginning of a linked list.
 * @head: Double pointer to the list_t list.
 * @str: New string to add to the in the node.
 *
 * Return: Return the address of the new element, or NUL if it fails.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int length = 0;
	
	while (str[length])
	{
		length++;
	}


	new = malloc(sizeof(list_t));

	if (!new)
	{
		return (NULL);
	}

	new->str = strdup(str);
	new->len = length;
	new->next = (*head);
	(*head) = new;

	return (*head);
}
