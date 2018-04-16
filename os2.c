#include<stdio.h>
#include<conio.h>
void main()
{
int n,r,i,j,k,p,u=0,s=0,m;
int bk[20],run[20],ac[20],nreq[20];
int max[20][20],ralloc[20][20],rreq[20][20];
int talloc[20],tot[20],salloc[20];
printf("Enter the total no of processes:");
scanf("%d",&n);
printf("Enter the total no of resource classes:");
scanf("%d",&r);
printf("Enter the total existed resource present  in  the each class:");
for(k=1;k<=r;k++)
scanf("%d",&tot[k]);
printf("Enter the allocated resources:");
for(i=1;i<=n;i++)
for(k=1;k<=r;k++)
scanf("%d",&ralloc);
printf("Enter the process making the new request:");
scanf("%d",&p);
printf("Enter the requested resource:");
for(k=1;k<=r;k++)
scanf("%d",&nreq[k]);
printf("Enter the processes which are n blocked or running:");
for(i=1;i<=n;i++)
{
	if(i!=p)
		{
			printf("process %d:\n",i);
			scanf("%d%d",&bk[i],&run[i]);
		}
}
bk[p]=0;
run[p]=0;
for(k=1;k<=r;k++)
	{
		j=0;
		for(i=1;i<=n;i++)
			{
				talloc[k]=j+ralloc[i][k];
				j=talloc[k];
			}
	}
for(i=1;i<=n;i++)
	{
		if(bk[i]==1||run[i]==1)
			{
			ac[i]=1;
			}	
		else
			{
			ac[i]=0;
			}
	}
for(k=1;k<=r;k++)
	{
		ralloc[p][k]+=nreq[k];
		talloc[k]+=nreq[k];
	}
for(k=1;k<=r;k++)
	{
		if(tot[k]-talloc[k]<0)
			{
				u=1;
				break;
			}
	}
if(u==0)
	{
		for(k=1;k<=r;k++)
		salloc[k]=talloc[k];
		for(s=1;s<=n;s++)
		for(i=1;i<=n;i++)
			{
				if(ac[i]==1)
					{
						j=0;
						for(k=1;k<=r;k++)
							{
								if((tot[k]-salloc[k])<(max[i][k]-ralloc[i][k]))
									{
										j=1;break;
									}
							}
					}
				if(j==0)
					{
						ac[i]=0;
						for(k=1;k<=r;k++)
						salloc[k]=ralloc[i][k];
					}
			}	
		m=0;
		for(k=1;k<=r;k++)
		rreq[p][k]=nreq[k];
		printf("safe state does not exist");
	}
else
	{
		for(k=1;k<=r;k++)
			{
				ralloc[p][k]=nreq[k];
				talloc[k]=nreq[k];
			}
		printf("safe state exists");
	}
getch();
}
