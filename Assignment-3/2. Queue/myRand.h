//
//Created by Fig0_xD on 13-02-2021
//

#ifndef PROJ1_MYRAND_H
#define PROJ1_MYRAND_H

#include <ctime>

long long int my_rand()
{
    long long int m, a;
    static long long int x;
    int n;

    time_t t;

    t = time(nullptr);
    x += t;                              //seeding the generator with t
    m = 2147483647;
    a = 48271;

    n = 50;

    for(int i=0; i<n; i++)
    {
        x = (x * a) % m;                //pseudo random generator
    }

    return x;
}

#endif //PROJ1_MYRAND_H
