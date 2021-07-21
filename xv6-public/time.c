#include "types.h"
#include "stat.h"
#include "user.h"

// The idea is that if anything is given after time we try to calculate its
// runtime and waittime else we return the time for closure of forked process.
int main(int argc, char *argv[])
{
    int wtime, rtime;
    int pid = fork();
    if (pid == -1)
        printf(1, "Some error occurred during forking.\n");
    else if (pid == 0)
    {
        // child
        if (argc == 1)
            exit();
        exec(argv[1], 1 + argv);
    }
    else
    {
        //parent
        int ch_pid = waitx(&wtime, &rtime);
        printf(1, "The process with pid %d exited.\n", ch_pid);
        printf(1, "Runtime (time spent in RUNNING state) = %d ticks\n", rtime);
        printf(1, "Wait time (time spent in RUNNABLE state) = %d ticks\n", wtime);
    }
    exit();
}
