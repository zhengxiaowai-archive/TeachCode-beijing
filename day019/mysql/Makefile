.SUFFIXES:.c .o
CC=gcc
SRCS=mysql1.c
OBJS=$(SRCS:.c=.o)
EXEC=mysql1

start: $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) -lmysqlclient
.c.o:
	$(CC) -o $@ -c $< -g -Wall
clean:
	rm -f $(OBJS)
	rm -f core.*
