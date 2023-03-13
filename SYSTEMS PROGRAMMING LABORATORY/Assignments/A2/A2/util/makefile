CC = gcc
CFLAGS = -fPIC -c -I. -I../trie
LDFLAGS = -shared

library: libwordutils.so

libwordutils.so: dictload.o dictutils.o
	$(CC) $(LDFLAGS) -o $@ $^

dictload.o: dictload.c dicttype.h dictload.h
	$(CC) $(CFLAGS) -o $@ $<

dictutils.o: dictutils.c dicttype.h dictutils.h
	$(CC) $(CFLAGS) -o $@ $<

distclean:
	rm -f *.o libwordutils.so
