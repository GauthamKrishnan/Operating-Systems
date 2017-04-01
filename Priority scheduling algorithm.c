#include<stdio.h>
struct process
{
        int pri, id, start, finish, burst, arrival, wait, turn;
};
int main()
{
        struct process p[10];
        struct process temp;
        int n,i,j;
        float sumt, sumw;
        printf("\nEnter number of processes: ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nFor process %d:\n",i+1);
                printf("Burst time:");
                scanf("%d",&p[i].burst);
                printf("Priority:");
                scanf("%d",&p[i].pri);
                p[i].id=i+1;
                p[i].arrival=0;
        }
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(p[i].pri>p[j].pri)
                        {
                                temp=p[i];
                                p[i]=p[j];
                                p[j]=temp;
                        }
                }
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
                printf("\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].burst,p[i].arrival,p[i].wait,p[i].turn);
        }
        sumt= sumt/n;
        sumw=sumw/n;
        printf("Avg waiting time = %f\n",(sumw));
        printf("Avg turning time = %f\n",(sumt));
}
