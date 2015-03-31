int main(int arg, char *args[])
{
	int fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error is %s\n", strerror(errno));
	}else
	{
		printf("success fd = %d\n", fd);
		struct stat buf;
		fstat(fd, &buf);
		if (S_ISREG(buf.st_mode))//�ж��ļ��Ƿ�Ϊ��׼�ļ�
		{
			printf("%s is charfile\n", args[1]);
		}
		if (S_ISDIR(buf.st_mode))//�ж��ļ��Ƿ�ΪĿ¼
		{
			printf("%s is dir\n", args[1]);
		}

		printf("%s size =%d\n", args[1], buf.st_size);//�õ��ļ���С

		close(fd);
	}
	return 0;
}