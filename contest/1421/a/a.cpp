#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int a, b;
		std::cin >> a >> b;
		int r = 0, n2 = 1;
		while (a > 0 || b > 0) {
			if ((a & 1) != (b & 1)) r += n2;
			n2 *= 2;
			a >>=1;
			b >>=1;
		}
		print(r);
	}
	return 0;
}