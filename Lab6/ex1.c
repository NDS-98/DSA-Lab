#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	float cgpa;
}Student;

void merge(Student ls1[], int sz1, Student ls2[], int sz2, Student ls[]){
	int i=0,j=0;
	int k=0;
	
	while(i<sz1 && j<sz2){
		if(ls1[i].cgpa<ls2[j].cgpa){
			ls[k] = ls1[i];
			i++;
		}
		else{
			ls[k] = ls2[j];
			j++;
		}
		k++;
	}
	
	while(i<sz1){
		ls[k]=ls1[i];
		i++;
		k++;
	}
	
	while(j<sz2){
		ls[k]=ls2[j];
		j++;
		k++;
	}
	
}

void recursive_mergesort(Student arr[],int l,int r){
	if(l<r){
		int m = l+(r-l)/2;
		
		recursive_mergesort(arr,l,m);
		recursive_mergesort(arr,m+1,r);
		
		int sz1 = m-l+1;
		int sz2 = r-m;
		Student *ls1 = (Student*)malloc(sizeof(Student)*sz1);
		Student *ls2 = (Student*)malloc(sizeof(Student)*sz2);
		Student *ls = (Student*)malloc(sizeof(Student)*(sz1+sz2));
		
		int i,j;
		
		for(i=0;i<sz1;i++){
			ls1[i] = arr[l+i];
		}
		
		for(j=0;j<sz2;j++){
			ls2[j] = arr[m+1+j];
		}
		
		merge(ls1,sz1,ls2,sz2,ls);
		
		for(i=l,j=0;i<=r;i++,j++){
			arr[i] = ls[j];
		}
	}
}


int min(int x,int y){
	return (x<y)?x:y;
}

void mergesort(Student arr[],int l,int r){
	int current_size,left_start,right_end,m;
	
	for(current_size=1;current_size<=r-l;current_size*=2){
		for(left_start=0;left_start<r-l;left_start+=2*current_size){
			m = left_start+current_size-1;
			right_end = min(left_start+2*current_size-1,r-l);
			// min is imp for cases where (l-r),i.e, size to be sorted is not of the form 2^n.
			
			int sz1 = m-left_start+1;
			int sz2 = right_end-m;
			Student *ls1 = (Student*)malloc(sizeof(Student)*sz1);
			Student *ls2 = (Student*)malloc(sizeof(Student)*sz2);
			Student *ls = (Student*)malloc(sizeof(Student)*(sz1+sz2));
		
			int i,j;
		
			for(i=0;i<sz1;i++){
				ls1[i] = arr[left_start+i];
			}
		
			for(j=0;j<sz2;j++){
				ls2[j] = arr[m+1+j];
			}
		
			merge(ls1,sz1,ls2,sz2,ls);
			
			for(i=left_start,j=0;i<=right_end;i++,j++){
				arr[i] = ls[j];
			}
		}
	}
	
}

void printarr(Student arr[],int size){
	int i=0;
	for(int i=0;i<size;i++){
		printf("Name - %s --- CGPA - %f \n",arr[i].name,arr[i].cgpa);
	}
}

int main(){
	Student *ls = (Student *)malloc(sizeof(Student)*1024);
	FILE *fp;
	fp = fopen("1024.txt","r");
	int i=0;
	while(fscanf(fp,"%[^,],%f\n",ls[i].name,&ls[i].cgpa)!=EOF){
		i++;
	}
	fclose(fp);
	//printarr(ls,1024);
	
	mergesort(ls,0,1023);
	printarr(ls,1024);
	
}
	
