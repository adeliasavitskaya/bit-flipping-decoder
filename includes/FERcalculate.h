#ifndef BFD_FERCALCULATE_H
#define BFD_FERCALCULATE_H

#include "code.h"
#include "matrix.h"
#include "bfd.h"
#include "channel.h"

double calculateFER(const Matrix& H, double p, int I_max=10,
                    int nFrames = 10000, unsigned seed = 42);

#endif