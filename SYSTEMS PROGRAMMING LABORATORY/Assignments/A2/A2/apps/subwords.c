/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wordutils.h>

int main()
{
    char string[100];
    printf("\nEnter a lower case string:\n");
    scanf("%s", string);
    int i, j;
    char temp;
    int n = strlen(string);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (string[i] > string[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    // generating all the poosible substring of length 1 less than the input string and then calling the anagrams fucntion to look for valid permutations
    dict Dictionary = loaddfltdict();
    int k = 0, l = 0, count = 0;
    char temp2[100];
    char **ans;
    for (i = 0; i < n; i++)
    {
        if (i && (string[i] == string[i - 1]))
        {
            continue;
        }
        for (j = 0; j <= n; j++)
        {
            if (i != j)
            {
                temp2[k++] = string[j];
            }
        }
        ans = anagrams(Dictionary, temp2);
        l = 0;
        while (ans[l] != NULL)
        {
            printf("%s\n", ans[l]);
            l++;
            count++;
        }
        l = 0;

        k = 0;
    }
    printf("%d subwords found\n", count);
}