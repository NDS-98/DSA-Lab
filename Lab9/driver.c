#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(){
	book = parser("aliceinwonderland.txt");
	profiling(book);
	
	//printf("HV = %d\n",hashFn("Adventures",5003,5000));
	
	createHashtable();
	int inCost = insertAll(htable);
	printf("Insertion Cost: %d\n",inCost);
	hashtableProfiling(htable);
	return 0;
}
