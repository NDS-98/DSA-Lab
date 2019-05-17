#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
	/*add_bst(10);
	add_bst(11);
	add_bst(12);
	
	Node *temp = find_min(head);
	printf("%d\n",temp->value);*/
	
	head = NULL;
	
	add_avl(1);
	add_avl(3);
	add_avl(5);
	add_avl(7);
	add_avl(9);
	add_avl(11);
	add_avl(13);
	add_avl(15);
	add_avl(17);
	//tree = add(tree,4);

	printf("root - %d \n",head->value);
	printf("root left- %d \n",head->left->value);
	printf("root right- %d \n",head->right->value);

	Node *node;
	int key = 15;
	while(key>=1){
		node = find(key);
		if(node==NULL){
			printf("%d not found in tree\n",key);
		}else{
			printf("%d found with height %d  in tree\n",key, height(node));
		}
		key -=2;
	}
	//inorder(tree,3,0);
	// int *arr = rangeSearch(tree,5,10);
	// for(int i=0;i<arr[0];i++){
		// printf("%d\n",arr[i+1]);
	// }
		
	delete_avl(5);
	delete_avl(7);
	delete_avl(1);

	printf("AFTER delete\n");
	key = 17;
	while(key>=1){
		node = find(key);
		if(node ==NULL){
			printf("%d not found in tree\n",key);
		}else{
			printf("%d found with height %d  in tree\n",key, height(node));
		}
		key-=2;
	}

	int ks = kthSmallest(head,4);
	printf("4th Smallest: %d\n",ks);
	
	rangeQueryResult = (int*)malloc(sizeof(int)*20);
	noOfElements=0;
	rangeSearch(head,1,17);
	for(int j=0;j<noOfElements;j++){
		printf("%d ",rangeQueryResult[j]);	
	}
}
