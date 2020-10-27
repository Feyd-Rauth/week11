#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char buf[5];
	char text[] = "Hello";
	memset(buf, '\0', sizeof(buf));
	setvbuf(stdin, buf, _IOLBF, 5);

	for(int i = 0; i < strlen(text); i++){
		printf("%c", text[i]);
		sleep(1);
	}

	return 0;
}