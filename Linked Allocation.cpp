#include<iostream>
using namespace std;
struct file
{
	char name[10];
	int size;
	int blocks[20];
	int alloc;
}f[10];
int canAllocate(int m[100],int size,int file)
{
	int flag=1,x;
	for(int i=0;i<size;i++)
	{
		x=f[file].blocks[i];
		if(m[x]!=-1)
			flag=0;
	}	
	return(flag);
}
void allocate(int m[100],int size, int file)
{
	int x;
	for(int i=0;i<size;i++)
	{	
		x=f[file].blocks[i];
		m[x]=file;
	}
}
int main()
{
	int i,j,n,blksize,totalmem,totalblk,filesize;
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
		cout<<"\nEnter the blocks in order (between 0 - "<<totalblk<<"): ";
		for(j=0;j<f[i].size;j++)
			cin>>f[i].blocks[j];
		if(canAllocate(memory,f[i].size,i))
		{
			f[i].alloc=1;
			allocate(memory,f[i].size,i);
			cout<<"\nFile allocated.";
		}
		else
		{
			cout<<"\nCannot allocate file : "<<f[i].name;
			f[i].alloc=0;
		}
	}
	cout<<"\nAll files:\n";
	cout<<"\nFile No\t\tFile Name\tNo of Blocks\tBlock Numbers\n";
	for(i=0;i<n;i++)
	{
		if(f[i].alloc==1)
		{
			cout<<i+1<<"\t\t"<<f[i].name<<"\t\t"<<f[i].size<<"\t\t"<<f[i].blocks[0];
		for(j=1;j<f[i].size;j++)
			cout<<"--->"<<f[i].blocks[j];
		cout<<endl;
		}
	}
}
