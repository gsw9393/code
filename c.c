#include <stdio.h>

typedef unsigned long long int bigint;
bigint maxnum(char* s);

int main (int argc, char *argv[]){
	
	unsigned int i=0;
	unsigned int j=1;
	//while(j>i){
	//	i++;
	//	j++;
	//}
	int k = sizeof(i);
	bigint l=maxnum("unsigned int");
	bigint ul=(l/2);
	//printf ("%d bytes: %lu...%lu \n",k,j,i);
	printf ("unsigned: 0...%llu\nsigned: -%llu...%llu",(l-1),ul,ul-1);
	//int x=2147483648;
	//printf ("%d",x);
	return 0;
}
bigint maxnum(char *s){
	bigint ans=1;
	int n=sizeof(s);
	int i;
	for (i=0 ; i<n ; i+=1){
		ans = ans*256;	
	}
	return ans;
}