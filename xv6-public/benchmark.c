#include "types.h"
#include "user.h"

int number_of_processes = 10;

int main(int argc, char *argv[])
{
  int option;
  if (argc == 1)
    option = 1;
  else
  {
    option = atoi(argv[1]);
    printf(1, "For this benchmark we have calculated sum of runtimes \nand waiting times of all the sub processes and\n divided by number of subprocesses to get the average\n");
  }
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        {
          sleep(200); //io time
        }
        else
        {
          if (option == 1)
            ;
          else
          {
            argv[1] = "bcnt";
            exec(argv[1], 1 + argv);
          }
        }
      }
      //   printf(1, "Process: %d Finished\n", j);
      exit();
    }
    else
    {
      ;
      set_priority(100 - (20 + j), pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
    }
  }
  int total_rtime = 0, total_wtime = 0, rtime = 0, wtime = 0, ch_pid;
  for (j = 0; j < number_of_processes + 5; j++)
  {
    rtime = wtime = 0;
    ch_pid = waitx(&wtime, &rtime);
    if (ch_pid != -1)
    {
      printf(1, "Process with pid = %d exited with rtime = %d and wtime = %d and total time = %d\n", ch_pid, rtime, wtime, rtime + wtime);
      total_rtime += rtime;
      total_wtime += wtime;
    }
  }
  printf(1, "Average Run time(time running on CPU i.e. RUNNING state) = %d\n", total_rtime / number_of_processes);
  printf(1, "Average Wait time(time spent in RUNNABLE state) = %d\n", total_wtime / number_of_processes);
  printf(1, "Average Total time = %d\n", (total_wtime + total_rtime) / number_of_processes);
  exit();
}
