#include"lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - add a node at end of a linkded list
 * @head: Double pointer to the list_t
 * @str: A  new string to add
 *
 * Return: The address of the new element
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp = *head;
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
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = new;
	return (new);
}
