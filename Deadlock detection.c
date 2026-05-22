#include <stdio.h>

int main() {
    int n, m;

    printf("Processes: ");
    scanf("%d", &n);

    printf("Resources: ");
    scanf("%d", &m);

    int a[n][m], r[n][m], av[m], f[n], seq[n], k = 0;

    for (int i = 0; i < n; i++)
        f[i] = 0;

    printf("Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    printf("Request Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &r[i][j]);

    printf("Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &av[i]);

    for (int c = 0; c < n; c++) {
        for (int i = 0; i < n; i++) {

            if (!f[i]) {
                int ok = 1;

                for (int j = 0; j < m; j++) {
                    if (r[i][j] > av[j]) {
                        ok = 0;
                        break;
                    }
                }

                if (ok) {
                    for (int j = 0; j < m; j++)
                        av[j] += a[i][j];

                    f[i] = 1;
                    seq[k++] = i;
                }
            }
        }
    }

    if (k == n) {
        printf("No Deadlock\nSequence: ");

        for (int i = 0; i < n; i++)
            printf("P%d ", seq[i]);
    }
    else {
        printf("Deadlock Detected");
    }

    return 0;
}
