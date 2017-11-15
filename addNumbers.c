
# include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pro[4];
	sum[4]={0,0,0,0};
	int status, res=0,i;
	int a[100];
	int k;
	int id;
	for (int j=0; j<100; j++)
	{
		a[j]=j;
	}

	for (i=0; i<4; i++)
  	{
		pro[i]=fork();
		if(pro[i]<0)
		{
			exit(EXIT_FAILURE);
		}
		else if(pro[i]==0)
		{
			for ( k=0; k<25; k++)
			{
				sum[0]=sum[0]+a[k];
			}
		}
		else if (pro[i]==1)
		{
			for (k=25; k<50; k++)
			{
				sum[1]=sum[1]+a[k];
			}
		}
		else if (pro[i]==2)
		{
			for(k=50; k<75; k++)
			{
				sum[2]=sum[2]+a[k];
			}
		}
		else if (pro[i]==3)
		{
			for ( k=75; k<100; k++)
			{
				sum[3]=sum[3]+a[k];
			}
		}
		else
		{
			printf("parent process");
		}
	for (i=0; i<4; i++)
	{
		pro[i]=wait(&status);
	}
	res=sum[0]+sum[1]+sum[2]+sum[3];
	printf("sum ", res);
	return 0;
}
}
