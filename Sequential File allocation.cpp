#include<iostream>
using namespace std;
struct file
{
	char name[10];
	int size;
	int start;
	int alloc;
}f[10];
int canAllocate(int m[100],int start,int size)
{
	int flag=1;
	for(int i=start;i<start+size;i++)
	{
		if(m[i]!=-1)
			flag=0;
	}	
	return(flag);
}
void allocate(int m[100],int start, int size, int file)
{
	for(int i=start;i<start+size;i++)
		m[i]=file;
}
int main()
{
	int i,n,blksize,totalmem,totalblk,filesize;
	cout<<"\nEnter total size of disk : ";
	cin>>totalmem;
	cout<<"\nEnter size of each block : ";
	cin>>blksize;
	totalblk=totalmem/blksize;
	cout<<"\nTotal no of blocks available: "<<totalblk;
	int memory[100];
	for(i=0;i<totalblk;i++)
		memory[i]=-1;
	cout<<"\nEnter no of files: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nFor file "<<i+1;
		cout<<"\nEnter name: ";
		cin>>f[i].name;
		cout<<"\nEnter file size: ";
		cin>>filesize;
		f[i].size=filesize/blksize;
		cout<<"\nEnter starting address (between 0 - "<<totalblk<<"): ";
		cin>>f[i].start;
		if(canAllocate(memory,f[i].start,f[i].size))
		{
			f[i].alloc=1;
			allocate(memory,f[i].start,f[i].size,i+1);
			cout<<"\nFile allocated.";
		}
		else
		{
			cout<<"\nCannot allocate file : "<<f[i].name;
			f[i].alloc=0;
		}
	}
	cout<<"\nAll files:\n";
	cout<<"\nFile No\t\tFile Name\tStarting Block\tNo of Blocks\tBlock Numbers\n";
	for(i=0;i<n;i++)
	{
		if(f[i].alloc==1)
		{
			cout<<i+1<<"\t\t"<<f[i].name<<"\t\t"<<f[i].start<<"\t\t"<<f[i].size<<"\t\t"<<f[i].start;
		for(int j=f[i].start+1;j<f[i].start+f[i].size;j++)
			cout<<", "<<j;
		cout<<endl;
		}
	}
}
