#include <stdio.h>
#include <limits.h>

#define MAX 20

typedef struct {
    int id;
    int arrival;
    int burst;
    int remaining;
    int deadline;
    int completion;
    int turnaround;
    int waiting;
} Process;

int main() {
    Process p[MAX];
    int n, time = 0, completed = 0;
    int gantt[MAX * 20], gIndex = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        printf("\nProcess P%d\n", i+1);
        p[i].id = i+1;
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Deadline: ");
        scanf("%d", &p[i].deadline);
        p[i].remaining = p[i].burst;
    }

    while(completed < n) {
        int idx = -1;
        int earliest_deadline = INT_MAX;

        for(int i=0;i<n;i++) {
            if(p[i].arrival <= time && p[i].remaining > 0) {
                if(p[i].deadline < earliest_deadline) {
                    earliest_deadline = p[i].deadline;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].remaining--;
            gantt[gIndex++] = p[idx].id;
            time++;

            if(p[idx].remaining == 0) {
                completed++;
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
            }
        }
        else {
            gantt[gIndex++] = 0; // idle
            time++;
        }
    }

    printf("\n\nPID\tAT\tBT\tDL\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].id, p[i].arrival, p[i].burst, p[i].deadline,
            p[i].completion, p[i].turnaround, p[i].waiting);
    }

    float avgWT=0, avgTAT=0;
    for(int i=0;i<n;i++) {
        avgWT += p[i].waiting;
        avgTAT += p[i].turnaround;
    }

    printf("\nAverage Waiting Time = %.2f", avgWT/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT/n);

    printf("\nGantt Chart:\n|");
    for(int i=0;i<gIndex;i++) {
        if(gantt[i]==0) printf(" Idle |");
        else printf(" P%d |", gantt[i]);
    }

    printf("\n0");
    for(int i=1;i<=gIndex;i++)
        printf("    %d", i);

    printf("\n");

    return 0;
}
