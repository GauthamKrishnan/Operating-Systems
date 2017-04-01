#include<iostream>
using namespace std;
int first=0,count=0;
int check(int q[10], int n, int target)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(q[i]==target)
			return 1;
	}
	return 0;
}
void addToTable(int q[10], int x, int n)
{
	if(n!=count)
	{
		q[count]=x;
		count++;
	}
	else
	{
		q[first]=x;
		first++;
		first=first%n;
	}
}
void dispTable(int q[10], int n)
{
	int i;
	cout<<"\n\nTable:\n";
	if(count!=n)
	{
	for(i=0;i<count;i++)
		cout<<"\t"<<q[i];
	}
	else
	{
	for(i=0;i<n;i++)
		cout<<"\t"<<q[i];
	}
}
int main()
{
	int p,hit=0,fault=0,table[10],n,ref[50],i;
	cout<<"\nEnter the number of frames:";
	cin>>n;
	for(i=0;i<n;i++)
		table[i]=-1;
	cout<<"\nEnter the no of processes:";
	cin>>p;
	cout<<"\nEnter the reference string:";
	for(i=0;i<p;i++)
		cin>>ref[i];
	for(i=0;i<p;i++)
	{
		cout<<"\nConsidering process: "<<ref[i];
		if(check(table,n,ref[i])==1)
			hit++;
		else
		{
			fault++;
			addToTable(table,ref[i],n);
		}
		dispTable(table,n);
	}
	cout<<"\nNo of hits = "<<hit;
	cout<<"\nNo of faults = "<<fault<<endl;
}
