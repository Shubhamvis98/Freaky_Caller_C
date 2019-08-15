#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define RED "\x1b[01;31m"
#define GREEN "\x1b[01;32m"
#define YELLOW "\x1b[01;33m"
#define BLUE "\x1b[01;34m"
#define MAGENTA "\x1b[01;35m"
#define CYAN "\x1b[01;36m"
#define RST "\x1b[0m"

void banner();
void chkroot();
void chkconf();
void delay();

int main()
{
	banner();
	chkconf();
	chkroot();
	delay();
	printf("\nDONE!!!\n");

	
}
/*#####################################*/
void banner()
{
	system("clear");
	printf(BLUE"=============================\n");
	printf("      Freaky Caller 2.0\n");
	printf("=============================\n"RST);
	printf("Written by Shubham Vishwakarma\n");
	printf("https://github.com/Shubhamvis98\n\n");
	sleep(2);
}

void chkroot()
{
	int UID = getuid();
	if (UID != 0)
	{
		printf(RED"[!] Try as root\n"RST);
		sleep(2);
		system("clear");
		exit(0);
	}
}

void chkconf()
{
	char conf[] = "config";
	if(access(conf, F_OK) != -1)
	{
		printf(BLUE"[!] Config found\n"RST);
	}
	else
	{
		printf(RED"[!] Config file not found\n"RST);
		sleep(1);
		printf(MAGENTA"[!] Creating config file\n"RST);
		FILE *conf;
		conf = fopen("config","w");
		fprintf(conf,"#      Default config file\n");
		fprintf(conf,"#\n");
		fprintf(conf,"#       Freaky Caller 2.0\n");
		fprintf(conf,"# Written by Shubham Vishwakarma\n");
		fprintf(conf,"#\n");
		fprintf(conf,"# Call Bomber that make multiple calls to a number\n");
		fprintf(conf,"#\n");
		fprintf(conf,"# https://github.com/shubhamvis98\n");
		fprintf(conf,"#\n");
		fprintf(conf,"# Works on rooted android devices\n");
		fprintf(conf,"# [!] The minimum value of 'C_INT' is 60 seconds \n\n");
		fprintf(conf,"PH_NO='Put phone number here'\n");
		fprintf(conf,"C_INT='Time interval between calls in seconds'\n");
		fclose(conf);
		sleep(1);
		printf(BLUE"[!] Config file created\n"RST);
		sleep(1);
		printf("\n[!] Now put the phone number and time interval in the config file using any text editor then re-execute this program\n");
		sleep(1);
		printf(RED"[!] Exitting...\n"RST);
		exit(0);
	}
}

void delay()
{
	system("source config; echo Number to call: $PH_NO");
	int n,hrs,min,sec,x=1;
	printf(BLUE"\n[?] Enter number of calls: "RST);
	scanf("%d",&n);
	printf(BLUE"\n[?] Enter Hours and Minutes\n\n"RST);
	printf(CYAN"[?] HOURS: "RST);
	scanf("%d",&hrs);
	printf(CYAN"\n[?] MINUTES: "RST);
	scanf("%d",&min);
	//Convert Hours and Minutes into Seconds
	hrs = hrs * 3600;
	min = min * 60;
	sec = hrs + min;
	printf(BLUE"\n[!] Waiting for %d seconds...\n"RST,sec);
	sleep(sec);

	while(x <= n)
	{
		printf("\nCalling %d\n",x);
		sleep(1);
		system("source config;am start -a android.intent.action.CALL -d tel:${PH_NO};sleep ${C_INT}");
		printf("\n\n");
		x++;
	}
}
