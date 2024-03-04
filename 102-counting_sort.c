#include "sort.h"

/**
 * get_maximum - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_maximum(int *array, int size)
{
    int maximum_value = array[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > maximum_value)
            maximum_value = array[i];
    }

    return maximum_value;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    int *counts, *sorted, maximum_value, i;

    if (array == NULL || size < 2)
        return;

    sorted = malloc(sizeof(int) * size);
    if (sorted == NULL)
        return;
    maximum_value = get_maximum(array, size);
    counts = malloc(sizeof(int) * (maximum_value + 1));
    if (counts == NULL)
    {
        free(sorted);
        return;
    }

    for (i = 0; i < (maximum_value + 1); i++)
        counts[i] = 0;
    for (i = 0; i < (int)size; i++)
        counts[array[i]] += 1;
    for (i = 1; i < (maximum_value + 1); i++)
        counts[i] += counts[i - 1];
    print_array(counts, maximum_value + 1);

    for (i = (int)size - 1; i >= 0; i--)
    {
        sorted[counts[array[i]] - 1] = array[i];
        counts[array[i]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(counts);
}
