#include "../includes/bfd.h"

static bool syndrome_ok(const std::vector<int>& M, const std::vector<std::vector<int>>& B) {
    for (const auto& row : B) {
        int s_j{0};
        for (int i : row) s_j ^= M[i];
        if (s_j != 0) return false;
    }
    return true;
}

DecodeResult BitFlippingDecoder(const std::vector<int>& y, const Matrix& H, int I_max)
{
    if (H.empty() || H[0].empty()) return DecodeResult{false, {}};

    int N{static_cast<int>(H[0].size())};
    int m{static_cast<int>(H.size())};
    std::vector<int> M = y;

    std::vector<std::vector<int>> B(m), A(N);
    for (int j{0}; j < m; ++j)
        for (int i{0}; i < N; ++i)
            if (H[j][i] == 1) { B[j].push_back(i); A[i].push_back(j); }

    if (syndrome_ok(M, B)) return DecodeResult{true, M};

    std::vector<std::vector<int>> E(m, std::vector<int>(N, 0));

    for (int iter{0}; iter < I_max; ++iter) {
        for (int j{0}; j < m; ++j) {
            for (int i : B[j]) {
                int sum{0};
                for (int i2 : B[j]) {
                    if (i2 == i) continue;
                    sum ^= M[i2];
                }
                E[j][i] = sum;
            }
        }

        for (int i{0}; i < N; ++i) {
            int votes_to_flip{0};
            for (int j : A[i]) {
                votes_to_flip += (E[j][i] ^ y[i]);
            }
            int k{static_cast<int>(A[i].size())};
            M[i] = (2 * votes_to_flip > k) ? (y[i] ^ 1) : y[i];
        }

        if (syndrome_ok(M, B)) return DecodeResult{true, M};
    }

    return DecodeResult{false, {}};
}