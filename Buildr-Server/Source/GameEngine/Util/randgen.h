#ifndef __RANDENG_H___
#define __RANDENG_H___

#include <algorithm>
#include <random>
#include <vector>


using std::vector;

class RandGen {
    // Random Generator
    static unsigned seed;
    public:
        static std::default_random_engine randEng;
        static int randint(int low, int hi);
        static void setSeed(unsigned seed);
};

#endif