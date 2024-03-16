#include "search_algos.h"
/**
 * linear_search - searches for a value in an array of integers using linear search
 * @array: A pointer to the first element in the element
 * @size: The number of element in an  array
 * @value:  The value to search for
 * 
 * Return: The first index where the value is located  or -1 if the value is not found
*/

int linear_search (int *array, size_t size, int value){
    size_t i = 0;
    if(array == NULL){
        return -1;
    }

    for( i = 0; i < size; i++){
        printf("Value checked array[%lu] = [%d]\n", i , array[i]);
        if(array[i] == value){
            return 1;
        }

    }

    return -1;
}