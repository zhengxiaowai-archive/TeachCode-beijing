#include <stdio.h>
#include <malloc.h>
typedef struct student
{
	int data;
	struct student  *next;
}ST;

void output(ST *s)
{
	while(s)
	{
		printf("%d ", s->data);
		s = s->next;
	}
}

int main(int argc, char *argv[])
{
	ST *s1 = (ST *)malloc(sizeof(ST));
	ST *s2 = (ST *)malloc(sizeof(ST));
	ST *s3 = (ST *)malloc(sizeof(ST));//我是新的
	ST *s4 = (ST *)malloc(sizeof(ST));
	s1->data = 1;
	s2->data = 2;
	s3->data = 3;//新的
	s4->data = 4;
	s1->next = s2;//next是一个指针，
				//他的作用是指向下一个结构体，
				//也好就是s2,
				//所以我们只需要把s2付给s1->next
	//s2->next = s3;
	s2->next = s4;
	s4->next = NULL;
	
	/*插入操作124->1234*/
	s3->next = s1->next->next;
	s1->next->next =s3;

	/*删除操作 1234->124*/
	s1->next->next = s1 ->next->next->next;
	free(s3);


	output(s1);//124
	//printf("%d\n",s1->next->data);
	printf("\n");
	return 0;
}
