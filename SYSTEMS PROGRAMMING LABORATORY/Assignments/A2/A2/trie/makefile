CC = gcc
CFLAGS = -fPIC -c -I. 
LDFLAGS = -shared

library: libtrie.so

libtrie.so: trie.o
	$(CC) $(LDFLAGS) -o $@ $^

trie.o: trie.c trie.h
	$(CC) $(CFLAGS) -o $@ $<

distclean:
	rm -f *.o libtrie.so
