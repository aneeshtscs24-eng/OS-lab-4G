#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id, tickets, run;
} P;

int main() {
    int n, cycles, total = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    P p[n];

    for (int i = 0; i < n; i++) {
        printf("Tickets for P%d: ", i + 1);
        scanf("%d", &p[i].tickets);

        p[i].id = i + 1;
        p[i].run = 0;

        total += p[i].tickets;
    }

    printf("Enter number of scheduling cycles: ");
    scanf("%d", &cycles);

    srand(time(0));

    while (cycles--) {
        int win = rand() % total + 1, sum = 0;

        for (int i = 0; i < n; i++) {
            if ((sum += p[i].tickets) >= win) {
                printf("P%d selected\n", p[i].id);
                p[i].run++;
                break;
            }
        }
    }

    printf("\nExecution Count:\n");

    for (int i = 0; i < n; i++)
        printf("P%d -> %d\n", p[i].id, p[i].run);

    return 0;
}
