#include<stdio.h>
struct process
{
        int id, finish, burst, arrival, wait, turn, comp;
        int flag;
};
int main()
{
        struct process p[10];
        int slice;
        int n, i, j, count, ctime=0;
        float sumt, sumw;
        printf("\nEnter number of processes: ");
        scanf("%d",&n);
        count=n;
        printf("\nEnter the time slice: ");
        scanf("%d",&slice);
        for(i=0;i<n;i++)
        {
                printf("\nFor process %d:\n",i+1);
                printf("Burst time:");
                scanf("%d",&p[i].burst);
                p[i].id=i+1;
                p[i].arrival=0;
                p[i].flag=0;
                p[i].comp=0;
                p[i].wait=0;
                p[i].turn=0;
        }
        while(count>0)
        {
            for(i=0;i<n;i++)
            {
                if(p[i].flag==0)
                {
                    p[i].wait=p[i].wait+(ctime-p[i].comp);
                    if(p[i].burst<=slice)
                    {
                        ctime=ctime+p[i].burst;
                        p[i].burst=0;
                        p[i].finish=ctime;
                    }
				else
				{
                        ctime=ctime+slice;
                        p[i].burst=p[i].burst-slice;
				}
				p[i].comp=ctime;
				if(p[i].burst==0)
				{
					p[i].flag=1;
					count--;
				}
			}
		}
	}
        sumt=0;
        sumw=0;
        printf("\n\tProcess\tBurst\tArrival\tWait\tTurn\n");
        for(i=0;i<n;i++)
        {
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
