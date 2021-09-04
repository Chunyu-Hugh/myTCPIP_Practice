#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char *argv[])
{
    pid_t pid;
    int lval = 20;
    gval++;
    lval += 5;
    pid = fork(); //创建子进程。父进程的pid中存有子进程的ID，子进程pid=0
    if (pid == 0)
        gval += 2, lval += 2;
    else
        gval -= 2, lval -= 2;
    if (pid == 0)
        printf("chils pROC:[%d,%d]\n", gval, lval);
    else
        printf("parent pROC:[%d,%d]\n", gval, lval);
    return 0;
}