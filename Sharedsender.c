#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    void *sharedmemory;
    char buffer[100];
    int shmid=shmget((key_t)1022,1024,0666|IPC_CREAT);
    sharedmemory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",sharedmemory);
    printf("Enter data to be read to shared memory");
    read(0,buffer,100);
    strcpy(sharedmemory,buffer);
    printf("You wrote %s",(char*)sharedmemory);
    return 0;
}
