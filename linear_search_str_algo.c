#include <stdio.h>
#include <string.h>

int main(void)
{
    char *words[] = {"battleship", "boot", "canon",
    "iron", "thimble", "top hat"};
    char s[20];
    
    printf("Word: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(words[i], s) == 0)
        {
            printf("Found inside: words[%i]\n", i);
            return 0;
        }
    }
    puts("Not found");
    return 1;
}
