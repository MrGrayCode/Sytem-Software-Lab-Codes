/*
Ebey Abraham
S5 - CSE
*/

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int main()
{
	int n;
	int i = 0;
	int j = 0;
	//printf("Enter number of processes: ");
	scanf("%d",&n);
	
	int burstTime[n];
	int remainingTime[n];
	int arrivalTime[n];
	int priority[n];
	bool check[n];
	int TAT[n];
	int WT[n];
	
	int totalTime = 0;
	
	//printf("Enter burst time of each process:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burstTime[i]);
		remainingTime[i] = burstTime[i];
		check[i] = true;
		TAT[i] = 0;
		WT[i] = 0;
	}
	
	//printf("Enter arrival time of each process:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arrivalTime[i]);
	}
	
	//printf("Enter priority of each process:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&priority[i]);
	}
	
	/*
	printf("Process No\t\tBurst Time\t\tArrival Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\n",i+1,burstTime[i],arrivalTime[i]);
	}
	
	printf("\n\n");
	*/
	
	
	int currentTime;
	int minPriority;
	int minPos = 0;
	int prev = 0;
	
	int count = n;
	
	for(currentTime = 0; count>0; currentTime++)
	{
		minPriority = INT_MAX;
		for(int i=0; i<n; i++)
		{
			if(remainingTime[i]>0 && arrivalTime[i] <= currentTime && priority[i] < minPriority)
			{
				minPos = i;
				minPriority = priority[i];
			}
		}
		
		for(int i=0; i<n; i++)
		{
			if(remainingTime[i]>0 && i!=minPos)
			{
				WT[i]++;
			}
		}
		
		remainingTime[minPos]--;
		//printf("MIN POS: %d--- Priority = %d\n",minPos + 1,priority[minPos]);
		
		if(remainingTime[minPos] == 0)
		{
			count--;
			//printf("Completed # %d\n",minPos+1);
			WT[minPos] -= arrivalTime[minPos];
			TAT[minPos] = WT[minPos] + burstTime[minPos];
		}
	}
	
	double avgTAT = 0;
	double avgWT = 0;
	
	printf("Process No\t\tTurnaround Time\t\tWaiting Time\n");
	for(i=0;i<n;i++)
	{
		TAT[i] = WT[i] + burstTime[i];
		printf("%d\t\t\t%d\t\t\t%d\n",i+1,TAT[i],WT[i]);
		avgTAT += TAT[i];
		avgWT += WT[i];
	}
	
	printf("\n\nAverage Turnaround Time : %.4f\n",avgTAT/n);
	printf("Average Waiting Time : %.4f\n",avgWT/n);
	
	return 0;	
}
