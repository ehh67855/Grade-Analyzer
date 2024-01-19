#include <stdio.h>
#include <stdlib.h>

//global variables
double response = 0;
//pointers
double* ptr;
double* head;
double* position;
//counts
int fiveCount = 1;
int totalCount = 0;
int allocCount = 0;
int freeCount = 0;
int byteCount = 0;
//prototypes

/* Takes in a pointer and the length of stored values and computes the average */
double average(double* p,int n);
/*Takes in the average and the main pointer. Determines what values are less then or greater to or equal to the average */
void compare(double average, double* p);
/* Reallocates size to new memory location every 5 responses */
void extendMemory();
/* Facilitates the very first response. Determines whether to allocate memory or not */
void startingResponse();

int main(int argc, char*argv[]) {
    printf("Enter a list of grades below where each grade is separated by a newline character.\nAfter the last grade is entered, enter a negative value to end the list.\n");
    scanf("%lf",&response);
    startingResponse();
    while (response >= 0) {
        scanf("%lf",&response);
        *(head + totalCount) = response;
        if (response >= 0) {
            totalCount++;
            position++;
            printf("Stored %lf in the heap at %p\n",response,(void *)(&head + totalCount));
        }
        if (totalCount % 5 == 0 && totalCount > 0) {
            extendMemory();
        }
    }
    double avg = average(head,totalCount);
    printf("The average of the %i grades is %lf\n",totalCount,avg);
    compare(avg,head);
    if (head != NULL) {
        free(head);
        freeCount++;
    }
    printf("Total heap usage: %i allocs, %i frees, %i bytes allocated\n", allocCount, freeCount, byteCount);
}

void startingResponse() {
    if (response >= 0) {
        head = (double*)malloc(5 * sizeof(double));
        printf("Allocated 40 bytes to the heap at ");
        printf("%p\n",(void *)&head); 
        position = head;
        printf("Stored %lf in the heap at %p\n",response,(void *)&head);
        *(head + totalCount) = response;
        totalCount++;
        allocCount++;
        byteCount+= 5 * sizeof(double);
    }
}

void extendMemory() {
    printf("Stored %i grades (%lu bytes) to the heap at %p\n", totalCount, totalCount * sizeof(double), (void *)&head);
    printf("Heap at %p is full\n",(void *)&head);
    fiveCount++;
    double* newHead = (double*)malloc(5 * fiveCount * sizeof(double));
    allocCount++;
    byteCount+=5 * fiveCount * sizeof(double);
    printf("Allocated %lu bytes to the heap at %p\n",5*fiveCount*sizeof(double),(void *)&newHead);
    for (int i = 0 ; i < totalCount ; i++) {
        *(newHead + i) = *(head + i);
    }
    printf("Copied 5 grades from %p to %p\n",(void *)&head,(void *)&newHead);
    free(head);
    freeCount++;
    printf("Freed %lu bytes from the heap at %p\n", 5*(fiveCount-1)*sizeof(double),(void *)&head);
    head = newHead;
}

double average(double* p,int n) {
    if (n==0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum+=*(p+i);
    }
    return sum/n;
}

void compare(double average, double* p) {
    
    for ( int i = 0 ; i < totalCount ; i++) {
        double current = *(p+i);
        printf("%i The grade of %lf is ",i,current);
        if (current < average) {
            printf("< the average\n");
        } else {
            printf(">= the average\n");
        }
    }
}
