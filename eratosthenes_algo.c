#include <stdio.h>

int main(void)
{
    int smallest_prime = 2;
    int max = 100;

    int arr[max];

    for (int i = 0; i < max; i++)
    {
        arr[i] = smallest_prime;
        smallest_prime++;
    }

    for (int i = 0; i * i <= max - 2; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = 2 * arr[i]; j <= max; j += arr[i])
                arr[j - 2] = 0;
        }
    }

    /* Prints the primes numbers */
    for (int i = 0; i < max - 1; i++)
    {
        if (arr[i] != 0)
            printf("[%d]\n", arr[i]);
    }
    return 0;
}
