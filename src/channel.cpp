#include "../includes/channel.h"

std::vector<int> channel(const std::vector<int>& c, double p, std::mt19937& gen) {
    std::vector<int> y{c};
    std::bernoulli_distribution flip(p);
    for (int& b : y) if (flip(gen)) b ^= 1;
    return y;
}