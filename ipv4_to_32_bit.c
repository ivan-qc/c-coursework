#include <stdio.h>

int main(void)
{
	unsigned long a = 0, b = 0, c = 0, d = 0, ip = 0;

    scanf("%lu", &a); scanf("%lu", &b); scanf("%lu", &c); scanf("%lu", &d);

    if (a >= 0 && a <= 256 && b >= 0 && b <= 256 && c >= 0 && c <= 256 && d >= 0 && d <= 256) 
    {
        ip = ((a*256*256*256) + (b*256*256) + (c*256) + d);
        printf("Human-readable IP address is: %lu.%lu.%lu.%lu\n", a, b, c, d);
        printf("IP address as a 32-bit number: %lu\n", ip);
        return 0;
    }
    else
	    puts("Incorrect IP Address.");
        return 1;
}
