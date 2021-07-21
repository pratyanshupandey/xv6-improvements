#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
        printf(1, "too less arguments");
    else if (argc > 3)
        printf(1, "too many arguments");
    else
        printf(1, "The Previous priority was %d\n", set_priority(atoi(argv[1]), atoi(argv[2])));
    exit();
}