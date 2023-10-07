#include "main.h"



/**
 * get_list_len - Gets the length of a linked list
 * @head: A pointer to the first node
*/
size_t get_list_len(list_t *head)
{
    size_t  length = 0;
    list_T *current = head;


    while (current != 0)
    {
        length ++; 
        current = current->next;
    }

    return (length);
}
