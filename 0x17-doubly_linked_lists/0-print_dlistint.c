#include "lists.h"

/**
 * print_dlistint - Prints all element in a linkedlist dlistint
 * @h: Pointer to start the linkedlist 
 * 
 * Return: Return number of nodes
*/

size_t print_dlistint(const dlistint_t *h)
{
    size_t i;

    for(i =  0; h != NULL; i++)
    {
        printf("%d\n",h->n);
        h = h->next;
    }

    return (i);
}