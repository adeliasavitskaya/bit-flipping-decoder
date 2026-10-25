#include "../includes/code.h"

std::pair<Matrix, std::vector<int>> findPivots(Matrix H) {
    int m = H.size(), N = H[0].size();
    std::vector<int> pivots;
    int row{0};

    for (int col{0}; col < N && row < m; ++col) {
        int r{row};
        while (r < m && H[r][col] == 0) ++r;
        if (r == m) continue;
        std::swap(H[r], H[row]);

        for (int i{0}; i < m; ++i) {
            if (i == row) continue;
            if (H[i][col] == 1) {
                for (int j{0}; j < N; ++j) H[i][j] ^= H[row][j];
            }
        }

        pivots.push_back(col);
        ++row;
    }
    return {H, pivots};
}

Matrix makeG(const Matrix& H) {
    int N = H[0].size();
    auto [H1, pivots] = findPivots(H);

    std::vector<bool> isPivot(N, false);
    for (int p : pivots) isPivot[p] = true;

    Matrix G;
    for (int f{0}; f < N; ++f) {
        if (isPivot[f]) continue;
        std::vector<int> v(N, 0);
        v[f] = 1;
        for (size_t k{0}; k < pivots.size(); ++k) v[pivots[k]] = H1[k][f];
        G.push_back(v);
    }
    return G;
}

std::vector<int> encode(const std::vector<int>& u, const Matrix& G) {
    int N = G[0].size(), K = G.size();
    std::vector<int> c(N, 0);
    for (int i{0}; i < K; ++i) {
        if (u[i] == 1) {
            for (int j{0}; j < N; ++j) c[j] ^= G[i][j];
        }
    }
    return c;
}
