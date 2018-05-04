

#include <stdio.h>
#include <cstdlib>

int main(int argc, char *argv[])
{

	/*
	 * Assume that a system has a 32-bit virtual address with a 4-KB page size.
	 *  Write a C program that is passed a virtual address (in decimal) on the command line and have it output the page number and offset for the given address
	 */

	const unsigned int pageSize = 4096;


	printf("Judah Perez, CS 433, Project 5 Part 1\n");
	printf( "5/4/2018\n");
	printf( "Virtual Addressing\n");

	//check for arg
	if ((argc < 2))
	{
		printf("Please add arguments for virtual address, producers and consumers");
		return -1;
	}

	unsigned int virtualAddress = atoi(argv[1]);

	//calc page, calc offset
	unsigned int pageNumber = virtualAddress / pageSize;
	unsigned int offset = virtualAddress - (pageNumber * pageSize);

	printf("the address %d\n", virtualAddress);
	printf("page number = %d\n", pageNumber);
	printf("offset = %d\n", offset);

	return 0;
}
