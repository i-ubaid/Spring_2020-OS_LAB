#include <stdlib.h>
#include <stdio.h>
#define size 5

int counter = 0, i, j, exec, resources, processes, safe = 0;
int allocation_table[size][size], maxNeed_table[size][size], total_resources[size], available_resources[size], running[size];
int total_allocated[size] = {0, 0, 0, 0, 0};
int cur_Need_table[size][size]; //created to store current/remaing need of Process
 
int main()
{
	inputTotalProcess();
	inputTotalResources();
	inputMaxResources();
	inputAllocation();
	inputMaxNeed();
	addRunningProcess();
	displayMaxResources();
	displayAllocatedResources();
	displayMaxNeed();
	update_Display_Allocation();
	update_Resources();
	update_curruent_Need();
  display_updated_resources(); //New Method created to calculate current/remaing need of the process
  display_updated_cur_need(); //To display updated cur_Need_table
	finalCalculation();
    
    return 0;
}

void inputTotalProcess()
{
	printf("\nEnter total processes: ");
    scanf("%d", &processes);
}

void inputTotalResources()
{
	printf("\nEnter total resources: ");
    scanf("%d", &resources);
}

void inputMaxResources()
{
	printf("\n\nEnter Total Availability of each Resource");
    for (i = 0; i < resources; i++) 
	{ 
	  printf("\nEnter Availibility for Resource_%d : ",(i+1));
	  scanf("%d", &total_resources[i]);
   	}
    	
}

void inputAllocation()
{	
   printf("\n\nEnter Process Wise Allocation Table of Resources");
   for (i = 0; i < processes; i++) 
	{
		for(j = 0; j < resources; j++) 
		{
			printf("\nEnter Allocation of Resource_%d of Process_%d : ",(j+1),(i+1));
  		  scanf("%d", &allocation_table[i][j]);
       	}
  }
}

void inputMaxNeed()
{
    printf("\n\nEnter Process Wise Maximum Need Table of Resources");
    for (i = 0; i < processes; i++) 
	{
      for(j = 0; j < resources; j++) 
		{
			printf("\nEnter Need for Resource_%d of Process_%d : ",(j+1),(i+1));
          		scanf("%d", &maxNeed_table[i][j]);
       	}
   	}
 	
}

void displayMaxResources()
{
	printf("\n\nThe Total Availability of each Resource");
    for (i = 0; i < resources; i++) 
	{
	    printf("\nResource_%d = %d,",(i+1), total_resources[i]);
	}
}

void displayAllocatedResources()
{	
	printf("\n\nThe Allocated Resource Table");
    for (i = 0; i < processes; i++) 
	{
	   for (j = 0; j < resources; j++) 
		{
       	  printf("\nProcess_%d and Resource_%d = %d,",(i+1),(j+1), allocation_table[i][j]);
        }

    }
}

void displayMaxNeed()
{
	printf("\n\nThe Maximum Need Table");
   	for (i = 0; i < processes; i++) 
	{
       for (j = 0; j < resources; j++) 
		{
		  printf("\nProcess_%d and Resource_%d = %d",(i+1), (j+1), maxNeed_table[i][j]);
        }
   	}
 
}

void addRunningProcess()
{	 
    for (i = 0; i < processes; i++) 
	{
      	running[i] = 1; //set flag = 1, means process to be executed
       	counter++;
   	}	
}

void update_Display_Allocation()
{
	for (i = 0; i < processes; i++) 
	{
        for (j = 0; j < resources; j++) 
		{
            total_allocated[j] = total_allocated[j] + allocation_table[i][j];
       	}
   	}
    printf("\n\nAllocated resources");
   	for (i = 0; i < resources; i++) 
    {
       	printf("\nResource_%d = %d",(i+1), total_allocated[i]);
   	}
}
	
 void update_Resources()
 {
    for (i = 0; i < resources; i++) 
	{
	        available_resources[i] = total_resources[i] - total_allocated[i];
	}
}

 void display_updated_resources()
 {
    printf("\n\nAvailable resources");
    for (i = 0; i < resources; i++) 
	{
        	printf("\nResource_%d = %d",(i+1),available_resources[i]);
   	}
}

void update_curruent_Need()
{
  int i,j;
  for(i=0; i<processes; i++)
  {
    for(j=0; j<resources; j++)
    {
      cur_Need_table[i][j] = maxNeed_table[i][j] - allocation_table[i][j];
    }
  }
}

void display_updated_cur_need()
{
  	printf("\n\nThe Current Need Table");
    for (i = 0; i < processes; i++) 
	{
	   for (j = 0; j < resources; j++) 
		{
       	  printf("\nProcess_%d and Resource_%d = %d,",(i+1),(j+1), cur_Need_table[i][j]);
        }

    }
}


void finalCalculation()
{

	int a[size];
  int i,j,k,x=0;
	int pflag=0,flag=0;

	for(k=0;k<processes;k++)
	{
		for(i=0;i<processes;i++)
		{
			if(running[i] == 1)
			{
				flag=0;
				for(j=0;j<resources;j++)
				{
					if(cur_Need_table[i][j] > available_resources[j])
						flag=1;
				}
				if(flag == 0 && running[i] == 1)
				{
          for(j=0;j<resources;j++)
          {
						available_resources[j]+=allocation_table[i][j];
          }
          	running[i]=0;
						pflag++;
						a[x++]=i;
				}
			}
		}
    			printf("\nPflag = %d" ,pflag);
		if(pflag >= processes)
		{
			printf("\nSafety Sequence  \n");
			for(int i =0; i<processes; i++)
			{
				printf("P_%d > ",(a[i]+1));
			}
			printf("\n");
			exit(0);
		}
	}
}









