#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int main()
{
	int n;
	int i = 0;
	int j = 0;
	//printf("Enter numbe of processes: ");
	scanf("%d",&n);
	
	int burstTime[n];
	int arrivalTime[n];
	bool check[n];
	
	int totalTime = 0;
	
	//printf("Enter burst time of each process:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burstTime[i]);
		check[i] = true;
	}
	
	//printf("Enter arrival time of each process:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arrivalTime[i]);
	}
	
	int TAT[n];
	int WT[n];
	/*
	printf("Process No\t\tBurst Time\t\tArrival Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\n",i+1,burstTime[i],arrivalTime[i]);
	}
	
	printf("\n\n");
	*/
	TAT[0] = burstTime[0];
	WT[0] = 0;
	check[0] = false;
	
	int currentTime = TAT[0];
	int minBurst = burstTime[1];
	int minPos = 1;
	int prev = 0;
	
	int count = n-1;
	
	while(count--)
	{
		minBurst = INT_MAX;
		for(i=1; arrivalTime[i]<=currentTime && i<n; i++)
		{
			if(check[i] && burstTime[i] < minBurst)
			{
				{
					minBurst = burstTime[i];
					minPos = i;
				}
			}
		}
		
		WT[minPos] = currentTime - arrivalTime[minPos];
		TAT[minPos] = WT[minPos] + burstTime[minPos];
		currentTime += burstTime[minPos];
		check[minPos] = false;
		
		prev = minPos;
		//printf("Current Time: %d   Pos: %d\n",currentTime,minPos);
	}
	
	
	double avgTAT = 0;
	double avgWT = 0;
	
	printf("Process No\t\tTurnaround Time\t\tWaiting Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\n",i+1,TAT[i],WT[i]);
		avgTAT += TAT[i];
		avgWT += WT[i];
	}
	
	printf("\n\nAverage Turnaround Time : %.4f\n",avgTAT);
	printf("Average Waiting Time : %.4f\n",avgWT);
	
	return 0;
	
}
