#include <stdio.h>

int main()
{
    int n,i,j;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int AT[100],BT[100],PID[100];
    for(i=0;i<n;i++)
    {
        printf("\nEnter Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Enter Burst Time: ");
        scanf("%d",&BT[i]);
        PID[i]=i+1;
    }
    int temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(AT[i] > AT[j])
            {
                temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;

                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;

                temp=PID[i];
                PID[i]=PID[j];
                PID[j]=temp;
            }
        }
    }
    int current_time=0;
    int CT[100],TAT[100],WT[100];
    int sum_WT=0,sum_TAT=0;
    float avg_WT,avg_TAT;
    for(i=0;i<n;i++)
    {
        if(current_time < AT[i])
            current_time = AT[i];

        CT[i] = current_time + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        current_time = CT[i];
        sum_WT += WT[i];
        sum_TAT += TAT[i];
        printf("\nProcess ID: %d",PID[i]);
        printf("\nArrival Time: %d",AT[i]);
        printf("\nBurst Time: %d",BT[i]);
        printf("\nWaiting Time: %d",WT[i]);
        printf("\nTurnaround Time: %d\n",TAT[i]);
    }
    avg_WT = (float)sum_WT/n;
    avg_TAT = (float)sum_TAT/n;

    printf("\nAverage Waiting Time: %f",avg_WT);
    printf("\nAverage Turnaround Time: %f",avg_TAT);

    return 0;
}

