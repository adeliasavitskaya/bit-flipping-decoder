#ifndef BFD_CHANNEL_H
#define BFD_CHANNEL_H

#include <random>

std::vector<int> channel(const std::vector<int>& c, double p, std::mt19937& gen);

#endif