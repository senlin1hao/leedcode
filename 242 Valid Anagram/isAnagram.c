#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
    {
        return false;
    }
    
    int count[26];
    memset(count, NULL, sizeof(count));

    int i = 0;
    while (s[i] != '\0')
    {
        ++count[s[i] - 'a'];
        ++i;
    }

    i = 0;
    while (t[i] != '\0')
    {
        --count[t[i] - 'a'];
        if (count[t[i] - 'a'] < 0)
        {
            return false;
        }
        ++i;
    }
    
    return true;
}