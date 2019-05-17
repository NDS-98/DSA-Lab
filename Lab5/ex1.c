#include <stdio.h>
#include "ex1.h"
#include <sys/time.h>
#include <string.h>

double elapsedTime;

void initialize(){
	arr = (struct Node *)malloc(ARR_SIZE*sizeof(struct Node));
	endptr=-1;
}

double get_elapsed_time(char filename[]){
	struct timeval t1,t2;
	
	gettimeofday(&t1, NULL);
	//printf("Elapsed Time t1 = %ld\n",t1.tv_usec);
	
	FILE * fptr = fopen(filename,"r");
	read_from_file(fptr);
	
	gettimeofday(&t2, NULL);
	fclose(fptr);
	
	//Elapsed Time in milliseconds
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000;
	
	//printf("Elapsed Time t2= %ld\n",t2.tv_usec);
	//printf("Elapsed Time = %lf\n",elapsedTime);
	
	return elapsedTime;
}

void grow_array(){
	int initial_size = sizeof(arr)/sizeof(arr[0]);
	int new_size = initial_size*10;
	arr = (struct Node*)realloc(arr,new_size*sizeof(struct Node));
}

void read_from_file(FILE * fp){
	if(fp==NULL){
		printf("Invalid File Pointer!\n");
	}
	endptr=0;
	long card_no;
	char bank_code[6];
	char expiry_date[8];
	char first_name[6];
	char last_name[6];
	int size;
	
	/*while(fscanf("\"%d%*c %s%*c %s%*c %s%*c %s\"",&card_no,bank_code,expiry_date,first_name,last_name)!=-1){
		arr[endptr].card_no = card_no;
		arr[endptr].bank_code = bank_code;
		arr[endptr].expiry_date = expiry_date;    WRONG ASSIGNMENT : Coz arrays can't be assigned like this.
		arr[endptr].first_name = first_name;
		arr[endptr].last_name = last_name;
	}*/
	int updated_size=0;
	while(!feof(fp)){
		fscanf(fp,"\"%ld%*c%[^,]%*c%[^,]%*c%[^,]%*c%[^\"]\"\n",&card_no,bank_code,expiry_date,first_name,last_name);
		
		arr[endptr].card_no = card_no;
		strcpy(arr[endptr].bank_code,bank_code);
		strcpy(arr[endptr].expiry_date,expiry_date);
		strcpy(arr[endptr].first_name,first_name);
		strcpy(arr[endptr].last_name,last_name);
		
		updated_size++;
		
		endptr+=1;
		size = sizeof(arr)/sizeof(arr[0]);
		if(endptr==size){
			grow_array();
		}
	}
	ARR_SIZE=updated_size;
	
	// Checking by printing the array arr.
	// printarr();
	
}

void insertInOrder(int k, long card_no){
	int i; //The array is sorted upto index k.
	
	//Search for index of given card no.
	for(i=k+1;i<ARR_SIZE;i++){
		if(arr[i].card_no==card_no)
			break;
	}
	struct Node value = arr[i];
	int j;
	for(j=i;j>k+1;j--){
		arr[j] = arr[j-1];
	}
	for(j=k;j>=0;j--){
		if(value.card_no>arr[j].card_no){
			break;
		}
		else
			arr[j+1] = arr[j];
	}
	arr[j+1] = value;
	
	unsigned int stack_top = 0;
	stack_topvalue = &stack_top;
	
}

void insertionSort(int k){
	if(k==ARR_SIZE-1)
		return;
	
	insertInOrder(k,arr[k+1].card_no);
	insertionSort(k+1);
	return;
}

void printarr(){
	int i;
	for(i=0;i<ARR_SIZE;i++){
		printf("%ld \t %s \t %s \t %s \t %s \n",arr[i].card_no,arr[i].bank_code,arr[i].expiry_date,arr[i].first_name,arr[i].last_name);
	}
}

