#include "node.h"
BOOL IsLower_GM(int id1, int id2)
{
	int gn1 = id1%10000;
	int gn2 = id2%10000;
	
	int rem1 = id1/10000;
	int rem2 = id2/10000;
	
	int mn1 = rem1%1000;
	int mn2 = rem2%1000;
	
	if(gn1<gn2){
		return 1;
	}
	else if(gn1>gn2){
		return 0;
	}
	else{
		if(mn1<mn2)
			return 1;
		else
			return 0;
	}
}
