#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 500
int table[MAX]; //shift table
int shifts=0;
int comparisons=0;
void shiftTable(char p[]) { //function to generate shift table
	int i,j,m;
	m=strlen(p); //length of pattern
	for (i=0;i<MAX;i++)
		table[i]=m; //in the beginning, all shift values are initialized with pattern length
	for (j=0;j<m-1;j++)
		table[p[j]]=m-1-j; //characters occurring in the pattern have value corresponding to their distance from the last character
}
int horspool(char p[],char t[]){
	shiftTable(p); //to create shift table
	int m=strlen(p); //length of pattern
	int n=strlen(t); //length of sequence
	int i=m-1; 
	while(i<=n-1){
		int k=0;
		while(k<=m-1 && p[m-1-k]==t[i-k]){ //as long as k < length of pattern and pattern matches text
			k++; //increment k
			comparisons++;//number of comparisons when match is found
		}
		if(k==m)
			return i-m+1; //position at which pattern occurs
		else
			shifts++; //number of shifts
			comparisons++; //comparisons when match is not found
			i+=table[t[i]]; //make a shift corresponding to the last character in pattern
		}
	return -1;
}





void main() {
	char t[100],p[100];
	int pos;
	printf("Enter the DNA sequence in which the pattern is to be searched:\n");
	gets(t);
	printf("Enter the pattern to be searched:\n");
	gets(p);
	pos=horspool(p,t);
	if(pos>=0)
	  printf("The desired pattern was found starting from position %d\n",pos+1);
       	else
	  printf("The pattern was not found in the given text.\n");
	printf("The number of compariosns made: %d\n",comparisons);
	printf("The number of shifts made: %d\n",shifts);
}
