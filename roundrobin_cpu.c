#include<stdio.h>
void main()
{
int tq,bt[20],p[20],num,i,rem[20],wt[20],tat[20],tqi,count=0,twt=0,tt=0;
float att,awt;
printf("enter number of processes:");
scanf("%d",&num);
printf("enter time quantum:");
scanf("%d",&tq);
printf("enter processes:");
for(i=0;i<num;i++)
{
scanf("%d",&p[i]);
}
printf("enter burst time for each processes:");
for(i=0;i<num;i++)
{
scanf("%d",&bt[i]);
rem[i]=bt[i];
}
tqi=0;
while(count<num)
{
for(i=0;i<num;i++)
{
if(rem[i]>tq)
{
tqi=tqi+tq;
rem[i]=rem[i]-tq;
}
else if(rem[i]>0&&rem[i]<=tq)
{
tqi=tqi+rem[i];
rem[i]=0;
wt[i]=tqi-bt[i];
tat[i]=tqi;
count++;
}
}
}
for(i=0;i<num;i++)
{
twt=twt+wt[i];
tt=tt+tat[i];
}
awt=(float)twt/num;
att=(float)tt/num;
printf("process\tburst time\twaiting time\tturn around time\n");
for(i=0;i<num;i++)
{
  printf("%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
}
  printf("average waiting time=%fms\n",awt);
  printf("average turn around time=%fms",att);
}

