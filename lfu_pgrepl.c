#include<stdio.h>
void main()
{
int rs[50], i, j, k, m, f, count[20], a[20], min, pf=0;
printf("\nEnter number of page references : ");
scanf("%d",&m);
printf("\nEnter the reference string :");
for(i=0;i<m;i++)
scanf("%d",&rs[i]);
printf("\nEnter the available no. of frames : ");
scanf("%d",&f);
for(i=0;i<f;i++)
{
count[i]=0;
a[i]=-1;
}
printf("\nThe Page Replacement Process is: \n");
for(i=0;i<m;i++)
{

for(j=0;j<f;j++)
if(rs[i]==a[j])
{
count[j]++;
break;
}
if(j==f)
{     min = 0;
for(k=1;k<f;k++)
if(count[k]<count[min])
min=k;
a[min]=rs[i];
count[min]=1;
pf++;
}
printf("\n");
for(j=0;j<f;j++)
printf("\t%d",a[j]);

}
printf("\n\nTotal number of page faults :%d",pf);
}
