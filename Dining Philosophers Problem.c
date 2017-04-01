#include <stdio.h>
int wait(int S)
{
	while(S<=0);
		S--;
	return S;
}
int signal(int S)
{
	S++;
	return S;
}
int main() 
{
	int n,chopstick[30],p1,p2,eat[20];
	int k=0,j=0,i=0,flag[2]={0,0};
		
		printf("\nEnter the no. of philosopher's(Odd): ");
		scanf("%d",&n);
		printf("Enter two philospher's id: ");
		scanf("%d%d",&p1,&p2);
		
		if(p1<p2) i=p1;
			else  i=p2;

		for( j=0;j<n;j++)
		{chopstick[j]=1;}

		while(i<n)
		{
			if(chopstick[i]==1&&chopstick[(i+1)%n]==1)
			{
				chopstick[i]=wait(chopstick[i]);
				chopstick[(i+1)%n]=wait(chopstick[(i+1)%n]);
				eat[k]=i;
				k++;
			}
			i++;
		}

		for(j=0;j<k;j++)
		{
			if(eat[j]==p1)  flag[0]=1;
				else if(eat[j]==p2) flag[1]=1;
		}

		if(flag[0]==1) printf("\n%d Eats",p1);
			else   printf("\n%d Thinks",p1);

		if(flag[1]==1) printf("\n%d eats",p2);
			else   printf("\n%d thinks",p2);

		printf("\n\n\n THE PHILOSOPHER'S WHO CAN EAT AT THE SAME TIME:\n");

		for(j=0;j<k;j++)
		{printf("\t%d\n",eat[j]);}

		i=p1;
		printf("\n\n After eating:\n");

		while(i<n)
		{
			if(chopstick[i]==0&&chopstick[(i+1)%n]==0)
			{
				chopstick[i]=signal(chopstick[i]);
				chopstick[(i+1)%n]=signal(chopstick[(i+1)%n]);
				printf("\t%d --> thinks\n",i);
			}
			i++;
		}
		return 0;
}
 
