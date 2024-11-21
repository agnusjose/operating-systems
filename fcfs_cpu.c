#include<stdio.h>
void main()
{
int lim,bt[20],i,wt[20],tat[20],tw=0,tt=0;
float avw,avt;
int p[20];
printf("enter number of processes:\n");
scanf("%d",&lim);
printf("enter process numbers:\n");
for(i=0;i<lim;i++)
{
  scanf("%d",&p[i]);
}
printf("enter burst time of each processes:\n");
for(i=0;i<lim;i++)
{
  scanf("%d",&bt[i]);
}
wt[0]=0;
tat[0]=bt[0];
for(i=1;i<lim;i++)
{
  wt[i]=wt[i-1]+bt[i-1];
  tat[i]=wt[i]+bt[i];
}
for(i=0;i<lim;i++)
{
  tw=tw+wt[i];
  tt=tt+tat[i];
}
avw=tw/(float)lim;
avt=tt/(float)lim;
printf("process\tburst time\twaiting time\tturn around time\n");
for(i=0;i<lim;i++)
{
  printf("%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
}
  printf("average waiting time=%fms\n",avw);
  printf("average turn around time=%fms",avt);
}
