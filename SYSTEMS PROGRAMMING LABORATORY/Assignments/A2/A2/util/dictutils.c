/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <dictutils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addbefore(dict D, char *s)
{ // uses triesearch to check for single character which can be added before the given string
    char *ans = (char *)malloc(sizeof(char) * 27);
    int i, j = 0;
    char newstr[100];
    for (i = 0; i <= strlen(s); i++)
    {
        newstr[i + 1] = s[i];
    }

    for (i = 0; i < 26; i++)
    {
        newstr[0] = 'a' + i;
        if (triesearch(D, newstr))
        {
            ans[j++] = 'a' + i;
        }
    }
    ans[j] = '\0';
    return ans;
}

char *addafter(dict D, char *s)
{ // uses triesearch to check for single character which can be added after the given string
    char *ans = (char *)malloc(sizeof(char) * 27);
    int i, j = 0, k;
    char newstr[100];
    for (i = 0; i < strlen(s); i++)
    {
        newstr[i] = s[i];
    }
    newstr[i + 1] = '\0';

    for (k = 0; k < 26; k++)
    {
        newstr[i] = 'a' + k;
        if (triesearch(D, newstr))
        {
            ans[j++] = 'a' + k;
        }
    }
    ans[j] = '\0';
    return ans;
}

char **anagrams(dict D, char *s)
{ // generates permutaions of given string and uses triesearch to check if it exists in the given dictionary
    int n = strlen(s);
    char string[20];
    strcpy(string, s);
    char temp;
    char **answer = (char **)malloc(sizeof(char *) * 100);
    int idx = 0;

    if (n == 0)
    {
        answer[idx] = NULL;
        return answer;
    }

    if (n == 1)
    {
        if (triesearch(D, string))
        {
            answer[idx] = (char *)malloc(sizeof(char) * (n + 1));
            strcpy(answer[idx], string);
            idx++;
        }
        answer[idx] = NULL;
        return answer;
    }

    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }

    while (1)
    {
        if (triesearch(D, string))
        {
            answer[idx] = (char *)malloc(sizeof(char) * (n + 1));
            strcpy(answer[idx], string);
            idx++;
        }

        int i = n - 1;
        while (string[i - 1] >= string[i])
        {

            if (--i == 0)
            {
                answer[idx] = NULL;
                return answer;
            }
        }
        int j = n - 1;
        while (j > i && string[j] <= string[i - 1])
        {
            j--;
        }

        temp = string[i - 1];
        string[i - 1] = string[j];
        string[j] = temp;

        for (k = i; k <= (i + n - 1) / 2; k++)

        {
            temp = string[k];
            string[k] = string[n - 1 - k + i];
            string[n - 1 - k + i] = temp;
        }
    }
}
