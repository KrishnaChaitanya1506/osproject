#include<stdio.h>
//In this problem we consider the time taken for each safari ride is equal that is 15 min
int allocate_cars(int x,int y)
{
	return x-y;
}
int main()
{
	int cars,wander,ready;
	int rcars,newready,time;
    int ch;
	int totalPeople;
	
	printf("Enter number of cars available:");
	scanf("%d",&cars);
	printf("\nEnter number of people wandering:");
	scanf("%d",&wander); 
	printf("\nEnter number of people ready to take ride:");
	scanf("%d",&ready);

	if(cars == 0)
	{
		printf("\nNo. of passengers completed the park ride = 0");
		printf("\nNo. of passengers wandering in the museum = %d",wander);
		printf("\nNo. of passengers completed the park ride = %d",ready);
	}
	
	else if(ready==cars)
	{
		printf("\nAll cars are in ride and are available in 15 min");	
		printf("\nNo. of passengers wandering in the museum = %d",wander);
		printf("\nNo. of passengers completed the park ride %d",ready);
	}
	
	else if(cars > ready)
	{
		int i;
		rcars=allocate_cars(cars,ready);
		printf("cars left are %d\n",rcars);
		
		for(i=0;i<100;i++)
		{
			if(i%5==0)
			{
				printf(".");
			}
		}
		printf("\nAfter some time.....");
		printf("\nIf any new passengers ready?\nPress 1 for new 0 for none: ");
		scanf("%d",&ch);
		if(ch==1)
		{
		repeat1:	printf("\nEnter number of new passengers: ");
			scanf("%d",&newready);
			if(newready<=wander)
			{
				if(rcars==newready)
				{
					printf("\nAll cars are in ride and are available in 15 min");
				}
				else if(rcars>newready)
				{
					rcars=allocate_cars(rcars,newready);
					printf("\nThe cars avilable are %d and rest %d are available at 15 min",rcars,cars-rcars);
					printf("\nNo. of passengers wandering in the museum = %d",wander-newready);
					printf("\nNo. of passengers completed ride in the museum = %d",newready+ready);
				}
				else
				{
					printf("\nEnter the time of leaving of first batch of car(s) (Less than 15): ");
					scanf("%d",&time);
					printf("%d of Cars will be available in %d min",cars-rcars,15-time);
					printf("\nNo. of passengers completed ride in the museum = %d",ready+rcars);
					printf("\nNo. of passengers ready to ride in the museum = %d",newready-rcars);

				}
			}
			else
			{
				printf("\nEnter correct number of passengers");
				goto repeat1;
			}
		}
		else
		{
			printf("\nThe cars avilable are %d and rest %d are available at 15 min",rcars,cars-rcars);
			printf("\nNo. of passengers wandering in the museum = %d",wander);
			printf("\nNo. of passengers completed ride in the museum = %d",ready);
		}
	}
	
	else
	{
		printf("\nEnter the time of leaving of first batch of car(s) (Less than 15): ");
		scanf("%d",&time);
		printf("\nIf any new passengers ready?\nPress 1 for new 0 for none: ");
		scanf("%d",&ch);
		if(ch==1)
		{
		repeat2 :	printf("\nEnter number of new passengers: ");
			scanf("%d",&newready);
			if(newready<=wander)
			{
			printf("%d of Cars will be available in %d min",cars,15-time);
			printf("\nNo. of passengers completed ride in the museum = %d",cars);
			printf("\nNo. of passengers ready to ride in the museum = %d",(newready+ready-cars));
			}
			else
			{
				printf("\nEnter correct number of passengers");
				goto repeat2;
			}
		}
		else
		{
			printf("%d of Cars will be available in %d min",cars,15-time);
			printf("\nNo. of passengers completed ride in the museum = %d",cars);
			printf("\nNo. of passengers ready to ride in the museum = %d",ready-cars);
		}
	}
}
