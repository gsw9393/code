#include <stdio.h>
#include <string.h>
#define L 1024//Max char length of print output
#define N 6//Number of rolls of die
#define MIN 1//Lowest number on die
#define MAX 9//Highest number in die
#define INVALID 666


int takeInput(int a[N]);
//^ Take input, check validity and store in array
void ruleTotal(int a[N],char printString[L],int *finalScr);
//^ Check Rule-Total and print in array if high score
void ruleMatch(int a[N], char printString[L],int *finalScr);
//^ Check Rule-Match and print in array if high score
void ruleSequence(int a[N],char printString[L],int *finalScr);
//^ Check Rule-Sequence and print in array if high score
void ruleSum2(int a[N],char printString[L],int *finalScr);
void ruleSum3(int a[N],char printString[L],int *finalScr);
void ruleSum4(int a[N],char printString[L],int *finalScr);
void ruleSum5(int a[N],char printString[L],int *finalScr);
void ruleTimtam(int a[N],char printString[L],int *finalScr);

int main(void){
	freopen("c.txt", "r", stdin);
	int scoreFinal=0;
	int *s=&scoreFinal;
	char p[L]={0};//This stores the desired output to be printed
	int x[N]={0};
	
	if (takeInput(x)!=INVALID){

		ruleTimtam(x,p,s);
		ruleTotal(x,p,s);
		ruleSum2(x,p,s);
		ruleSum3(x,p,s);
		ruleSum4(x,p,s);
		ruleSum5(x,p,s);
		ruleSequence(x,p,s);
		ruleMatch(x,p,s);
		fputs(p,stdout);//Prints the String
	}
	
return 0;
}

// Take and check validity of input
int takeInput(int a[N]){
		
	int i;
	int j=MIN;//used in loop for checking non descending
	int errorCheck = 0;
	
	//Loop for taking and checking input	
	for (i=0;i<N; i+=1){	
		//checking for missing input, non decending, limits
		if(scanf("%d",&a[i])==1 && a[i]>=j && a[i]<=MAX){
			j=a[i];
		}else{
			//print error message
			printf("Invalid input: 6 integers 1..9 in sorted order must be supplied.\n");
			errorCheck = INVALID;
			break;
		}
	}
return errorCheck;
}

void ruleTotal(int a[N],char printString[L],int *finalScr){
	
	int i,score=0;
	
	for (i=0;i<N; i++){
		score=score+a[i];
	}
	if (*finalScr<=score){
		*finalScr=score;
		//printString[L]={0};
		
		sprintf(printString,"Rule total - score %d.\n",*finalScr);
/*DEBUG
		printf("DEBUG Rule Total ");
		for (i=0;i<N-1; i++){
			printf("%d+",a[i]);
		}
		printf("%d=%d\n",a[N-1],score);			
*/
	}
}

void ruleMatch(int a[N],char printString[L],int *finalScr){
	int i,j;
	int score=0;
	int l=0,m=0;
	
	//Logic used: e.g. for match-4
	//if element a[0]=a[3] then a[0]=a[1]=a[2]=a[3]
	//similar for match2-match6
	
	for (i=1;i<=N-1; i++){
		//Loop for checking match2 (i=1)to match6 (i=5)
	
		for (j=0;j<N-i; j++){
			//Loop for checking pairs e.g. for match-4
			//checking if a[0]==a[3] or a[1]==a[4] or a[2]==a[5] ...
			if ( a[j]==a[j+i]//check if element equal
			  && score<(1+i)*a[j]+17+(2*i)){//keeping high score only
				score=(1+i)*a[j]+17+(2*i);//if higher update
				l=i+1;//l=Match length
				m=a[j];//m=Largest match integer
			}	
		}				
	}
	if (*finalScr<=score){
	
		*finalScr=score;
		//printString[L]={0};

		sprintf(printString,"Rule match-%d(%d) - score %d.\n",l,m,score);
//DEBG
		//printf("DEBUG Rule Match score %d*%d+%d=%d\n",l,m,n,score);
	}
}

//Check Rule-Sequence and print if high score
void ruleSequence(int a[N],char printString[L],int *finalScr){
	int h,i, j = 1;
	int k=0;
	//a[0],a[1],a[2],a[3],a[4],a[5] 1 3 4 7 7 9
	for (i=0;i<=N-2; i+=1){
	 //Loop for checking sequence2 (i=0)to sequence6 (i=4)
		for(h=i+1; h<=N-1; h+=1){
			if ((a[i]+j)==a[h]){
				//if in sequence track sequence length with j
				j+=1;	
				if (*finalScr<=j*(a[h])+15+j){
					//updates score in higher
					*finalScr = j*(a[h])+15+j;
					sprintf(printString,"Rule sequence-%d(",j);
					for (k=a[h]-j+1;k<a[h]; k+=1){
						sprintf(printString+strlen(printString),"%d,",k);
					}
					sprintf(printString+strlen(printString),"%d) - score %d.\n",k,*finalScr);
				}
			}
		}
		j=1;
	}
}

void ruleSum2(int a[N],char printString[L],int *finalScr){
	//a[0],a[1],a[2],a[3],a[4],a[5]
	int s=2;
	int i,j,k;

	for(k=0; k<=3; k++){
		for(j=k+1; j<=4; j++){
			for(i=j+1; i<=5; i++){
				if(a[k]+a[j]==a[i]
					&& *finalScr<=a[k]+a[i]+14+s*(s+2)){
					
					*finalScr=a[k]+a[i]+14+s*(s+2);

					sprintf(printString,"Rule sum-%d(%d+%d=%d) - score %d.\n",s,a[k],a[j],a[i],*finalScr);
				}		
			}
		}
	}
}
void ruleSum3(int a[N],char printString[L],int *finalScr){
	//a[0],a[1],a[2],a[3],a[4],a[5]
	int s=3;
	int i,j,k,l;

	for (l=0; l<=2; l++){
		for (k=l+1; k<=3; k++){
			for(j=k+1; j<=4; j++){
				for(i=j+1; i<=5; i++){
					if(a[l]+a[k]+a[j]==a[i]
						&& *finalScr<=a[l]+a[i]+14+s*(s+2)){
						
						*finalScr=a[l]+a[i]+14+s*(s+2);
						sprintf(printString,"Rule sum-%d(%d+%d+%d=%d) - score %d.\n",s,a[l],a[k],a[j],a[i],*finalScr);
					}		
				}
			}
		}
	}
}
void ruleSum4(int a[N],char printString[L],int *finalScr){
	//a[0],a[1],a[2],a[3],a[4],a[5]
	int s=4;
	int i,j,k,l,m;
	
	for (m=0; m<=1; m++){
		for (l=m+1; l<=2; l++){
			for (k=l+1; k<=3; k++){
				for(j=k+1; j<=4; j++){
					for(i=j+1; i<=5; i++){
						if(a[m]+a[l]+a[k]+a[j]==a[i]
							&& *finalScr<=a[m]+a[i]+14+s*(s+2)){
							
							*finalScr=a[m]+a[i]+14+s*(s+2);
							sprintf(printString,"Rule sum-%d(%d+%d+%d+%d=%d) - score %d.\n",s,a[m],a[l],a[k],a[j],a[i],*finalScr);
						}		
					}
				}
			}
		}
	}
}
void ruleSum5(int a[N],char printString[L],int *finalScr){
	//a[0],a[1],a[2],a[3],a[4],a[5]
	int s=5;
	int i,j,k,l,m,n;

	for (n=0; n<=1; n++){
		for (m=n+1; m<=1; m++){
			for (l=m+1; l<=2; l++){
				for (k=l+1; k<=3; k++){
					for(j=k+1; j<=4; j++){
						for(i=j+1; i<=5; i++){
							if(a[n]+a[m]+a[l]+a[k]+a[j]==a[i]
								&& *finalScr<=a[n]+a[i]+14+s*(s+2)){
								
								*finalScr=a[n]+a[i]+14+s*(s+2);
								sprintf(printString,"Rule sum-%d(%d+%d+%d+%d+%d=%d) - score %d.\n",s,a[n],a[m],a[l],a[k],a[j],a[i],*finalScr);
							}		
						}
					}
				}
			}
		}
	}
}

void ruleTimtam(int a[N],char printString[L],int *finalScr){
	//a[0],a[1],a[2],a[3],a[4],a[5]
	//  2    2    4    6    7    9
	int i,j,k;
	int tmp1,tmp2,tmp3;
	int k2,j2,i2;

	for(k=0; k<=3; k++){
		for(j=k+1; j<=4; j++){
			for(i=j+1; i<=5; i++){
				if(a[k]+a[j]==a[i]){
					
					tmp1=a[k];
					tmp2=a[j];
					tmp3=a[i];
					
					k2=k;
					j2=j;
					i2=i;

					a[k]=-100;
					a[j]=-100;
					a[i]=-100;
					//a[0],a[1],a[2],a[3],a[4],a[5]
					//  2    2    4    6    7    9
					for(k=0; k<=3; k++){
						for(j=k+1; j<=4; j++){
							for(i=j+1; i<=5; i++){
								if(a[k]+a[j]==a[i]
								&& *finalScr<=tmp1+2*tmp2+3*tmp3+4*a[k]+5*a[j]+6*a[i]){
					
								*finalScr=tmp1+2*tmp2+3*tmp3+4*a[k]+5*a[j]+6*a[i];
								
								sprintf(printString,"Rule tim-tam(%d+%d=%d,%d+%d=%d) - score %d.\n",tmp1,tmp2,tmp3,a[k],a[j],a[i],*finalScr);
					
								//printf("DEBUG Rule timtam-%d(%d+%d=%d,%d+%d=%d) - score %d.\n",s,tmp1,tmp2,tmp3,a[k],a[j],a[i],*finalScr);
								}
							}
						}
					}
					k=k2;
					j=j2;
					i=i2;
					a[k]=tmp1;
					a[j]=tmp2;
					a[i]=tmp3;
				}		
			}
		}
	}
}