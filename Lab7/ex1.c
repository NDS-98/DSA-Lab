#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct {
	char name[10];
	int id;
} Employee;

// Swapping can always be easily done using pointers.
void swapEmp(Employee *a,Employee *b){
	Employee t = *a;
	*a=*b;
	*b=t;
}

//---------------------Exercise-1---------------------------

int partition(Employee arr[],int low,int high){
	int pivot = arr[high].id;
	
	int i=low-1;
	for(int j=low;j<high;j++){
		if(arr[j].id<=pivot){
			i++;
			swapEmp(&arr[j],&arr[i]);
		}
	}
	swapEmp(&arr[i+1],&arr[high]);
	return (i+1);
}

void quicksort(Employee arr[],int low,int high,int S){
	
	int stack[high-low+1];
	int top=-1;
	
	stack[++top]=low;
	stack[++top]=high;
	
	while(top>=0){
		high = stack[top--];
		low = stack[top--];
		
		int p = partition(arr,low,high);
		
		if(low<p-1 && (p-low)>S){
			stack[++top]=low;
			stack[++top]=p-1;
		}
		if(p+1<high && (high-p)>S){
			stack[++top]=p+1;
			stack[++top]=high;
		}
	}
	
}

// Part-(b)

void insertionsort(Employee arr[],int low,int high){
	int k=low;
	
	for(int i=low+1;i<=high;i++){
		k=i;
		for(int j=i-1;j>=low;j--){
			if(arr[j].id>arr[k].id){
				swapEmp(&arr[k],&arr[j]);
				k--;
			}
			else
				break;
		}
	}
}


//--------------------Exercise-2-----------------------

double * testRun(Employee Ls,int size){
	Employee Ls1[size],Ls2[size];
	
	for(int i=0;i<size;i++){
		Ls1[i]=Ls[i];
		Ls2[i]=Ls[i];
	}
	
	struct timeval t1,t2;
	double QStime;
	
	gettimeofday(&t1,NULL);
	quicksort(Ls1,0,size-1,1);
	gettimeofday(&t2,NULL);
	
	QStime = (t2.tv_sec-t1.tv_sec)*1000.0;
	QStime += (t2.tv_usec-t1.tv_usec)/1000.0;
	
	gettimeofday(&t1,NULL);
	insertionsort(Ls2,0,size-1);
	gettimeofday(&t2,NULL);
	
	IStime = (t2.tv_sec-t1.tv_sec)*1000.0;
	IStime += (t2.tv_usec-t1.tv_usec)/1000.0;
	
	double arr[2];
	arr[0]=QStime;
	arr[1]=IStime;
	
	return arr;
}

int estimateCutoff(Employee Ls){
	double *tt1 = testRun(Ls,min);
	printf("QS_mintime: %lf \t IS_mintime: %lf",tt1[0],tt1[1]);
	
	double *tt2 = testRun(Ls,max);
	printf("QS_maxtime: %lf \t IS_maxtime: %lf",tt2[0],tt2[1]);
	
	// Binary Search
	int mid;
	double *tt;
	
	while(min<=max){
		mid = (min+max)/2;
		tt = testRun(Ls,mid);
	
		
	}
	
}


int main(){
	
	//------------------------Exercise-1------------------------
	
	Employee arr[6];
	strcpy(arr[0].name,"Aa"); //Use strncpy instead of strcpy
	arr[0].id=20;
	strcpy(arr[1].name,"Bb");
	arr[1].id=15;
	strcpy(arr[2].name,"Cc");
	arr[2].id=45;
	strcpy(arr[3].name,"Dd");
	arr[3].id=30;
	strcpy(arr[4].name,"Ee");
	arr[4].id=70;
	strcpy(arr[5].name,"Ff");
	arr[5].id=50;
	
	printf("------------QUICK SORT-------------\n");
	quicksort(arr,0,5,1);
	for(int i=0;i<6;i++){
		printf(" %s---%d\n",arr[i].name,arr[i].id);
	}
	
	strcpy(arr[0].name,"Aa"); //Use strncpy instead of strcpy
	arr[0].id=20;
	strcpy(arr[1].name,"Bb");
	arr[1].id=15;
	strcpy(arr[2].name,"Cc");
	arr[2].id=45;
	strcpy(arr[3].name,"Dd");
	arr[3].id=30;
	strcpy(arr[4].name,"Ee");
	arr[4].id=70;
	strcpy(arr[5].name,"Ff");
	arr[5].id=50;
	
	printf("------------INSERTION SORT-------------\n");
	insertionsort(arr,0,5);
	
	for(int i=0;i<6;i++){
		printf(" %s---%d\n",arr[i].name,arr[i].id);
	}
}
