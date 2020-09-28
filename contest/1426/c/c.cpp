#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		int r = n - 1;
		for (int i = 1; i <= n; i = n / (n / i) + 1) {
			r = std::min(r, i - 2 + (n + i - 1) / i);
		}
		print(r);
	}
	return 0;
}