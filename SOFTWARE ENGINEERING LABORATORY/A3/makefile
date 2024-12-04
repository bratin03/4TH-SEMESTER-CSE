CC = g++
CFLAGS = -fPIC -c -I.
LDFLAGS = -fPIC -shared

interface:
	g++ -Wall -c rdb-basics.cpp 
	g++ -Wall -c rdb-attr.cpp 
	g++ -Wall -c rdb-join.cpp
	g++ -Wall -o run.out rdb-main.cpp rdb-attr.o rdb-basics.o rdb-join.o
	./run.out

library: librdb.so

librdb.so: rdb-basics.o rdb-attr.o rdb-join.o
	$(CC) $(LDFLAGS) -o $@ $^

rdb-basics.o: rdb-basics.cpp rdb.h
	$(CC) $(CFLAGS) -o $@ $<

rdb-attr.o: rdb-attr.cpp rdb.h
	$(CC) $(CFLAGS) -o $@ $<

rdb-join.o: rdb-join.cpp rdb.h
	$(CC) $(CFLAGS) -o $@ $<

run_with_library:
	g++ -I. -L. -Wl,-rpath=. rdb-main.cpp -o librun.out -lrdb
	./librun.out

clean:
	rm -f my rdb-attr.o rdb-basics.o rdb-join.o librdb.so run.out librun.out