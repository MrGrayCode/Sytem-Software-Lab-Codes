#include<bits/stdc++.h>
using namespace std;

int fcfs(vector<int> req, int n,int head)
{
	int seektime = 0;
	if(head!=req[0])
	{
		cout<<head;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"->"<<req[i];
		if(i>0)
		{
			seektime += abs(req[i]-req[i-1]);
		}
		else
		{
			seektime += abs(req[0]-head);
		}
	}
	
	cout<<"\nSeek Time = "<<seektime<<endl;
	
	return 0;
}

int scan(vector<int> req, int n, int head)
{
	int seektime = 0;
	sort(req.begin(),req.end());
	int pos = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(req[i]<=head)
		{
			pos = i;
			break;
		}
	}
	
	if(head!=req[0])
	{
		cout<<head;
	}
	
	for(int i=pos;i>=0;i--)
	{
		cout<<"->"<<req[i];
		if(i!=pos)
		{
			seektime += abs(req[i]-req[i+1]);
		}
		else
		{
			seektime += abs(req[pos]-head);
		}
		//cout<<endl<<seektime<<endl;
	}
	for(int i=pos+1;i<n;i++)
	{
		cout<<"->"<<req[i];
		if(i!=pos+1)
		{
			seektime += abs(req[i]-req[i-1]);
		}
		else
		{
			seektime += abs(req[0]-req[i]);
		}
		//cout<<endl<<seektime<<endl;
	}
	
	cout<<"\nSeek Time = "<<seektime<<endl;
	return 0;
}

int cscan(vector<int> req, int n, int head)
{
	int seektime =0;
	sort(req.begin(),req.end());
	int pos = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(req[i]<=head)
		{
			pos = i;
			break;
		}
	}
	
	if(head!=req[0])
	{
		cout<<head;
	}
	
	for(int i=pos;i>=0;i--)
	{
		cout<<"->"<<req[i];
		if(i!=pos)
		{
			seektime += abs(req[i]-req[i+1]);
		}
		else
		{
			seektime += abs(req[i]-head);
		}
	}
	for(int i=n-1;i>pos;i--)
	{
		cout<<"->"<<req[i];
		if(i!=n-1)
		{
			seektime += abs(req[i]-req[i+1]);
		}
		else
		{
			//seektime += abs(req[i]-req[0]);
		}
	}
	
	cout<<"\nSeek Time = "<<seektime<<endl;
	return 0;
}


int main()
{
	int n;
	//cout<<"Enter number of requests: ";
	cin>>n;
	
	vector<int> req(n);
	//cout<<"Enter requests:"
	for(int i=0;i<n;i++)
	{
		cin>>req[i];
	}
	
	cout<<"Input Queue:\n";
	for(int i=0;i<n;i++)
	{
		cout<<req[i]<<" ";
	}
	cout<<"\n\n";
	
	int head;
	//cout<<"Enter head: ";
	cin>>head;
	
	cout<<"HEAD ="<<head<<"\n\n";
	
	cout<<"FCFS:\n";
	fcfs(req,n,head);
	
	cout<<"\n\n";
	
	cout<<"SCAN:\n";
	scan(req,n,head);
	
	cout<<"\n\n";
	
	cout<<"C-SCAN:\n";
	cscan(req,n,head);
	
	cout<<endl;
	return 0;
}
