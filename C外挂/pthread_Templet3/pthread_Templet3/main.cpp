#include <stdio.h>
#include <pthread.h>
const int NUM_THREAD = 5;
void* myfunc(void* args) {
    int tid = (int)args;
    printf("hello world! %d\n",args);
    return NULL;
}


int main(int argc, char const* argv[])
{
    pthread_t pt[NUM_THREAD];
    for (int i = 1; i <=NUM_THREAD; i++)
    {
         //�����߳�ID
        pthread_create(&pt[i], NULL, myfunc, (void*)i); //�����߳�
        pthread_join(pt[i], NULL); //�ȴ��߳̽���
    }
    pthread_exit(NULL);

    return 0;
}
