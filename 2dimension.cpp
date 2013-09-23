#include<stdio.h>
#include<stdlib.h>
int max(int rowstart,int **num,int length,int width){
	int i,rowend;
	int sumcombine=0;
	int *numcopy;
	int maxofaa=0;
	numcopy=(int *)malloc(sizeof(int)*width);
	for(i=0;i<width;i++){
		numcopy[i]=0;
	}
	
	for(rowend=rowstart;rowend<length;rowend++){
		for(i=0;i<width;i++){
			numcopy[i]=numcopy[i]+num[rowend][i];
		}
		int breakpoint=0, maxinperiod=0, maxofall=0, addornot=0,breakornot=0;
		int singlemax=numcopy[0];
		for(i=0;i<width;i++){
			if(singlemax<numcopy[i]){
				singlemax=numcopy[i];
			}
			if(maxinperiod==0){
				if(numcopy[i]>0){
					maxinperiod=numcopy[i];
					breakornot=numcopy[i];
				}
				continue;
			}
			addornot=addornot+numcopy[i];
			if(addornot>=0){
				maxinperiod=maxinperiod+addornot;
				addornot=0;
			}
			breakornot=breakornot+numcopy[i];
			if(breakornot<=0||i==width-1){
				if(maxofall<maxinperiod)
					maxofall=maxinperiod;
				maxinperiod=0;
			}
		}
		if(singlemax<0){
			maxofall=singlemax;
		}
		if(rowend==rowstart){
			maxofaa=maxofall;
		}
		else if(maxofaa<maxofall){
			maxofaa=maxofall;
		}
	}
	return maxofaa;
}
void main(int agrc, char** argv){
	int **num;
	int startrow,length,width;
	int i,j;
	scanf("%d%d",&length,&width);
	num=(int **)malloc(sizeof(int*)*length);
	for(i=0;i<width;i++)
		num[i]=(int *)malloc(sizeof(int)*width);
	for(i=0;i<length;i++){
		for(j=0;j<width;j++){
			scanf("%d",&num[i][j]);
		}
	}
	int maxofmatrix;
	for(startrow=0;startrow<length;startrow++){
		int midmax=max(startrow,num,length,width);
		if(startrow==0)
			maxofmatrix=midmax;
		else if(maxofmatrix<midmax){
			maxofmatrix=midmax;
		}
	}
	printf("the max sum of a square is: %d\n",maxofmatrix);
	system("pause");
}