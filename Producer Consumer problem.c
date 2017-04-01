#include<stdio.h>
int bsize=5;
int a[5];
int counter=0;
int in=0,out=0;
void print()
{
	int i;
		for(i=out;i<in;i++)
		{ printf("\t%d",a[i]); }
}
void producer()
{
	int nextp;
		if ((in+1)%bsize == out)
		{ printf("\nBuffer is full"); }
		else
		{
			printf("Enter the element: ");
			scanf("%d",&nextp);
			a[in]=nextp;
			in=(in+1)%bsize;
			counter++;
		printf("\nElement inserted by producer");
		}
		print();
}
void consumer()
{
	int nextc;
		if (in == out)
		{ printf("\nBuffer empty"); }
		else
		{
			nextc=a[out];
			out=(out+1)%bsize;
			counter--;
		printf("\nElement removed by consumer");
		}
		print();
		
}
int main()
{
	int choice;
		do
		{
			printf("\nControl to producer or consumer?1/2: ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:{ producer(); printf("\nCounter is at %d",counter); } break;
				case 2:{ consumer(); printf("\nCounter is at %d",counter); } break;
			}
		}while(choice!=3);
}
 
