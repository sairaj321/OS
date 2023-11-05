#include<stdio.h>
# define m 100

void bankers(int need[m][m],int avail[m],int alloc[m][m],int safe[m],int n,int r)
{
	int count=0,count1=0,i,j,k,p,flag;
	while(count1<n)
	{	
		
		for(i=0;i<n;i++)
		{
			flag=0;
			for(p=0;p<count1;p++)
			{
				if(i==safe[p])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				continue;
			}
			count=0;
			for(j=0;j<r;j++)
			{
				if(need[i][j]<=avail[j])
				{
					count++;
				}
				if(count==r)
				{
					safe[count1]=i;
					count1++;
					for(k=0;k<r;k++)
					{
						avail[k]=avail[k]+alloc[i][k];
					}
					break;
				}
			}
		}
	}
	printf("available resources\n");
	for(i=0;i<r;i++)
	{
		printf("%d\t",avail[i]);
	}
	printf("\nsafe list\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",safe[i]);
	}
}
void main()
{
	int alloc[100][100],max[100][100],avail[100],need [100][100],safe[100],i,j,n,r;
	printf("Enter no. of processes\n");
	scanf("%d",&n);	
	printf("Enter no. of resoureses\n");
	scanf("%d",&r);	
	for(i=0;i<n;i++)
	{
		printf("Enter allocated and max resorces for process %d \n",i);
		for(j=0;j<r;j++)
		{
			
			scanf("%d",&alloc[i][j]);
			scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}	 
	}
	
	printf("Enter available resources\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	
	bankers(need,avail,alloc,safe,n,r);
}