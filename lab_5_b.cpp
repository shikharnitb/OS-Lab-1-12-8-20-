/*
Q2- 
	A C program to show multiple threads with local, global and static variables. Create three threads
	and print the value of the static, global and local variable.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
// global variable  
int g = 0;
void *myThreadFun(void *vargp) 
{ 
    int *myid = (int *)vargp; 
    // local variable
    int l =1;
    // static variable  
    static int s = 0; 
  
    // Change static and global variables 
    ++s; ++g; 
    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, ++s, ++g,++l); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
  
    // hreads creation
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
  
    pthread_exit(NULL); 
    return 0; 
}
