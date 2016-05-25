#ifndef H_RANDOM
#define H_RANDOM

  int Random(int min, int max) {
    return rand() % max + min;
  }

#endif
