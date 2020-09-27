#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		std::sort(a.begin(), a.end());
		int r = 0;
		for (int i = 1; i < n; ++i) {
			r += (k - a[i]) / a[0];
		}
		print(r);
	}
	return 0;
}