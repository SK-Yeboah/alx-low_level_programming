#include "lists.h"
#include <stdlib.h>



/**
 * get_list_len - Gets the length of a linked list
 * @head: A pointer to the first node
*/
size_t list_len(const list_t *h)
{
    size_t  length = 0;
   


    while (h != 0)
    {
        length ++; 
        h = h->next;
    }

    return (length);
}
