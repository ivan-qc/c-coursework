#include <stdio.h>

void array_info(int array[], int size);
void sort(int array[], int size);

int main(void)
{
    // Array
    int grades[] = {9, 7, 3, 8, 10, 1, 6, 2, 0};
    int elements = sizeof(grades) / sizeof(grades[0]);
    // Unsorted print
    array_info(grades, elements);
    // Sorting call
    sort(grades, elements);
    // Sorted print
    array_info(grades, elements);

    return 0;
}

// Prints info
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

// Sorting function (Bubble sort)
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
