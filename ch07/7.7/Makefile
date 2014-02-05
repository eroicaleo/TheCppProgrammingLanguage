
CFLAGS = -std=c++11 -g -Wall
BINARY = rvalueref

all : $(BINARY)

# string : string.cpp
# 	g++ $(CFLAGS) $^ -o $@

% : %.cpp
	g++ $(CFLAGS) $^ -o $@

clean :
	rm -rf *.o $(BINARY)
