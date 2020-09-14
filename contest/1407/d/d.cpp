#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	int h[n], dp[n];
	for (int i = 0 ;i < n; ++i) std::cin >> h[i];
	std::vector<int> low{0}, high{0};
	dp[0] = 0;
	for (int i = 1; i < n; ++i) {
		dp[i] = dp[i - 1] + 1;
		while (!low.empty() && h[i] >= h[low.back()]) {
			int x = h[low.back()];
			low.pop_back();
			if (h[i] > x && !low.empty()) dp[i] = std::min(dp[i], dp[low.back()] + 1);
		}
		while (!high.empty() && h[i] <= h[high.back()]) {
			int x = h[high.back()];
			high.pop_back();
			if (h[i] < x && !high.empty()) dp[i] = std::min(dp[i], dp[high.back()] + 1);
		}
		low.emplace_back(i);
		high.emplace_back(i);
	}
	std::cout << dp[n - 1] << std::endl;
	return 0;
}