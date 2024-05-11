#include<stdio.h>
#include<conio.h>
#define max 30

void main()
{
    int i,n,j,t,bt[max],wt[max]pr[max],tat[max],pos;
    float awt=0;atat=0;

    print("enter the number of process");
    scanf("%d",&n);
    print("enter the burst time of the process");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    print("enter the priority of the process");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pr[i]);
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++){
            if(pr[i]<pr[pos]){
                pos=j;

            }
        }
        t=pr[i];
        pr[i]=pr[pos];
        pr[pos]=t;

        t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
    }
    wt[0]=0;
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