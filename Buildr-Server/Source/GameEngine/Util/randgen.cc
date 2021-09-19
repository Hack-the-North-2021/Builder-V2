#include "randgen.h"

unsigned RandGen::seed = 0;
std::default_random_engine RandGen::randEng = std::default_random_engine{seed};

int RandGen::randint(int low, int hi) {
    std::uniform_int_distribution<int> distribution(low,hi);
    return distribution(RandGen::randEng);
}

void RandGen::setSeed(unsigned newSeed)
{
  RandGen::seed = newSeed;
  RandGen::randEng = std::default_random_engine{newSeed};
}