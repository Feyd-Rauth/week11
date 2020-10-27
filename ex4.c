#include <sys/mman.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int srcd, destd;
	char *src, *dest;
	struct stat src_stat;
	size_t filesize;

	srcd = open("ex1.txt", O_RDONLY); // opening the source file
	fstat(srcd, &src_stat);
	filesize = src_stat.st_size;

	src = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, srcd, 0);

	destd = open("ex1.memcpy.txt", O_RDWR|O_CREAT); //creating and opening a destination file

	ftruncate(destd, filesize); //setting size of destination file to the size of the source file

	dest = mmap(NULL, filesize, PROT_READ|PROT_WRITE, MAP_SHARED, destd, 0);

	memcpy(dest, src, filesize);

	/* UNMAPPING */
	munmap(src, filesize);
	munmap(dest, filesize);
	/* CLOSING */
	close(srcd);
	close(destd);



	return 0;
}