/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <trie.h>

trie trieinit()
{ // Fucntion to return empty trie
    trie new;
    trienode *node = (trienode *)malloc(sizeof(trienode));
    node->end_of_word = 0;
    node->label = '-';
    node->first_child = NULL;
    node->next_sibling = NULL;
    new = node;
    return new;
}

int triesearch(trie T, char *s)
{ // Fucntion which scans the string character by character and checks if there exists a path for the given string
    int strl = strlen(s), i;
    trienode *cur = T;
    for (i = 0; i < strl; i++)
    {
        cur = cur->first_child;
        if (cur == NULL)
        {
            return 0;
        }
        while (cur)
        {
            if (cur->label == s[i])
            {
                break;
            }
            if (cur->label > s[i])
            {
                return 0;
            }
            cur = cur->next_sibling;
        }
        if (cur == NULL)
        {
            return 0;
        }
        if (i == strl - 1)
        {
            if ((cur->end_of_word) == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

void trieinsert(trie T, char *s)
{ // Fucntion scans the string character by character and checks if there already exists a path
    // if not it creates a path with adding the missing characters at the missing places
    int strl = strlen(s), i;
    trienode *cur = T, *prev = T, *head = T, *parent;
    for (i = 0; i < strl; i++)
    {
        parent = cur;
        cur = cur->first_child;
        head = cur;
        if (cur == NULL)
        {
            trienode *temp = (trienode *)malloc(sizeof(trienode));
            temp->label = s[i];
            temp->first_child = NULL;
            temp->next_sibling = NULL;
            parent->first_child = temp;
            temp->end_of_word = 0;
            cur = temp;
        }
        else
        {
            prev = cur;
            while (cur != NULL)
            {
                if (cur->label == s[i])
                {
                    break;
                }
                if (cur->label > s[i])
                {
                    if (cur == head)
                    {
                        trienode *temp = (trienode *)malloc(sizeof(trienode));
                        temp->label = s[i];
                        temp->first_child = NULL;
                        temp->next_sibling = head;
                        parent->first_child = temp;
                        cur = temp;
                        temp->end_of_word = 0;
                        break;
                    }
                    else
                    {
                        trienode *temp = (trienode *)malloc(sizeof(trienode));
                        temp->label = s[i];
                        temp->first_child = NULL;
                        temp->next_sibling = cur;
                        prev->next_sibling = temp;
                        cur = temp;
                        temp->end_of_word = 0;
                        break;
                    }
                }
                prev = cur;
                cur = cur->next_sibling;
            }
            if (cur == NULL)
            {
                trienode *temp = (trienode *)malloc(sizeof(trienode));
                temp->label = s[i];
                temp->first_child = NULL;
                prev->next_sibling = temp;
                temp->end_of_word = 0;
                cur = temp;
            }
        }
        if (i == strl - 1)
        {
            cur->end_of_word = 1;
        }
    }
}

void listall(trie T)
{ // A DFS search to list all the elements
    trienode *x = T;
    trienode *arr[100];
    int i = 0, down = 1, j;
    while (i != 0 || down != 0)
    {
        if (down == 1)
        {
            if (x->first_child)
            {
                arr[i++] = x;
                if (x->end_of_word == 1)
                {
                    for (j = 1; j < i; j++)
                    {
                        printf("%c", arr[j]->label);
                    }
                    printf("\n");
                }
                x = x->first_child;
            }
            else
            {
                down = 0;
                arr[i] = x;
                if (x->end_of_word == 1)
                {
                    for (j = 1; j <= i; j++)
                    {
                        printf("%c", arr[j]->label);
                    }
                    printf("\n");
                }
            }
        }
        else
        {
            if (x->next_sibling)
            {
                x = x->next_sibling;
                arr[i++] = x;
                if (x->end_of_word == 1)
                {
                    for (j = 1; j < i; j++)
                    {
                        printf("%c", arr[j]->label);
                    }
                    printf("\n");
                }
                if (x->first_child)
                {
                    x = x->first_child;
                    down = 1;
                }
                else
                {
                    down = 0;
                }
            }
            else
            {
                x = arr[--i];
            }
        }
    }
}