#ifndef __WORDUTILSLIB_DICTUTILS_H__
#define __WORDUTILSLIB_DICTUTILS_H__
#include <dicttype.h>
char *addbefore(dict D, char *s);
char *addafter(dict D, char *s);
char **anagrams(dict D, char *s);
#endif
