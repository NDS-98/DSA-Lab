#include<stdio.h>
#include <stdlib.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];

void Merge_GM(int *Ls1, int sz1, int * Ls2, int sz2, int* Ls)
{
  if(sz2==0)
	Ls = Ls1;
	
  int i=0,j=0,k=0;
  while(i<sz1 && j<sz2){
  	if(IsLower_GM(Ls1[i],Ls2[j])){
  		Ls[k] = Ls1[i];
  		i++;
  	}
  	else{
  		Ls[k] = Ls2[j];
  		j++;
  	}
  	k++;
  }
  
  while(i<sz1){
  	Ls[k] = Ls1[i];
  	i++;
  	k++;
  }
  
  while(j<sz2){
  	Ls[k] = Ls2[j];
  	j++;
  	k++;
  }
}

int * Merge_Arr()
{
   int i;
   int *linarr = (int *)malloc(sizeof(int)*(M*N));
   int sizelinarr = 0;
   
   for(i=0;i<N;i++){
   
   	int tempsize = Num_Elements[i]+sizelinarr;
   	
   	int *temp = (int *)malloc(sizeof(int)*tempsize);
   	
   	Merge_GM(Arr[i],Num_Elements[i],linarr,sizelinarr,temp);
   	
   	int j;
   	for(j=0;j<tempsize;j++){
   		linarr[i] = temp[i];
   	}
   	sizelinarr = tempsize;
   }
   return linarr;   
}



