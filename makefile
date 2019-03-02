CC = g++
CFLAGS = -std=c++11
TARGET = P0
OBJS = main.o Node.o Tree.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
Node.o: Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp
Tree.o: Tree.cpp
	$(CC) $(CFLAGS) -c Tree.cpp
clean:
	/bin/rm -f *.o
clean_all:
	/bin/rm -f *.o $(TARGET)
