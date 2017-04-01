#include<iostream>
using namespace std;
struct pstruct
{
        int fno;
        int pbit;
}ptable[10];

int pmsize,lmsize,psize,frame,page,ftable[20],frameno;

void info()
{
        cout<<"Memory Management Unit\n";
        cout<<"\nEnter the size of physical memory: ";
        cin>>pmsize;
        cout<<"\nEnter the size of Logical memory: ";
        cin>>lmsize;
        cout<<"\nEnter the partition size: ";
        cin>>psize;
        frame=(int)pmsize/psize;
        page=lmsize/psize;
        cout<<"\nThe physical memory is divided into "<<frame<<" no.of frames";
        cout<<"\nThe Logical memory is divided into "<<page<<" no.of pages";
}

void assign()
{
        int i;
        for (i=0;i<page;i++)
        {
                ptable[i].fno = -1;
                ptable[i].pbit= -1;
        }
        for(i=0; i<frame;i++)
        {ftable[i] = 32555;}
	
	 for (i=0;i<page;i++)
        {
                cout<<"\nEnter the frame number where page "<<i<<" must be placed: ";                
		cin>>frameno;
                ftable[frameno]=i;
                if(ptable[i].pbit==-1)
                {
                        ptable[i].fno=frameno;
                        ptable[i].pbit=1;
                }
        }
        
	cout<<"\n\nPAGE TABLE\n\n";
        cout<<"PageAddress FrameNo. PresenceBit\n\n";
        for (i=0;i<page;i++)
        {cout<<i<<"\t\t"<<ptable[i].fno<<"\t\t"<<ptable[i].pbit<<endl;}

        cout<<"\n\n\n\tFRAME TABLE\n\n";
        cout<<"FrameAddress PageNo\n\n";

        for(i=0;i<frame;i++)
        {cout<<i<<"\t\t"<<ftable[i]<<endl;}
}

void phyaddress()
{
        int laddr,paddr,disp,phyaddr,baddr;
                cout<<"\n\n\n\tProcess to create the Physical Address\n\n";
                cout<<"\nEnter the Base Address: ";
                cin>>baddr;
                cout<<"\nEnter the Logical Address: ";
                cin>>laddr;
                paddr = laddr / psize;
                cout<<"Enter the displacement: ";
		cin>>disp;
                if(ptable[paddr].pbit == 1 )
                {phyaddr = baddr + (ptable[paddr].fno*psize) + disp;}
		cout<<"\nThe Physical Address where the instruction present is: "<<phyaddr<<endl;
}
int main()
{info();assign();phyaddress();}

