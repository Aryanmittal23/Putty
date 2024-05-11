#include<stdio.h>
#include<conio.h>
#define max 10

void main(){
    int n,i,qt,count=0,temp,sq=0,bt[max],tat[max],rem_bt[max];
    float awt=0,atat=0;

    printf("enter the number of process");
    scanf("%d",&n);
    printf("enter burst time of process");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("enter the qunatum time");
    scanf("%d",&qt);
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
            rem_bt[i]=rem_bt[i]-qt;
            else
            if(rem_bt[i]>=0)
            {
                temp=rem_bt[i];
                rem_bt[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(n==count)
        break;
    }
    printf("\nprocess\tbrust time\tturn around time\twaiting time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=tat[i]-bt[j];
        }
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t%d\t%d\n",i+1,bt[i],tat[i],wt[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("average waiting time %f\n",awt);
    printf("average turn around time %f\n",atat);
    getch();
}