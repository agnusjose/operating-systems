#include<stdio.h>
void main()
{
int lim,bt[20],i,j,wt[20],tat[20],tw=0,tt=0,temp1,temp2;
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
for(i=0;i<lim;i++)
{
for(j=i+1;j<lim;j++)
{
if(bt[i]>bt[j])
{
temp1=bt[i];
bt[i]=bt[j];
bt[j]=temp1;

temp2=p[i];
p[i]=p[j];
p[j]=temp2;
}
}
}
printf("sorted processes:\n");
printf("process\tburst time\n");
for(i=0;i<lim;i++)
{
printf("%d\t%d\n",p[i],bt[i]);
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
