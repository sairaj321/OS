#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[],char *en[])
{
 int i,j,c,arr[argc],ele,n;
 
 for(j=0;j<argc-1;j++)
 {
 n=atoi(argv[j]);
 arr[j]=n;
 }
 ele=atoi(argv[j]);
 i=0;j=argc-1;
 c=(i+j)/2;
 while(arr[c]!=ele & i<=j)
 {
 if(ele>arr[c])
 i=c+1;
 else
 j=c-1;
 c=(i+j)/2;
 }
 if(i<=j)
 printf("\n Element found in given array");
 else
 printf("\n Element not found in given array");
 return 0;
}