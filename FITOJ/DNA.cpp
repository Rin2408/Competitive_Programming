#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
int N;
long long a[MAXN], D[MAXN];
long long M[MAXN][MAXN];

long long Cal(int L, int R) {
    if (L == R) return 0;
    if (M[L][R] != -1) return M[L][R];

    long long res = LLONG_MAX;
    for (int i = L; i < R; i++) {
        long long tmp = Cal(L, i) + Cal(i + 1, R) + D[R] - D[L - 1];
        if (tmp < res) res = tmp;
    }
    return M[L][R] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        D[i] = D[i - 1] + a[i];
    }
    memset(M, -1, sizeof(M));

    cout << Cal(1, N) << '\n';
}
