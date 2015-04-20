CC=gcc

TARGET=book
OBJS=book.o

$(TARGET):$(OBJS)
	$(CC) $^ -o $@

$(OBJS):%.o:%.c
	$(CC) -c $^ -o $@ 

clean:
	-$(RM) $(TARGET) $(OBJS)

