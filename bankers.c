#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,r,i,j,c=0,exec,k=0,f;
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("Enter number of resources:");
    scanf("%d",&r);
    int alloc[n][r],max[n][r],avail[r],need[n][r],vis[n],a[n];
    for(i=0;i<n;i++)
    {
        vis[i]=0;
        printf("Enter maximum resources of P%d:",i);
        for(j=0;j<r;j++)
        scanf("%d",&max[i][j]);
        printf("Enter allocated resources of P%d:",i);
        for(j=0;j<r;j++)
        {
           scanf("%d",&alloc[i][j]);
           need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("Enter available resources:");
    for(j=0;j<r;j++)
    scanf("%d",&avail[j]);
    printf("Process\tMaximum\tAllocated\tNeed\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t",i);
        for(j=0;j<r;j++)
        printf("%d ",max[i][j]);
        printf("\t");
        for(j=0;j<r;j++)
        printf("%d ",alloc[i][j]);
        printf("\t\t");
        for(j=0;j<r;j++)
        printf("%d ",need[i][j]);
        printf("\n");
    }
    while(c<n)
    {
        f=0;
        for(i=0;i<n;i++)
        {
            exec=0;
            for(j=0;j<r;j++)
            {
                if(need[i][j]<=avail[j])
                exec++;
            }
            if(exec==r&&vis[i]==0)
            {
                for(j=0;j<r;j++)
                avail[j]+=alloc[i][j];
                vis[i]=1;
                f=1;
                a[k++]=i;
                c++;
            }
        }
        if(f==0)
        {
        printf("No safe sequence!");
        exit(0);
        }
    }
    printf("Safe Sequence is:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}