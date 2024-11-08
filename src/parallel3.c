#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#define ARRAY_SIZE 1000000
#define THREAD_NO 10

int sum = 0;  // Global variable to hold the sum
pthread_mutex_t lock; //Global lock variable

// Thread function to sum elements of a sub-array
void *addToSum(void *arg) {
    int *subArray = (int *)arg;
    int local_sum = 0;

    // Calculate the sum of the assigned sub-array in a local variable
    for (int i = 0; i < (ARRAY_SIZE / THREAD_NO); i++) {
        local_sum += subArray[i];
    }

    // Lock once to add the local sum to the global sum
    pthread_mutex_lock(&lock);
    sum += local_sum;
    pthread_mutex_unlock(&lock);
    
    //Return
    return NULL;
}

int main() {
    int num[THREAD_NO][ARRAY_SIZE / THREAD_NO];
    pthread_t threads[THREAD_NO];
    
    srand(100);

    // Initialize arrays
    for (int i = 0; i < THREAD_NO; i++) {
        for (int j = 0; j < ARRAY_SIZE / THREAD_NO; j++) {
            num[i][j] = rand() % 100;
        }
    }
    
    //Initialize lock
    pthread_mutex_init(&lock, NULL);
    
    // Create threads
    for (int i = 0; i < THREAD_NO; i++) {
        int rc = pthread_create(&threads[i], NULL, addToSum, num[i]);
        assert(rc == 0);
    }

    // Join all threads
    for (int i = 0; i < THREAD_NO; i++) {
        int rc = pthread_join(threads[i], NULL);
        assert(rc == 0);
    }
    
    //Destory lock
    pthread_mutex_destroy(&lock);
    
    // Print the result
    printf("sum = %d\n", sum);
    return 0;
}
