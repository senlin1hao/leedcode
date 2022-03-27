#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26];
        memset(count, 0, sizeof(int) * 26);
        for (char c : magazine)
        {
            count[c - 'a']++;
        }
        for (char c : ransomNote)
        {
            count[c - 'a']--;
            if (count[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};