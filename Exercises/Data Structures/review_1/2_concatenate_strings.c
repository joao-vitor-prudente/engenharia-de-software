#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char *s1, char *s2, char sep);

int main(int argc, char const *argv[])
{
    char s1[255];
    char s2[255];
    char sep;
    printf("Enter the first word: \n");
    fgets(s1, sizeof(s1), stdin);
    if (s1 == NULL)
    {
        printf("Error: Could not read terminal.");
        return -1;
    }
    s1[strcspn(s1, "\n")] = 0;
    printf("Enter the second word: \n");
    fgets(s2, sizeof(s2), stdin);
    if (s2 == NULL)
    {
        printf("Error: Could not read terminal.");
        return -1;
    }
    s2[strcspn(s2, "\n")] = 0;
    printf("Enter the separator: \n");
    scanf("%c", &sep);

    char *s = concat(s1, s2, sep);
    if (s == NULL)
    {
        printf("Error: Could not allocate memory.");
        return -1;
    }

    printf("\n%s\n", s);
    free(s);
    return 0;
}

char *concat(char *s1, char *s2, char sep)
{
    printf("len s1 = %ld\n", strlen(s1));
    printf("len s2 = %ld\n", strlen(s2));
    char *s = (char *)malloc((strlen(s1) + strlen(s2) + 1) *sizeof(char));
    printf("len s = %ld\n", strlen(s));
    if (s == NULL)
    {
        return NULL;
    }

    int s_index = 0;

    for (size_t i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '\0')
        {
            continue;
        }
        
        s[s_index] = s1[i];
        s_index++;
    }
    s[s_index] = sep;
    s_index++;

    for (size_t i = 0; i < strlen(s2); i++)
    {
        if (s2[i] == '\0')
        {
            continue;
        }
        
        s[s_index] = s2[i];
        s_index++;
    }
    return s;
}