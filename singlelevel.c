/*
* Ebey Abraham
* S5 - CSE
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char a[10][20];
int fileCount = 0;

int search_sl(char file[10])
{
	int pos = -1;
	for(int i=0;i<fileCount;i++)
	{
		if(!strcmp(file,a[i]))
		{
			pos = i;
			break;
		}
	}
	return pos;	
}

void add_directory_sl()
{
	char file[10];
	printf("Enter filename: ");
	scanf("%s",file);
	strcpy(a[fileCount],file);
	fileCount++;
}

void display_sl()
{
	printf("\n\n******************************************************************************************************************\n\n");
	printf("DISPLAYING ALL DIRECTORIES\n\n");
	for(int i=0;i<fileCount;i++)
	{
		printf("--%s\n",a[i]);
	}
	printf("\n\n******************************************************************************************************************\n\n");
}

void delete_sl()
{
	char file[10];
	printf("Enter file to delete: ");
	scanf("%s",file);
	int pos = search_sl(file);
	if(pos == -1)
	{
		printf("\n\nUnable to delete.File not found\n\n");
	}
	else
	{
		int i;
		for(i=pos; i<fileCount-1;i++)
		{
			strcpy(a[i],a[i+1]);
		}
		fileCount--;
		
		printf("\n%s has been deleted\n\n",file);
	}
}

int main()
{
	while(true)
	{
		printf("---------------------------------------------------------------------------------------------------------------\n");
		printf("1. Add directory\n");
		printf("2. Delete directory\n");
		printf("3. Search directory\n");
		printf("4. Display all directories\n");
		printf("5. Exit\n");
		int choice;
		char file[10];
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: add_directory_sl();
					break;
			case 2: delete_sl();
					break;
			case 3: printf("Enter directory to search: ");
					scanf("%s",file);
					int found = search_sl(file);
					if(found == -1)
					{
						printf("\n\nFile not found\n\n");
					}
					else
					{
						printf("\n\nFile found\n\n");
					}
					break;
			case 4: display_sl();
					break;
			case 5:	exit(0); 
		}
		
		
		
	}
	return 0;
}
