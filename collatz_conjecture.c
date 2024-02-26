#include <stdio.h>

int collatz(int number);

int main(void)
{
    int n;
    
    puts(" *** The Collatz conjecture *** ");
    printf("Number: ");
    scanf("%d", &n);

    printf("Collatz: %d\n", collatz(n));

    return 0;
}

int collatz(int number)
{

    if (number == 1)
        return 0;
    else if ((number % 2) == 0)
        return 1 + collatz(number / 2);
    else
        return 1 + collatz(3 * number + 1);
}
