CC = gcc
CFLAGS = -Wall -O2 	#编译参数
VPATH = ./add/:./sub/:./
OBJS = add.o sub.o main.o #需要的二进制文件
OBJSDIR = .objs
TARGET = calc 	#编译目标
$(TARGET):$(OBJSDIR) $(OBJS)
	$(CC) $(OBJSDIR)/*.o -o $(TARGET) $(CFLAGS)  

# 把*.o 的文件改成 *c
$(OBJS):%.o:%.c  	
#  $< 是依赖项中第一个依赖文件名   $@ 目标想中的文件名	
	$(CC) -c $< -o $(OBJSDIR)/$@  $(CFLAGS) 

$(OBJSDIR):
	mkdir -p ./$@

clean:
	-$(RM) $(TARGET)
	-$(RM) $(OBJSDIR)/*.o













