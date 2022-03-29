#include <stdio.h>

void reverseString(char *s, int sSize)
{
    char c;
    int left = 0;
    int right = sSize - 1;
    while (left < right)
    {
        c = s[left];
        s[left] = s[right];
        s[right] = c;

        ++left;
        --right;
    }
    return;
}