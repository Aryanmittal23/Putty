#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int tickets;
    int stride;
    int pass;
} Process;

void printProcesses(Process* procs, int n) {
    printf("Stride Scheduling Algorithm:\n");
    printf("ID\tTickets\tStride\tPass\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", procs[i].id, procs[i].tickets, procs[i].stride, procs[i].pass);
    }
}

int findMinPass(Process* procs, int n) {
    int minIndex = 0;
    int min = procs[0].pass;
    for (int i = 1; i < n; i++) {
        if (procs[i].pass < min) {
            min = procs[i].pass;
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n = 5;
    int tix[] = {2, 3, 4, 5, 6};
    int maxNum = 60;

    Process procs[n];
    for (int i = 0; i < n; i++) {
        procs[i].id = i + 1;
        procs[i].tickets = tix[i];
        procs[i].stride = maxNum / tix[i];
        procs[i].pass = 0;
    }

    printProcesses(procs, n);

    printf("\nExecution Order:\n");
    while (1) {
        int minIndex = findMinPass(procs, n);
        printf("Process %d\n", procs[minIndex].id);

        for (int i = 0; i < n; i++) {
            procs[i].pass += procs[i].stride;
        }

        int allDone = 1;
        for (int i = 0; i < n; i++) {
            if (procs[i].pass != procs[minIndex].pass) {
                allDone = 0;
                break;
            }
        }

        if (allDone) {
            break;
        }
    }

    return 0;
}