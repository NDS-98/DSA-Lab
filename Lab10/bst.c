#include "bst.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>



void add_bst(int val){
	Node * node = (Node*)malloc(sizeof(Node));
	node->value = val;
	node->left = NULL;
	node->right = NULL;
	node->height_info = 0;
	
	if(head==NULL){
		head = node;
	}
	else{
		Node* temp = head;
		while(1){
			if(val<=temp->value){
				if(temp->left!=NULL)
					temp = temp->left;
				else{
					temp->left = node;
					temp = temp->left;
					break;
				}
			}
			else if(val>temp->value){
				if(temp->right!=NULL)
					temp = temp->right;
				else{
					temp->right = node;
					temp = temp->right;
					break;
				}
			}
		}
		// Now modifying the height_info of each node lying in the path from newly added node to the root.
		while(temp!=NULL){    //NULL when it reaches parent of root node.
			int diff = height_diff(temp);
			if(diff>0)
				temp->height_info = 1;
			else if(diff<0)
				temp->height_info = -1;
			else
				temp->height_info = 0;
			temp = parent_of(temp->value);
		}
	}	
}


int height_diff(Node* node){ //Return the diff in height of left and right subtrees of node.(R-L)
	int left_st_height = height(node->left);
	int right_st_height = height(node->right);
	
	return right_st_height-left_st_height;
}

int max(int a,int b){
	return (a>b)?a:b;	
}

int height(Node* node){
	if(node==NULL)
		return -1;
	int left_h = height(node->left);
	int right_h = height(node->right);
	return max(left_h,right_h)+1;
}

Node* find(int val){
	Node* temp = head;
	while(temp!=NULL){
		if(val==temp->value){
			return temp;  //Found
		}
		else if(val>temp->value)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return NULL;  //Not Found
}

Node* parent_of(int val){
	if(val==head->value)
		return NULL;
	
	Node* temp = head;
	Node* temp1;
	if(val<temp->value)
		temp1 = temp->left;
	else if(val>temp->value)
		temp1 = temp->right;
		
	while(temp1!=NULL){
		if(val==temp1->value){
			return temp; 
		}
		else if(val>temp1->value){
			temp = temp1;
			temp1 = temp1->right;
		}
		else{
			temp = temp1;
			temp1 = temp1->left;
		}
	}
	return NULL; //Val not present, hence parent is NULL	
}

Node* grandparent_of(int val){
	if(parent_of(val)==NULL)
		return NULL;
	return parent_of(parent_of(val)->value);
}

Node* find_min(Node* start){ //Find min element of tree whose head is start
	Node* temp = start;
	while(temp->left!=NULL){
		temp = temp->left;
	}
	return temp;
}

Node* successor(int val){
	Node* temp = find(val);
	if(temp->right!=NULL)
		return find_min(temp->right);
	else{
		Node* par = parent_of(temp->value);
		while(par!=NULL && temp==par->right){
			temp = par;
			par = parent_of(temp->value);
		}
		return par;
	}
}

void delete(int val){
	if(find(val)==NULL){
		printf("Value to be deleted not present in tree!\n");
		return;
	}
	//3 cases
	
	//Case1 - If val is a leaf node
	Node* temp = find(val);
	Node* parent = parent_of(val);
	
	
	if(temp->left==NULL && temp->right==NULL){
		if(temp==head)
			head=NULL;
		else if(parent->left==temp)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(temp);
	}
	
	//Case2 - If val has one child
	else if(temp->left==NULL || temp->right==NULL){
		Node* child;
		if(temp->left==NULL)
			child = temp->right;
		else
			child = temp->left;
		if(temp==head)
			head = child;
		else if(parent->left==temp)
			parent->left = child;
		else
			parent->right = child;
		free(temp);
	}
	
	//Case3 - If val has 2 children
	else{
		Node* succ = successor(temp->value);
		int v = succ->value;
		delete(succ->value);
		temp->value = v;
	}
}

void rotate(Node* X,Node* Y,Node* Z){
	// 4 cases: Z is point of imbalance

	Node *a,*b,*c;
	Node *T0,*T1,*T2,*T3;

	//Case 1: Right child of right subtree
	if(Y->right==X && Z->right==Y){
		a = Z;
		b = Y;
		c = X;
		T1 = b->left;
		T2 = c->left;
	}
	//Case 2: Left child of left subtree
	else if(Y->left==X && Z->left==Y){
		a = X;
		b = Y;
		c = Z;
		T1 = a->right;
		T2 = b->right;
	}
	//Case 3: Left child of right subtree
	else if(Y->left==X && Z->right==Y){
		a = Z;
		b = X;
		c = Y;
		T1 = b->left;
		T2 = b->right;
	}
	//Case 4: Right child of left subtree
	else if(Y->right==X && Z->left==Y){
		a = Y;
		b = X;
		c = Z;
		T1 = b->left;
		T2 = b->right;
	}

	T0 = a->left;
	T3 = c->right;

	if(parent_of(Z->value)==NULL){ //Only root has NULL parent
		head = b;
	}
	else{
		if(parent_of(Z->value)->right==Z){
			parent_of(Z->value)->right = b;
		}
		else if(parent_of(Z->value)->left==Z){
			parent_of(Z->value)->left = b;
		}
	}
	b->left = a;
	b->right = c;
	a->left = T0;
	a->right = T1;
	c->left = T2;
	c->right = T3;
}

void add_avl(int val){
	add_bst(val);

	Node* temp = parent_of(val);
	
	if(temp==NULL)
		return;
		
	if(temp->right->value==val)
			temp = temp->right;
	else
			temp = temp->left;

	while(grandparent_of(temp->value)!=NULL){
		if(abs(height_diff(grandparent_of(temp->value)))>1){
			rotate(temp,parent_of(temp->value),grandparent_of(temp->value));
		}
		temp = parent_of(temp->value);
	}
}

void delete_avl(int val){
	Node *temp =parent_of(val);
	if(temp==NULL)
		temp = head;

	delete(val);
	temp = head;
	while(!(temp->left==NULL && temp->right==NULL)){  
		if(height_diff(temp)>=0){
			if(temp->right!=NULL)
				temp = temp->right;
		}
		else{
			if(temp->left!=NULL)
				temp = temp->left;
		}
	}

	// Now temp is the node whose grandparent can be a point of imbalance.

	while(grandparent_of(temp->value)!=NULL){
		if(abs(height_diff(grandparent_of(temp->value)))>1){
			rotate(temp,parent_of(temp->value),grandparent_of(temp->value));
		}
		temp = parent_of(temp->value);
		if(temp==NULL)
			break;
	}
}

//Exercise-2

int kthSmallest(Node *start,int k){
// Initialize count=0 in main
	if(start==NULL)
		return INT_MIN;

	int value1 = kthSmallest(start->left,k);
	count++;
	if(count==k)
		return start->value;
	int value2 = kthSmallest(start->right,k);

	return max(value1,value2);
}


void rangeSearch(Node* start,int k1,int k2){
	if(start==NULL)
		return;
	if(start->value>k2)
		rangeSearch(start->left,k1,k2);
	else if(start->value<k1)
		rangeSearch(start->right,k1,k2);
	else{
		rangeSearch(start->left,k1,start->value);
		rangeQueryResult[noOfElements++] = start->value;
		rangeSearch(start->right,start->value,k2);
	}
}
