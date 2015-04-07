.SUFFIXES:.c .o

CC=gcc

SRCS1=server.c
SRCS2=client.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)

EXEC1=server
EXEC2=client

all: $(OBJS1) $(OBJS2)
	$(CC) $(OBJS1) -o $(EXEC1) -lpthread
	$(CC) $(OBJS2) -o $(EXEC2) -lpthread
.c.o:
	$(CC) -o $@ -c $< -g -Wall
clean:
	rm -f *.o
	rm -f core.*
