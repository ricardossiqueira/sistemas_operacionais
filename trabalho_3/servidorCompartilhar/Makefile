# the compiler
CC = gcc

# compiler flags:
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall
LDFLAGS = -pthread

# the build target executable:
TARGET1 = server
TARGET2 = FilaLista

all: $(TARGET1)

$(TARGET1): $(TARGET1).c $(TARGET2).c
	$(CC) $(CFLAGS) -o $(TARGET1) $(TARGET1).c $(TARGET2).c $(LDFLAGS)

clean:
	$(RM) $(TARGET1) $(TARGET1)
