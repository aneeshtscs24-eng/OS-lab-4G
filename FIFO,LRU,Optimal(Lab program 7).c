#include <stdio.h>

void fifo(int pages[], int n, int frames) {
    int frame[20], i, j, k = 0, fault = 0, found;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[k] = pages[i];
            k = (k + 1) % frames;
            fault++;
        }
    }

    printf("\nFIFO Page Faults = %d", fault);
}

void lru(int pages[], int n, int frames) {
    int frame[20], time[20];
    int i, j, fault = 0, count = 0;
    int found, pos, min;

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if(!found) {
            min = time[0];
            pos = 0;

            for(j = 1; j < frames; j++) {
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            count++;
            frame[pos] = pages[i];
            time[pos] = count;
            fault++;
        }
    }

    printf("\nLRU Page Faults = %d", fault);
}

void optimal(int pages[], int n, int frames) {
    int frame[20];
    int i, j, k, fault = 0;
    int found, pos, farthest, index;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int empty = -1;

            for(j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                frame[empty] = pages[i];
            }
            else {
                farthest = -1;
                pos = -1;

                for(j = 0; j < frames; j++) {
                    index = 9999;

                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }

                    if(index > farthest) {
                        farthest = index;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
            }

            fault++;
        }
    }

    printf("\nOptimal Page Faults = %d", fault);
}

int main() {
    int n, frames, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    fifo(pages, n, frames);
    lru(pages, n, frames);
    optimal(pages, n, frames);

    printf("\n");

    return 0;
}
