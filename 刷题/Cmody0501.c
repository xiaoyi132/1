
#include <stdio.h>
int main()
{

	int i,j,b[20][20];
	int m,n,sum;
	scanf_s("%d%d",&m,&n);
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			scanf_s("%d",&b[i][j]);
	sum=0;	
	for(i=0;i<n;i++){
		sum = 0;
		for (j=0;j<m;j++)
			sum=sum+b[j][i];
		printf("%d ",sum);		
	}

	return 0;
}
