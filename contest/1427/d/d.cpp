
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1), p(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		p[a[i]] = i;
	}
	std::vector<std::vector<int>> r;
	while (1) {
		int id = 1;
		while (id < n && id > p[a[id] - 1]) ++id;
		if (id == n) break;
		std::vector<int> tmp;
		if (id > 1) tmp.emplace_back(id - 1);
		int t = id;
		while (a[t] < a[t + 1]) ++t;
		if (t > id) tmp.emplace_back(t - id);
		if (p[a[id] - 1]  > t) tmp.emplace_back(p[a[id] - 1] - t);
		if (p[a[id] - 1] < n) tmp.emplace_back(n - p[a[id] - 1]);
		r.emplace_back(tmp);
		int cur = 0, now = n;
		for (auto x : tmp) {
			for (int i = now - x + 1; i <= now; ++i) b[++cur] = a[i];
			now -= x;
		}
		a = b;
		for (int i = 1; i <= n; ++i) p[a[i]] = i;
	}
	print(r.size());
	for (auto &x : r) {
		std::cout << x.size() << " ";
		for (auto i : x) std::cout << i << " ";
		println;
	}
	return 0;
}