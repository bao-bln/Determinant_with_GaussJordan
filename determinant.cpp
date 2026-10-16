#include <bits/stdc++.h>
#define nmax 101

double a[nmax][nmax] {};
int n {};

void inMatrix() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
        }
    }
}

void outMatrix(double b[][nmax], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << b[i][j] << " ";
        }
        std::cout << '\n';
    }
}

double determinant() {
    double det = 1;

    for (int k = 1; k <= n; k++) {
        int p = k;

        for (int i = k + 1; i <= n; i++) {
            if (std::fabs(a[i][k]) > std::fabs(a[p][k])) {
                p = i;
            }
        }

        if (std::fabs(a[p][k]) < 1e-12) {
            return 0;
        }

        if (p != k) {
            for (int j = 1; j <= n; j++) {
                std::swap(a[p][j], a[k][j]);
            }
            det = -det;
        }

        double pivot = a[k][k];
        det *= pivot;

        for (int i = k + 1; i <= n; i++) {
            double factor = a[i][k] / pivot;

            for (int j = k + 1; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }

            a[i][k] = 0;
        }
    }
    return det;
}

int main() {
    inMatrix();

    std::cout << "Det: " << determinant() << '\n';
    outMatrix(a, n);
    return 0;
}
