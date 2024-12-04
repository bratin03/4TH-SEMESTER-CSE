CC = gcc
CFLAGS = -I../utils -I../trie

maxchain:
	gcc -I../util -I../trie -L../util -L../trie -Wl,-rpath=../util -Wl,-rpath=../trie maxchain.c -o a.out -lwordutils -ltrie
	./a.out
subwords:
	gcc -I../util -I../trie -L../util -L../trie -Wl,-rpath=../util -Wl,-rpath=../trie subwords.c -o b.out -lwordutils -ltrie
	./b.out
clean: 
	rm -f a.out b.out
