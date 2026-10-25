#ifndef BFD_CODE_H
#define BFD_CODE_H

#include "matrix.h"
#include <vector>

std::pair<Matrix, std::vector<int>> findPivots(Matrix H);
Matrix makeG(const Matrix& H);
std::vector<int> encode(const std::vector<int>& u, const Matrix& G);

#endif