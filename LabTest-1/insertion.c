#include "node.h"
#include<stdio.h>

extern int * Arr[N];
extern int Num_Elements[N];

void InsertionSort_GM(int arr[], int n) 
{
	int i,key,j;
	for(i=1;i<n;i++){
		key = arr[i];
		j=i-1;
		while(j>=0 && IsLower_GM(key, arr[j])){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
 
} 

void InsertionSort_Arr()
{
	int i;
	
	for(i=0;i<N;i++){
		InsertionSort_GM(Arr[i],Num_Elements[i]);
	}
}


