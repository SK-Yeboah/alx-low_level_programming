#include "lists.h"
#include <stdlib.h>

/**
 * list_len - Gets the length of a linked list
 * @h: A pointer to the first node
 *
 * Return: The number of the elements in the list
*/
size_t list_len(const list_t *h)
{
	size_t  length = 0;

	while (h != 0)
	{
		length++;
		h = h->next;
	}

	return (length);
}
