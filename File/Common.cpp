#include <cstdio>
#include <stdlib.h>
float randf(float max){
  return (float)max*(float)rand()/((float)RAND_MAX+1);
}
