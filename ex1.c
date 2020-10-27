#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int file = open("ex1.txt", O_RDWR);

	struct stat mstat = {};
	fstat(file, &mstat);

	char text[] = "This is a nice day";
	ftruncate(file, strlen(text)*sizeof(char)); // setting a file size to the size of a text

	off_t size = mstat.st_size;
	char* str;

	str = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);

	for(int i = 0; i < strlen(text); i++)
	{
		str[i] = text[i];
	}

}