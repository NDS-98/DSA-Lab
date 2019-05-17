#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <math.h>
#include <limits.h>

int hashFn(char* str,int baseNo,int tableSize){
	int i,sum=0;
	for(i=0;i<strlen(str);i++){
		sum += (int)str[i];
	}
	return (sum%baseNo)%tableSize;	
}

int collisionCount(char** arr,int arrsize,int baseNo,int tableSize){
	int *tablearr = (int *)malloc(sizeof(int)*tableSize);
	
	printf("----------SIZE---------%d------\n",arrsize);
	
	int collisions=0;
	int hashvalue;
	for(int i=0;i<arrsize;i++){
		hashvalue = hashFn(arr[i],baseNo,tableSize);
		if(tablearr[hashvalue]==1){
			collisions++;
		}
		else if(tablearr[hashvalue]==0)
			tablearr[hashvalue]=1;
	}
	return collisions;
}

char** parser(char* filename){
	FILE *fp = fopen(filename,"r");
	
	int size=20000;
	char** book = (char **)malloc(sizeof(char*)*size);
	
	int i=0;
	while(!feof(fp)){
		if(i==size-2){
			book = (char**)realloc(book,sizeof(char *)*size*2);
			size *= 2;
		}
		book[i] = (char*)malloc(sizeof(char*)*15);
		fscanf(fp," %[^ \n]",book[i]);
		
		int wordsize = strlen(book[i]);
		if(((book[i][wordsize-1]>='A' && book[i][wordsize-1]<='Z')||(book[i][wordsize-1]>='a' && book[i][wordsize-1]<='z'))&&((book[i][0]>='A' && book[i][0]<='Z')||(book[i][0]>='a' && book[i][0]<='z'))&&((book[i][wordsize-2]>='A' && book[i][wordsize-2]<='Z')||(book[i][wordsize-2]>='a' && book[i][wordsize-2]<='z'))&&((book[i][1]>='A' && book[i][1]<='Z')||(book[i][1]>='a' && book[i][1]<='z'))){
			printf("%s\n",book[i]);
			i++;
		}
	}
	printf("The no. of words are %d\n",i-1);
	booksize = i-1;
	return book;
}

void profiling(char** book){
	int tsize[3] = {5000,50000,500000};
	
	int best_tsize,best_bno;
	int minCollision = INT_MAX;

	for(int t=0;t<3;t++){
		int i = tsize[t];
		int baseNs[6];
		int k=0;
		while(i<=2*tsize[t]){
			int flag=0;
			for(int j=2;j<=sqrt(i);j++){
				if(i%j==0){
					flag=1;
					break;
				}	
			}
			if(flag==0){
				baseNs[k]=i;
				k++;
				if(k>=3)
					break;
			}
			i++;
		}
		i=1000*tsize[t];
		while(1){
			int flag=0;
			for(int j=2;j<=sqrt(i);j++){
				if(i%j==0){
					flag=1;
					break;
				}	
			}
			if(flag==0){
				baseNs[k]=i;
				k++;
				if(k>5)
					break;
			}
			i++;
		}
		
		for(int p=0;p<6;p++){
			int collision = collisionCount(book,booksize,baseNs[p],tsize[t]);
			printf("Base No: %d, Table Size: %d, Collisions: %d\n",baseNs[p],tsize[t],collision);
			
			if(collision<minCollision){
				minCollision = collision;
				best_tsize = tsize[t];
				best_bno = baseNs[p];
			}
		}
	}
	printf("Best Parameters\nBase No: %d, Table Size: %d\n",best_bno,best_tsize);
}

//Exercise-2

void createHashtable(){
	htable = (hashtable*)malloc(sizeof(hashtable));
	htable->elementCount=0;
	htable->insertionCost=0;
	htable->queryingCost=0;

	htable->records = (Record **)malloc(sizeof(Record*)*5000);
}

void insert(hashtable *ht,char **A,int j){
	int hashvalue = hashFn(A[j],5003,5000);
	
	Record *node = (Record*)malloc(sizeof(Record));
	node->index = j;
	node->count = 1;
	node->next = NULL;
	 
	if(htable->records[hashvalue]==NULL)
		htable->records[hashvalue]=node;
	else{
		Record* temp = htable->records[hashvalue];
		Record* temp1;
		int inC=0;
		while(temp!=NULL){
			inC++;
			if(strcmp(A[temp->index],A[j])==0){
				temp->count++;
				free(node);
				return;
			}
			if(temp->next==NULL)
				temp1 = temp;
			temp = temp->next;
		}
		ht->insertionCost += inC;
		temp1->next = node;		
	}		
}

int insertAll(hashtable *ht){
	for(int i=0;i<booksize;i++){
		insert(ht,book,i);
	}
	return ht->insertionCost;
}

Record* lookup(hashtable *ht,char* input){
	int hashvalue = hashFn(input,5003,5000);
	
	if(htable->records[hashvalue]==NULL)
		return NULL;
	else{
		Record* temp = htable->records[hashvalue];
		Record* temp1;
		int qC=0;
		while(temp!=NULL){
			qC++;
			if(strcmp(book[temp->index],input)==0){
				ht->queryingCost += qC;
				return temp;
			}
			temp = temp->next;
		}
		ht->queryingCost += qC;
		return NULL;		
	}	
}

int lookupall(hashtable *ht,char** arr,int arrsize,float m){
	int indexupto = (int)(m*arrsize);
	
	//Reset querying cost
	ht->queryingCost=0;
	
	Record *temp;
	
	for(int i=0;i<indexupto;i++){
		temp = lookup(ht,arr[i]);
	}
	printf("Querying Cost with m=%f : %d\n",m,ht->queryingCost);
	return ht->queryingCost;	
}

//Exercise-3

void hashtableProfiling(hashtable *ht){
	float m = 0.1;
	
	while(m<1){
		ht->queryingCost = lookupall(ht,book,booksize,m);
		if(ht->queryingCost>ht->insertionCost)
			break;
		m += 0.1;
	}
	printf("Value of m where queryingCost overtakes insertionCost: %f% \n",(m*100));
}

void cleanup(hashtable *ht,char **stopwords,int stopsize){
	Record *rec;
	for(int i=0;i<stopsize;i++){
		rec = lookup(ht,stopwords[i]);
		if(rec!=NULL){
			int hashvalue = hashFn(stopwords[i],5003,5000);
			Record *temp = ht->records[hashvalue];
			if(temp==rec){
				ht->records[hashvalue]=NULL;
			}
			else{
				while(temp->next!=rec){
					temp = temp->next;
				}
				temp = temp->next->next;
			}
			free(rec);
		}
	}
	
	hashtableProfiling(ht);
}

