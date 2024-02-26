#include <stdio.h>

void show_bits(int n);

int main(void)
{
    int i;
    printf("Number: ");
    scanf("%d", &i);
    
    show_bits(i);
    return 0;
}

void show_bits(int n)
{
    printf("Binary: ");
    for (int bit = 31; bit >= 0; bit--)
    {
        printf("%d", (n >> bit) & 1);
    }
    puts("");
}
