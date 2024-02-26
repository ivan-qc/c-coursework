#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int n;
    printf("Number: ");
    scanf("%d", &n);

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found inside: numbers[%i]\n", i);
            return 0;
        }
    }
    puts("Not found");
    return 1;
}
