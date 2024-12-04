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

typedef struct pair
{ // struct to store our answer
    char string[100];
    int len;
    char seq[100];
    int seq2[100];

} pair;

pair solve(pair in, dict D)
{ // function to recursively execute a DFS for getting the longest chain of words

    char *before = addbefore(D, in.string);
    char *after = addafter(D, in.string);
    int i, j;
    if (strlen(before) != 0 && strlen(after) != 0)
    {
        int max = 0;
        pair ans;

        pair a, aans;

        for (j = 0; j <= strlen(in.string); j++)
        {

            a.string[j + 1] = in.string[j];
            if (j != strlen(in.string))
            {
                a.seq[j] = in.seq[j];
                a.seq2[j] = in.seq2[j];
            }
        }
        for (i = 0; i < strlen(before); i++)
        {
            a.string[0] = before[i];
            a.len = in.len + 1;
            a.seq[strlen(in.string)] = before[i];
            a.seq2[strlen(in.string)] = 1;
            aans = solve(a, D);
            if (aans.len > max)
            {
                max = aans.len;
                ans = aans;
            }
        }

        if (in.len)
        {

            for (j = 0; j < strlen(in.string); j++)
            {

                a.string[j] = in.string[j];

                a.seq[j] = in.seq[j];
                a.seq2[j] = in.seq2[j];
            }
            for (i = 0; i < strlen(after); i++)
            {
                a.string[strlen(in.string)] = after[i];
                a.string[strlen(in.string) + 1] = '\0';
                a.len = in.len + 1;
                a.seq[strlen(in.string)] = after[i];
                a.seq2[strlen(in.string)] = -1;
                aans = solve(a, D);
                if (aans.len > max)
                {
                    max = aans.len;
                    ans = aans;
                }
            }
        }

        return ans;
    }

    else if (strlen(before) != 0 && strlen(after) == 0)
    {

        int max = 0;
        pair ans;

        pair a, aans;

        for (j = 0; j <= strlen(in.string); j++)
        {

            a.string[j + 1] = in.string[j];
            if (j != strlen(in.string))
            {
                a.seq[j] = in.seq[j];
                a.seq2[j] = in.seq2[j];
            }
        }
        for (i = 0; i < strlen(before); i++)
        {
            a.string[0] = before[i];
            a.len = in.len + 1;
            a.seq[strlen(in.string)] = before[i];
            a.seq2[strlen(in.string)] = 1;
            aans = solve(a, D);
            if (aans.len > max)
            {
                max = aans.len;
                ans = aans;
            }
        }
        return ans;
    }
    else if (strlen(before) == 0 && strlen(after) != 0)
    {
        int max = 0;
        pair a, aans, ans;

        for (j = 0; j < strlen(in.string); j++)
        {

            a.string[j] = in.string[j];

            a.seq[j] = in.seq[j];
            a.seq2[j] = in.seq2[j];
        }
        for (i = 0; i < strlen(after); i++)
        {
            a.string[strlen(in.string)] = after[i];
            a.string[strlen(in.string) + 1] = '\0';
            a.len = in.len + 1;
            a.seq[strlen(in.string)] = after[i];
            a.seq2[strlen(in.string)] = -1;
            aans = solve(a, D);
            if (aans.len > max)
            {
                max = aans.len;
                ans = aans;
            }
        }
        return ans;
    }
    else
        return in;
}

int main()
{
    pair input;
    input.len = 0;
    input.string[0] = '\0';
    dict Dictionary = loaddfltdict();
    // calling the function to recursively search for the longest chain of words starting from null string
    pair output = solve(input, Dictionary);
    int i, j;
    char ans[20];
    printf("The longest chain of valid words is:\n");
    for (i = 0; i < output.len; i++)
    {
        if (output.seq2[i] == 1)
        {
            for (j = i; j > 0; j--)
            {
                ans[j] = ans[j - 1];
            }
            ans[0] = output.seq[i];
        }
        else
        {
            ans[i] = output.seq[i];
            ans[i + 1] = '\0';
        }
        printf("%s\n", ans);
    }
}
