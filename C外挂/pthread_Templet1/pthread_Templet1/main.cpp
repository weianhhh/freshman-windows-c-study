#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#pragma warning(disable:4996)
#pragma warning(disable:4716)

#define NUMBER_OF_THREADS 10000
#define TASK_SIZE 10000000

void* perform_task(void* tid);

int main(void) {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // 记录开始时间

    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        printf("Main here. Creating thread %d\n", i);
        status = pthread_create(&threads[i], NULL, perform_task, (void*)i);
        if (status != 0) {
            printf("pthread_create returned error code %d\n", status);
            exit(-1);
        }
    }

    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    end = clock(); // 记录结束时间

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("代码执行时间：%f 秒\n", cpu_time_used);

    exit(0);
}

void* perform_task(void* tid) {
    int thread_id = (int)tid;
    int i;
    double result = 0.0;

    for (i = 0; i < TASK_SIZE; i++) {
        result += i * 2.0 + 1.0;
    }

    printf("Thread %d: Result = %f\n", thread_id, result);

    pthread_exit(NULL);
}
