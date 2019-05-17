#include <stdlib.h>
#include <stdio.h>

struct Node{
	long card_no;
	char bank_code[6];    // Size of these arrays 1 greater than the required size.
	char expiry_date[8];  // So that while printing, it doesn't include the other 					field as well and is able to get a blank space to stop.
	char first_name[6];
	char last_name[6];
};

struct Node * arr;  //Header file should never contain initialization. (Declaration only)

int endptr;

int ARR_SIZE;

unsigned int stack_topvalue,stack_bottomvalue;

void initialize();

double get_elapsed_time(char filename[]);

void read_from_file(FILE * fp);

void insertInOrder(int k, long card_no);

void insertionSort(int k);

void printarr();

