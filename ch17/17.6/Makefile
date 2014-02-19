
CFLAGS = -std=c++11 -g -Wall
BINARY = ExplicitDefaults DefaultOperations handle Tic_tac_toe DeletedFunctions

all : $(BINARY)

# string : string.cpp
# 	g++ $(CFLAGS) $^ -o $@

% : %.cpp
	g++ $(CFLAGS) $^ -o $@

clean :
	rm -rf *.o $(BINARY)
