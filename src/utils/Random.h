#ifndef H_RANDOM
#define H_RANDOM

  #include <time.h>
  #include <random>

  int Random(int min, int max) {
    return rand() % max + min;
  }

#endif
