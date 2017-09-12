/*
* Ebey Abraham
* S5 - CSE
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct users
{
	char username[10];
	char a[10][20];
	int fileCount;
}ob[10];

int userCount = 0;

int search_sl(int pos, char file[10])
{
	int loc = -1;
	for(int i=0;i<ob[pos].fileCount;i++)
	{
		if(!strcmp(file,ob[pos].a[i]))
		{
			loc = i;
			break;
		}
	}
	return loc;	
}

int find_user(char username[10])
{
	int pos = -1;
	for(int i=0;i<userCount;i++)
	{
		if(!strcmp(username,ob[i].username))
		{
			pos = i;
			break;
		}
	}
	return pos;
}

void delete_user()
{
	char name[10];
	printf("\nEnter username: ");
	scanf("%s",name);
	int pos = find_user(name);
	if(pos == -1)
	{
		printf("\nuser not found!");
	}	
	else
	{
		for(int i=0;i<userCount-1;i++)
		{
			ob[i] = ob[i+1];
		}
		userCount--;
	}
}

void add_user()
{
	char name[10];
	printf("\nEnter usename: ");
	scanf("%s",name);
	if(find_user(name) != -1)
	{
		printf("\nUsername exists!");
	}
	else
	{
		strcpy(ob[userCount].username,name);
		userCount++;
	}
}

void display_users()
{
	for(int i=0;i<userCount;i++)
	{
		printf("--%s\n",ob[i].username);
	}
}

void add_directory_sl(int pos)
{
	char file[10];
	printf("Enter filename: ");
	scanf("%s",file);
	strcpy(ob[pos].a[ob[pos].fileCount],file);
	ob[pos].fileCount++;
}

void display_sl(int pos)
{
	printf("\n\n******************************************************************************************************************\n\n");
	printf("DISPLAYING ALL DIRECTORIES\n\n");
	for(int i=0;i<ob[pos].fileCount;i++)
	{
		printf("--%s\n",ob[pos].a[i]);
	}
	printf("\n\n******************************************************************************************************************\n\n");
}

void delete_sl(int pos)
{
	char file[10];
	printf("Enter file to delete: ");
	scanf("%s",file);
	int fileLoc = search_sl(pos,file);
	if(fileLoc == -1)
	{
		printf("\n\nUnable to delete.File not found\n\n");
	}
	else
	{
		int i;
		for(i=pos; i<ob[pos].fileCount-1;i++)
		{
			strcpy(ob[pos].a[i],ob[pos].a[i+1]);
		}
		ob[pos].fileCount--;
		
		printf("\n%s has been deleted\n\n",file);
	}
}

int main()
{
	while(true)
	{
		printf("\n---------------------------------------------------------------------------------------------------------------\n");
		printf("1. Add new user\n");
		printf("2. Add directory\n");
		printf("3. Delete directory\n");
		printf("4. Search directory\n");
		printf("5. Display all directories\n");
		printf("6. Display all users\n");
		printf("7. Delete user\n");
		printf("8. Exit\n");
		int choice;
		char file[10];
		char name[10];
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: add_user();
					break;
			case 2: printf("\nEnter username: ");
					scanf("%s",name);
					int pos = find_user(name);
					if(pos == -1)
					{
						printf("user not found!");
					}
					else
					{
						add_directory_sl(pos);
					}
					
					break;
			case 3: printf("\nEnter username: ");
					scanf("%s",name);
					pos = find_user(name);
					if(pos == -1)
					{
						printf("user not found!");
					}
					else
					{
						delete_sl(pos);
					}
					break;
			case 4:	printf("\nEnter username: ");
					scanf("%s",name);
					pos = find_user(name);
					if(pos == -1)
					{
						printf("user not found!");
						break;
					} 
					printf("\nEnter directory to search: ");
					scanf("%s",file);
					int found = search_sl(pos,file);
					if(found == -1)
					{
						printf("\n\nFile not found\n\n");
					}
					else
					{
						printf("\n\nFile found\n\n");
					}
					break;
			case 5: printf("\nEnter username: ");
					scanf("%s",name);
					pos = find_user(name);
					if(pos == -1)
					{
						printf("\nuser not found!");
						break;
					}
					display_sl(pos);
					break;
			case 6: display_users();
					break;
			case 7: delete_user();
					break;
			case 8:	exit(0); 
		}
		
		
		
	}
	return 0;
}
