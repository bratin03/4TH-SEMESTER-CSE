/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <dictload.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DFLT_DICT "../dict/words.txt"

dict loaddfltdict()
{ // loads default dictionary
    dict a = trieinit();
    FILE *fp = fopen(DFLT_DICT, "r");
    int end;
    char line[100];
    if (fp == NULL)
    {
        printf("Error! File not opened.\n");
        return a;
    }
    while (fgets(line, 100, fp))
    {
        end = strlen(line);
        if (line[end - 1] == '\n')
        {
            line[end - 1] = '\0';
        }
        trieinsert(a, line);
    }
    fclose(fp);
    return a;
}

dict loaddict(const char *fname)
{ // takes path to the dictionary as argument and loads it
    dict a = trieinit();
    FILE *fp = fopen(fname, "r");

    char line[100];
    int end;
    if (fp == NULL)
    {
        printf("Error! File not opened.\n");
        return a;
    }
    while (fgets(line, 100, fp))
    {
        end = strlen(line);
        if (line[end - 1] == '\n')
        {
            line[end - 1] = '\0';
        }
        trieinsert(a, line);
    }
    return a;
}
