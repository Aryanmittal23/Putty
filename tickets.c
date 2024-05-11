#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSES 5

char names[] = {'P', 'Q', 'R', 'S', 'T'};
int tickets[] = {600, 200, 800, 300, 100};

int total = 0;

void initialize() {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        total += tickets[i];
    }
}

int select() {
    int random = rand() % total;
    int sum = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        sum += tickets[i];
        if (random < sum) {
            return i;
        }
    }
    return -1; 
}

int main() {
    srand(time(NULL)); 

    initialize();

    printf("Tickets Distribution:\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%c: %d\n", names[i], tickets[i]);
    }
    printf("Total Tickets: %d\n\n", total);

    int iterations = 10; 
    for (int i = 0; i < iterations; i++) {
        int selected = select();
        printf("CPU allocated to Process %c\n", names[selected]);
    }

    return 0;
}