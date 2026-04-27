#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        printf("failed\n");
    }else if(pid == 0){
        printf("child process\n"); 
        printf("child pid: %d\n", getpid());
        printf("parent pid: %d\n", getppid());
    }else{
        printf("parent process\n");
        printf("parent pid: %d\n", getpid());
        printf("child pid: %d\n", pid);
    }
}