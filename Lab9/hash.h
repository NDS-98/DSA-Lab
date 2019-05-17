int hashFn(char* str,int baseNo,int tableSize);

int collisionCount(char** arr,int arrsize,int baseNo,int tableSize);

char** parser(char* filename);

void profiling(char** book);

typedef struct rec Record;
struct rec{
	int index;
	int count;
	Record* next;
};

typedef struct table hashtable;
struct table{
	int elementCount;
	int insertionCost;
	int queryingCost;
	Record **records;
};

char **book;
hashtable *htable; //Pointer to the hashtable

int booksize;

void createHashtable();

void insert(hashtable *ht,char **A,int j);

int insertAll(hashtable *ht);

int lookupall(hashtable *ht,char** arr,int arrsize,float m);

void hashtableProfiling(hashtable *ht);

void cleanup(hashtable *ht,char **stopwords,int stopsize);
