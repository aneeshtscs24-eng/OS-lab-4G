#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], wt[20], tat[20], type[20];

    float avg_wt = 0, avg_tat = 0;
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, Type (1-System, 2-User):\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &at[i], &bt[i], &type[i]);
    }

    printf("\n--- System Processes (FCFS) ---\n");

    for(i = 0; i < n; i++) {
        if(type[i] == 1) {

            if(time < at[i])
                time = at[i];

            wt[i] = time - at[i];
            time += bt[i];
            tat[i] = wt[i] + bt[i];

            printf("P%d\tAT=%d\tBT=%d\tWT=%d\tTAT=%d\n",
                   i+1, at[i], bt[i], wt[i], tat[i]);
        }
    }

    printf("\n--- User Processes (FCFS) ---\n");

    for(i = 0; i < n; i++) {
        if(type[i] == 2) {

            if(time < at[i])
                time = at[i];

            wt[i] = time - at[i];
            time += bt[i];
            tat[i] = wt[i] + bt[i];

            printf("P%d\tAT=%d\tBT=%d\tWT=%d\tTAT=%d\n",
                   i+1, at[i], bt[i], wt[i], tat[i]);
        }
    }

    printf("\nProcess\tAT\tBT\tType\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], type[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}


