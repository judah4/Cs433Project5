

#include <stdio.h>
#include <cstdlib>
#include <ctime>

#define PAGEREFS 20

//Fifo page replacement
//returns page faults
int fifo(int pageRefs[], int frameCount)
{
	int *frames = (int*)malloc(frameCount * sizeof(int));

	//reset to empty
	int frameCnt;
	int pageCnt;
	for (frameCnt = 0; frameCnt < frameCount; frameCnt++) {
		frames[frameCnt] = -1;
	}

	int fault = 0;
	int lastIndex = 0;
	for (pageCnt = 0; pageCnt < PAGEREFS; pageCnt++) {

		int page = pageRefs[pageCnt];

		bool foundPage = false;
		for (frameCnt = 0; frameCnt < frameCount; frameCnt++) {
			if (frames[frameCnt] == page) {
				foundPage = true;
				break;
			}
		}

		if(foundPage == false)
		{
			fault++;
			frames[lastIndex] = page;
			lastIndex++;
			lastIndex %= frameCount;
		}


	}


	free(frames);

	return fault;
}

int main(int argc, char *argv[])
{

	/*
	 * Write a program that implements the FIFO, LRU, and optimal page replacement algorithms presented in this chapter. 
	 * First, generate a random page-reference string where page numbers range from 0 to 9. Apply the random page-reference string to each algorithm, 
	 * and record the number of page faults incurred by each algorithm. 
	 * Implement the replacement algorithms so that the number of page frames can vary from 1 to 7. Assume that demand paging is used.
	 */

	printf("Judah Perez, CS 433, Project 5 Part 2\n");
	printf("5/4/2018\n");
	printf("Page Replacement Stratagies\n");

	int pageRefs[PAGEREFS];

	time_t t;
	/* Intializes random number generator */
	srand((unsigned)time(&t));

	int cnt;
	for (cnt = 0; cnt < PAGEREFS; cnt++) {
		pageRefs[cnt] = rand() % 10;
	}

	printf("Enter number of page frames from 1 to 7. \n");

	int frames;
	scanf_s("%d", &frames);

	if (frames > 7)
	{
		frames = 7;
	}
	if(frames < 1)
	{
		frames = 1;
	}

	printf("Page String: ");
	for (cnt = 0; cnt < PAGEREFS; cnt++) {
		printf("%d ", pageRefs[cnt]);
	}
	printf("\nFrames: %d\n", frames);


	int fifoFaults = fifo(pageRefs, frames);
	printf("FIFO Page Faults = %d\n", fifoFaults);

	scanf_s("%d", &frames);

	return 0;
}
