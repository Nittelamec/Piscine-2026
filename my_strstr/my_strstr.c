#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    if (!needle || needle[0] == '\0')
        return 0;
    else
    {
        int i = 0;
        int j = 0;
        int n = 0;
        while (haystack[i] != '\0')
        {
            if (needle[j] == '\0')
                return i - n;
            else if (haystack[i] == needle[j])
            {
                i++;
                j++;
                n++;
            }
            else
            {
                if (n > 0)
                {
                    while (j >= 0 && haystack[i] != needle[j])
                    {
                        j--;
                        n--;
                    }
                    if (j < 0)
                    {
                        j = 0;
                        n = 0;
                        i++;
                    }
                }
                else
                    i++;
            }
        }
        return (needle[j] == '\0') ? i - n : -1;
    }
}
