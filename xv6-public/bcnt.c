#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{

    for (volatile int i = 0; i < 1000000; ++i)
    {
        for (volatile int j = 0; j < 50; ++j)
        {
            volatile float a = 0;
            volatile float b = 1.39;
            volatile float c = 1.917;
            a = (a * b + c);
            b = a + c;
            c = c + a * b;
        }
    }

    exit();
}
