#include <iostream>
#include "includes/matrix.h"
#include "includes/FERcalculate.h"

int main() {
    Matrix H = {
        {1, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1}
    };

    for (double p : {0.01, 0.05, 0.1, 0.5})
        std::cout << "p = " << p << "  FER = " << calculateFER(H, p) << '\n';
}