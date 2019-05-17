#include<stdio.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];


void PrintArr()
{
  for(int i=0; i<N; i++)
  {
     for(int j = 0; j < Num_Elements[i]; j++)
       printf(" %d ", Arr[i][j]);
     printf("\n");
  }
}

int main()
{
	Locality * test = ReadFileintoLists("file.txt");
	PrintLists(test);
	
	ConvertListstoArray(test);
	PrintArr();
	
	printf("-----------------------\n");
	InsertionSort_Arr();
	PrintArr();
	
	printf("-----------FINAL--------\n");
	int * lin = Merge_Arr();
	int size = sizeof(lin)/sizeof(lin[0]);
	
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",lin[i]);
	}
	
	return 0;
}
  

  
