#include<stdio.h>
#include<stdlib.h>
#define max 30


void main()
{
    int i,j,n,bt[max],wt[max],tat[max],p[max];
    float awt=0,atat=0;

    printf("enter the number of process");
    scanf("%d",&n);
    printf("enter the burst time of process");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("process\t burst time\t waiting time\t turn around time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("average waiting time %f\n",awt);
    printf("average turn around time %f",atat);
    getch();
}