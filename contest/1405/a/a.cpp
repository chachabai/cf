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
		int n;
		std::cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		for (int i = n - 1; ~i; --i) std::cout << a[i] << " ";
		std::cout << "\n";
	}
	return 0;
}