#include <stdio.h>
#include <string.h>

int main()
{
    char s[100], reverse[100];
    int i, j = 0;

    printf("Enter a string: ");
    scanf("%99s", s);

    i = strlen(s) - 1;

    while (i >= 0)
    {
        reverse[j] = s[i];
        j++;
        i--;
    }

    reverse[j] = '\0';

    if (strcmp(s, reverse) == 0)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
