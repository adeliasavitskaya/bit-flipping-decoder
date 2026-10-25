#include <random>
#include "includes/FERcalculate.h"


double calculateFER(const Matrix& H, double p, int I_max,
                    int nFrames, unsigned seed) {
    Matrix G = makeG(H);
    int K = G.size();
    std::mt19937 gen(seed);
    int frameErrors{0};

    for (int f{0}; f < nFrames; ++f) {
        std::vector<int> msg(K);
        for (int& b : msg) b = gen() & 1;
        std::vector<int> c = encode(msg, G);
        std::vector<int> y = channel(c, p, gen);
        auto res{BitFlippingDecoder(y, H, I_max)};
        if (res.success == false || res.codeword != c) ++frameErrors;
    }
    return static_cast<double>(frameErrors) / nFrames;
}