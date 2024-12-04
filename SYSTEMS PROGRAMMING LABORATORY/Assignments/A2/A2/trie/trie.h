/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#ifndef __TRIELIB_TRIE_H__
#define __TRIELIB_TRIE_H__
typedef struct trienode
{
    char label;
    int end_of_word;
    struct trienode *first_child, *next_sibling;
} trienode;

typedef trienode *trie;

trie trieinit();
extern int triesearch(trie t, char *s);
extern void trieinsert(trie t, char *s);
extern void listall(trie t);
#endif
