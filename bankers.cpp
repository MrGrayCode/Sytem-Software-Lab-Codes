/*
* Ebey Abraham
* Implementation of Bankers Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > getMatrix(int m,int n)
{
	vector< vector<int> > res(m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			res[i].push_back(x);
		}
	}
	return res;
}

vector< vector<int> > getNeed(vector< vector<int> > max,vector< vector<int> > alloc,int p,int r)
{
	vector< vector<int> > res(p);
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			int x = max[i][j]-alloc[i][j];
			res[i].push_back(x);
		}
	}
	return res;
}

bool isLess(vector<int> need, vector<int> work)
{
	int n = need.size();
	for(int i=0;i<n;i++)
	{
		if(need[i]>work[i])
		{
			return false;
		}
	}
	return true;
}

int addTo(vector<int>* work, vector<int> alloc)
{
	int n = alloc.size();
	for(int i=0;i<n;i++)
	{
		(*work)[i] += alloc[i];
	}
	return 0;
}

bool isSafe(vector<int> process,vector<int> avail, vector< vector<int> > max, vector< vector<int> > alloc,int p,int r)
{
	vector< vector<int> > need(p);
	need = getNeed(max,alloc,p,r);
	cout<<"\nNEED\n";
	for(int i=0;i<p;i++)
	{
		cout<<need[i][0]<<" "<<need[i][1]<<" "<<need[i][2]<<endl;
	}
	
	bool finish[p] = {false};
	vector<int> safeseq;
	
	vector<int> work;
	work = avail;
	
	int count = 0;
	while(count<p)
	{
		bool found = true;
		for(int i=0;i<p;i++)
		{
			if(!finish[i])
			{
				if(isLess(need[i],work))
				{
					addTo(&work,alloc[i]);
					safeseq.push_back(i);
					count++;
					finish[i] = true;
					found = true;
				}
			}
		}
		if(!found)
		{
			cout<<"System is not in safe state!\n";
			return false;
		}
	}
	cout<<"\nSystem is in safe state\n";
	for(int i=0;i<p;i++)
	{
		cout<<safeseq[i]<<" ";
	}
	cout<<endl;
	
	return true;
}

int main()
{
	int p,r;
	//cout<<"Enter number of processes: ";
	cin>>p;
	//cout<<"Enter number of resources: ";
	cin>>r;
	
	// input processes
	vector<int> process;
	for(int i=0;i<p;i++)
	{
		process.push_back(i);
	}
	
	// input available
	vector<int> avail;
	for(int i=0;i<r;i++)
	{
		int x;
		cin>>x;
		avail.push_back(x);
	}
	cout<<"AVAIL\n";
	cout<<avail[0]<<" "<<avail[1]<<" "<<avail[2]<<endl;
	
	//input max
	vector<vector<int> > max;
	max = getMatrix(p,r);
	cout<<"\nMAX\n";
	for(int i=0;i<p;i++)
	{
		cout<<max[i][0]<<" "<<max[i][1]<<" "<<max[i][2]<<endl;
	}
	
	// input alloc
	vector<vector<int> > alloc(p);
	alloc = getMatrix(p,r);
	cout<<"\nALLOC\n";
	for(int i=0;i<p;i++)
	{
		cout<<alloc[i][0]<<" "<<alloc[i][1]<<" "<<alloc[i][2]<<endl;
	}
	
	isSafe(process,avail,max,alloc,p,r);
	
	return 0;
}
