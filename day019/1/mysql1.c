#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

MYSQL mysql, *connection;
void cancel_backspace()
{
	struct termios term;//定义一个temions结构
	if(tcgetattr(STDIN_FILENO, &term) == -1)//得到系统termion的设置
	{
		printf("tcgetattr error is %s\n", strerror(errno));
		return;
	}
	term.c_cc[VERASE] = '\b';//'\b'为退格键的ASCII码
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)//设置系统termion
	{
		printf("tcsetattr error is %s\n", strerror(errno));
		return;
	}

}

void deletename()
{
	char SQL[1024];
	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL,"%s","输入要删除的名字>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char name[1024];
	memset(name, 0, sizeof(name));
	fgets(name,sizeof(name),stdin);
	name[strlen(name) - 1] = '\0';

	sprintf(SQL, "DELETE FROM table1 WHERE name = '%s'", name);
	printf("%s",SQL);

	if( mysql_query(connection,SQL) != 0)
	{
		printf("query failed:%s\n",mysql_error(&mysql));
		return;
	}
}

void insertname()
{
	char SQL[1024];
	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL,"%s","输入要删除的名字>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char name[1024];
	memset(name, 0, sizeof(name));
	fgets(name,sizeof(name),stdin);
	name[strlen(name) - 1] = '\0';

	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL,"%s","输入要删除的性别>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char sex[1024];
	memset(sex, 0, sizeof(sex));
	fgets(sex,sizeof(sex),stdin);
	sex[strlen(sex) - 1] = '\0';
	
	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL,"%s","输入要删除的年龄>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char age[1024];
	memset(age, 0, sizeof(age));
	fgets(age,sizeof(age),stdin);
	age[strlen(age) - 1] = '\0';
	
	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL,"%s","输入要删除的班级>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char class[1024];
	memset(class, 0, sizeof(class));
	fgets(class,sizeof(class),stdin);
	class[strlen(class) - 1] = '\0';
	
	
	sprintf(SQL, "INSERT INTO table1(name, sex, age, class )  VALUES('%s', '%s', %s, '%s')", name, sex, age, class);
	//printf("%s",SQL);

	if( mysql_query(connection,SQL) != 0)
	{
		printf("query failed:%s\n",mysql_error(&mysql));
		return;
	}
}
void set_utf8()
{
	mysql_query(connection,"SET NAMES utf8");
}

void selectname()
{
	
	char SQL[1024];
	memset(SQL, 0, sizeof(SQL));
	/*
	sprintf(SQL,"%s","输入要查询的名字>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	
	char name[1024];
	memset(name, 0, sizeof(name));
	fgets(name,sizeof(name),stdin);
	name[strlen(name) - 1] = '\0'; */
	sprintf(SQL, "SELECT * FROM table1");
	
	if( mysql_query(connection,SQL) != 0)
	{
		printf("query failed:%s\n",mysql_error(&mysql));
		return;
	}
	
	MYSQL_RES *result = mysql_store_result(connection);
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	int field_count = 0;
	while(1)
	{
		field = mysql_fetch_field(result);
		if(NULL == field)
			break;
		printf("%s\t", field->name);
		field_count++;
	}
	printf("\n");
	
	while(1)
	{
		row = mysql_fetch_row(result);
		if(NULL == row)
			break;
		int i = 0;
		for(; i <field_count; i++ )
			printf("%s\t", row[i]);
		printf("\n");
	}
	
	
	mysql_free_result(result);
}
int main(int argc, char *argv[])
{
	if( argc < 4)
		return 0;
	cancel_backspace();
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql, argv[1], argv[2], argv[3],
									argv[4], 0 ,0 ,0);
	if( NULL == connection)
	{
		printf("connect failed:%s\n",mysql_error(&mysql));
		return -1;
	}
	
	set_utf8();
	selectname();
	mysql_close(connection);

	return 0;
}
