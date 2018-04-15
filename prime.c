#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
 void *primeno(void); 
 int i,j,n,flag=0;
 int main()
{
 pthread_t thread1;
 pthread_create(&thread1,NULL,primeno,NULL); 
 pthread_join(thread1,NULL); 
 }
 void *primeno(void) 
 {   
 printf("enter the no till you want to print prime no : ");   
 scanf("%d",n);  

for(i=1;i<n;i++)
{
	for(j=1;j<n;j++)
	{
		if(i%j==0)
		{
			flag++;
		}
	}
	 printf("%d\n",i);
	  sleep(1); 
}
 }    

