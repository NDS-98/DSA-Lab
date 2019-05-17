typedef struct node Node;

struct node{
int value;
Node* left;
Node* right;
int height_info:2;
};

Node *head;
int count; //count for kth smallest element

int max(int a,int b);

int *rangeQueryResult; //Array to store result of range query
int noOfElements;

void add_bst(int val);

int height_diff(Node* node);
int height(Node* node);

Node* find(int val);

Node* parent_of(int val);
Node* find_min(Node* start);

Node* successor(int val);

void delete(int val);

void rotate(Node* X,Node* Y,Node* Z);

void add_avl(int val);

void delete_avl(int val);

int kthSmallest(Node *start,int k);

void rangeSearch(Node* start,int k1,int k2);
