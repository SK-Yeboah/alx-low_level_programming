#include "search_algos.h"
/**
 * jump_search - searches for a value in an array of integers using jump_search
 * @array: A pointer to the first element in the element
 * @size: The number of element in an  array
 * @value:  The value to search for
 * 
 * Return: The first index where the value is located  or -1 if the value is not found
*/

int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size);
    size_t prev = 0;

    if (array == NULL)
        return (-1);

    while (array[prev] < value && prev < size)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);

        prev += step;

        if (prev >= size)
            break;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

    prev -= step;

    for (size_t i = prev; i <= prev + step && i < size; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);

        if (array[i] == value)
            return (i);
    }

    return (-1);
}