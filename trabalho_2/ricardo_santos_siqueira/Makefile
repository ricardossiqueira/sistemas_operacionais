CC = g++
LD = g++

CFLAGS = -Wall -std=c++11 -pthread
LFLAGS = -Wall -std=c++11 -pthread

OBJS = main.o

TARGET = trabalho_2

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm $(OBJS) $(TARGET)

test:
	make -s all; for i in {1..10}; do ./trabalho_2; echo ----$i----; done; make -s clean