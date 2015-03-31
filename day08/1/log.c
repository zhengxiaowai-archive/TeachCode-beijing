#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
int write_log(const char *log)
{
	time_t tDate;
	struct tm *eventTime;
	time(&tDate);
	eventTime = localtime(&tDate);

	int year = eventTime->tm_year + 1900;
	int mon	 = eventTime->tm_mon;
	int day	 = eventTime->tm_mday;
	int hour = eventTime->tm_hour;
	int min  = eventTime->tm_min;
	int sec  = eventTime->tm_sec;

	char sDate[16];
	memset(sDate, 0, sizeof(sDate));
	sprintf(sDate, "%04d-%02d-%02d", year, mon, day);
	char sTime[16];
	memset(sTime, 0, sizeof(sTime));
	sprintf(sTime, "%02d:%02d:%02d", hour, min, sec);
	char s[1024];
	memset(s, 0, sizeof(s));
	sprintf(s, "%s %s : %s", sDate, sTime, log);

	FILE *fp = fopen("log.txt", "a+");
	if(!fp)
	{
		perror("open log failed:");
		return -1;
	}
	fputs(s,fp);
	fclose(fp);
	
	return 0;

}
int main( int argc, char *argv[])
{
	write_log("程序开始\n");
	write_log("hello world\n");
	write_log("程序结束\n");

	return 0;
}