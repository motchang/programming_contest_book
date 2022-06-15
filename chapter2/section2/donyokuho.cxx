#include <queue>
#include <cstdio>

// コインの金額
const int V[6] = {1, 5, 10, 50, 100, 500};

// 入力
int C[6]; // C[0] = C_1, C[1] = C_5, ...
int A = 620;

void solve() {
	int ans = 0;

	for (int i = 5; i >= 0; i--) {
		int t = min(A / V[i], C[i]); // コインiを使う枚数
		A -= t * V[i];
		ans += t; // 今回はコインを何枚使うかなのでこれでよい。コインの種別ごとに枚数を出したいならtも配列にすればよい
	}

	printf("%d\n", ans);
}
