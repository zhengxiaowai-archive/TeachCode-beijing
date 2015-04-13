#include <stdio.h>
#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
MYSQL mysql,*connection;

void sql_err()
{
	fprintf(stderr, "%s\n", mysql_error(&mysql));
}

int insert_name()
{
	/*INSERT INTO table1 (name, sex, age, class), VALUES("名字", "性别", 年龄, "班级")*/
	char SQL[1024];

	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "%s", "输入要插入的名字>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char name[1024];
	memset(name, 0, sizeof(name));
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "%s", "输入要插入的性别>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char sex[1024];
	memset(sex, 0, sizeof(sex));
	fgets(sex, sizeof(sex), stdin);
	sex[strlen(sex) - 1] = '\0';

	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "%s", "输入要插入的年龄>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char age[1024];
	memset(age, 0, sizeof(age));
	fgets(age, sizeof(age), stdin);
	age[strlen(age) - 1] = '\0';

	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "%s", "输入要插入的班级>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char class[1024];
	memset(class, 0, sizeof(class));
	fgets(class, sizeof(class), stdin);
	class[strlen(class) - 1] = '\0';

	sprintf(SQL, "INSERT INTO table1(name, sex, age, class )  VALUES('%s', '%s', %s, '%s')", name, sex, age, class);
	if(0 != mysql_query(connection, SQL))
	{
		sql_err();
		return -1;
	}
	else
	{
		printf("query OK!\n");
	}

	return 0;
}

int delete_name()
{
	/*DELETE FROM table1 WHERE nane = 'xxxx'*/
	char SQL[1024];

	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "%s", "输入要插入的名字>");
	write(STDOUT_FILENO, SQL, strlen(SQL));
	char name[1024];
	memset(name, 0, sizeof(name));
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	sprintf(SQL, "DELETE FROM table1 WHERE name = '%s'", name);
	if(0 != mysql_query(connection, SQL))
	{
		sql_err();
		return -1;
	}
	else
	{
		printf("query OK!\n");
	}

	return 0;

}

int select_name()
{
	char SQL[1024];
	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "SELECT * FROM table1");

	if(mysql_query(connection, SQL) != 0)
	{
		sql_err();
		return -1;
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
		printf("%-s\t", field->name);
		field_count++;
	}
	printf("\n");

	while(1)
	{
		row = mysql_fetch_row(result);
		if(NULL == row)
			break;
		int i = 0;
		for(;i < field_count; i++)
			printf("%-s\t", row[i]);
		printf("\n");
	}
	
	mysql_free_result(result);
	return 0;
}

int set_names(char *str)
{
	char SQL[1024];
	memset(SQL, 0, sizeof(SQL));
	sprintf(SQL, "SET NAMES %s", str);
	if(0 != mysql_query(connection, SQL))
	{
		sql_err();
		return -1;
	}

	return 0;
}
int main(int argc, char *argv[])
{
	if(argc < 4)
		return -1;
	mysql_init(&mysql);

	connection = mysql_real_connect(&mysql, argv[1], argv[2], argv[3], argv[4], 0, 0, 0);
	if(NULL == connection)
	{
		printf("1111\n");
		sql_err();
		return -1;
	}

	set_names("utf8");
#if 0
	if(-1 == insert_name())
	{
		return -1;
	}
#endif
/*
	if(-1 == delete_name())
	{
		return -1;
	}
*/

	select_name();
	mysql_close(connection);
	return 0;
}
