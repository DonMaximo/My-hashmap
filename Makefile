CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic

all: testMap

testMap: hashmap.h testMap.cpp
	$(CC) $(CFLAGS) -o testMap testMap.cpp

clean:
	rm -rf *.o testMap *~
