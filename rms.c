#include <stdio.h>

typedef struct {
    int id;
    int period;
    int execution;
    int remaining;
    int deadline;
    int next_release;
} Task;

int main() {
    int n, hyper = 20;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task t[n];

    for (int i = 0; i < n; i++) {
        t[i].id = i + 1;

        printf("\nTask %d\n", i + 1);

        printf("Execution Time: ");
        scanf("%d", &t[i].execution);

        printf("Period: ");
        scanf("%d", &t[i].period);

        t[i].remaining = 0;
        t[i].next_release = 0;
    }

    printf("\n===== Rate Monotonic Scheduling =====\n");

    printf("\nGantt Chart:\n|");

    for (int time = 0; time < hyper; time++) {

        for (int i = 0; i < n; i++) {
            if (time == t[i].next_release) {
                if (t[i].remaining == 0)
                    t[i].remaining = t[i].execution;
                t[i].deadline = time + t[i].period;
                t[i].next_release += t[i].period;
            }
        }

        int selected = -1;

        for (int i = 0; i < n; i++) {
            if (t[i].remaining > 0) {
                if (selected == -1 ||
                    t[i].period < t[selected].period) {
                    selected = i;
                }
            }
        }

        if (selected != -1) {
            printf(" T%d |", t[selected].id);
            t[selected].remaining--;
        } else {
            printf(" Idle |");
        }
    }

    printf("\n0");

    for (int i = 1; i <= hyper; i++) {
        printf("    %d", i);
    }

    printf("\n");
}
