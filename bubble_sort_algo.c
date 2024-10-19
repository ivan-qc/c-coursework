#include <stdio.h>

void array_info(int array[], int size);
void sort(int array[], int size);

int main(void)
{
    // Unsorted array
    int grades[] = {9, 7, 3, 8, 10, 1, 6, 2, 0};
    // Calculate number of elements
    int elements = sizeof(grades) / sizeof(grades[0]);
    // Unsorted print
    array_info(grades, elements);
    // Sort
    sort(grades, elements);
    // Sorted print
    array_info(grades, elements);

    return 0;
}

// Print function
void array_info(int array[], int size)
{
    printf("\n");
    printf("This array has %d elements:\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("[%i]", array[i]);
    }
    printf("\n");
}

// Bubble sort function
void sort(int array[], int size)
{
    int holder;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                holder = array[j];
                array[j] = array[j+1];
                array[j+1] = holder;
            }
        }
    }
}
