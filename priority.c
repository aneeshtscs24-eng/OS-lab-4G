#include <stdio.h>
struct Process
{
    int pid, at, bt, ct, tat, wt, complete,pr,remainingbt;
};
void display(struct Process p[], int n)
{
    float avgwt=0,avgtat=0;
    printf("\n\nPROCESS DETAILS\n");
    for(int i=0;i<n;i++)
    {
        printf("\n-------------------------");
        printf("\nProcess ID      : %d",p[i].pid);
        printf("\nArrival Time    : %d",p[i].at);
        printf("\nBurst Time      : %d",p[i].bt);
        printf("\nCompletion Time : %d",p[i].ct);
        printf("\nTurnaround Time : %d",p[i].tat);
        printf("\nWaiting Time    : %d\n",p[i].wt);
        printf("\nPriority  : %d\n",p[i].pr);
        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n",avgtat/n);
}


void priority_non_preemptive(struct Process p[], int n)
{
    int completed = 0, current_time = 0;

    while (completed < n)
    {
        int idx = -1;
        int highest_priority = 9999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && p[i].complete == 0)
            {
                if (p[i].pr < highest_priority)
                {
                    highest_priority = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            current_time++;
        }
        else
        {
            p[idx].ct = current_time + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].complete = 1;

            current_time = p[idx].ct;
            completed++;
        }
    }
}
void priority_preemptive(struct Process p[], int n)
{
    int completed = 0, current_time = 0;

    while (completed < n)
    {
        int idx = -1;
        int highest_priority = 9999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= current_time && p[i].complete == 0)
            {
                if (p[i].pr < highest_priority)
                {
                    highest_priority = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            current_time++;
        }
        else
        {

            p[idx].remainingbt--;
            current_time++;

            if (p[idx].remainingbt == 0)
            {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].complete = 1;
                completed++;
            }
        }
    }
}
int main()
{
    struct Process p[20];
    int n,choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("\nProcess %d",i+1);

        printf("\nEnter Arrival Time: ");
        scanf("%d",&p[i].at);

        printf("Enter Burst Time: ");
        scanf("%d",&p[i].bt);
        printf("Enter Priority: ");
        scanf("%d",&p[i].pr);

        p[i].pid=i+1;
        p[i].complete=0;
    }

    printf("\nSelect Algorithm");
    printf("\n1. Priority Non Preemptive");
    printf("\n2. Priority Preemptive");
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            priority_non_preemptive(p,n);
            display(p,n);
            break;

        case 2:
            priority_preemptive(p,n);
            display(p,n);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}


