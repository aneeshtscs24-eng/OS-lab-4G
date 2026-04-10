#include <stdio.h>

int main() {
    int n, tq, time = 0, remain, i;
    int at[20], bt[20], rt[20];
    int wt[20] = {0}, tat[20] = {0};
    int done[20] = {0};

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(remain > 0) {
        int executed = 0;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                executed = 1;

                if(rt[i] <= tq) {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    rt[i] = 0;
                    remain--;
                } else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }

        // If no process is ready, increment time
        if(executed == 0)
            time++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}

