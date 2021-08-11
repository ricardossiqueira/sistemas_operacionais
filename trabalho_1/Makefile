CC = g++
LD = g++

CFLAGS = -Wall
LFLAGS = -Wall

OBJS = handlers.o main.o

TARGET = trabalho_1

handlers.o: handlers.cpp handlers.hpp
	$(CC) $(CFLAGS) -c handlers.cpp

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)