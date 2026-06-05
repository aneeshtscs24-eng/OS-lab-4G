#include <stdio.h>

int main() {
    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb], original[nb];

    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
        original[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np], allocation[np];

    printf("Enter sizes of processes:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for(i = 0; i < np; i++) {
        for(j = 0; j < nb; j++) {
            if(block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nProcess\tSize\tBlock No.\n");
    for(i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("\nRemaining Memory in Blocks:\n");
    printf("Block\tOriginal\tRemaining\n");

    for(i = 0; i < nb; i++) {
        printf("%d\t%d\t\t%d\n",
               i + 1, original[i], block[i]);
    }

    return 0;
}
