#include<stdio.h>
struct process
{
	int start, finish, burst, arrival, wait, turn;
};
int main()
{
	struct process p[10];
	int n,i;
	float sumt, sumw;
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nFor process %d:\n",i+1);
		printf("Burst time:");
		scanf("%d",&p[i].burst);
		printf("Arrival time:");
		scanf("%d",&p[i].arrival);
	}
	p[0].start=p[0].arrival;
	sumt=0;
	sumw=0;
	printf("\n\tProcess\tBurst\tArrival\tWait\tTurn\n");
	for(i=0;i<n;i++)
	{
		p[i+1].start=p[i].finish=p[i].start+p[i].burst;
		p[i].wait=p[i].start-p[i].arrival;
		p[i].turn=p[i].finish-p[i].arrival;
		sumw =sumw + p[i].wait;
		sumt =sumt + p[i].turn;
		printf("\t%d\t%d\t%d\t%d\t%d\n",i,p[i].burst,p[i].arrival,p[i].wait,p[i].turn);
	}
	sumt= sumt/n;
	sumw=sumw/n;
	printf("Avg waiting time = %f\n",(sumw));
	printf("Avg turning time = %f\n",(sumt));
}
