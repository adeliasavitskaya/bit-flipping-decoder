#ifndef BFD_BFD_H
#define BFD_BFD_H

#include "matrix.h"
#include <vector>

struct DecodeResult {
    bool success;
    std::vector<int> codeword;
};

DecodeResult BitFlippingDecoder(const std::vector<int>& y, const Matrix& H, int I_max);

#endif