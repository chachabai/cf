#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl;
using LL = long long;

const int N = 1e5 + 9;
bool isp[N];
std::vector<int> p;

int initPrimeP() {
	p.emplace_back(2);
	isp[2] = true;
	for (int i = 3; i < N; i += 2) isp[i] = true;
	int sq = int(std::sqrt(N - 1))|1;
	for (int i = 3; i <= sq; i += 2) if (isp[i]) {
		p.emplace_back(i);
		for (int j = i * i; j < N; j += i << 1) {
			isp[j] = false;
		}
	}
	for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
	return p.size();
}

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	initPrimeP();
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		int nfactor = 0, nn = n;
		std::vector<std::pair<int, int>> pfactor;
		for (int i = 0; p[i] * p[i] <= nn; ++i) {
			if (nn % p[i] == 0) {
				int np = 0;
				while (nn % p[i] == 0) {
					nn /= p[i];
					++np;
				}
				nfactor += np;
				pfactor.push_back({p[i], np});
			}
		}
		if (nn > 1) {
			pfactor.push_back({nn, 1});
			++nfactor;
		}
		if (nfactor == 2 && pfactor.size() == 2) {
			std::cout << pfactor[0].first << " " << pfactor[1].first << " " << n << std::endl;
			print(1);
			continue;
		}
		auto printp = [&](int i) {
			int r = 1;
			for (int id = 0; id < pfactor[i].second; ++id) {
				r *= pfactor[i].first;
				std::cout << r <<" ";
			}
		};
		if (pfactor.size() == 1) {
			printp(0);
			println;
			print(0);
			continue;
		}
		std::vector<int> factor;
		int sq = std::sqrt(n + 0.2);
		std::vector<int> f1(sq + 2), f2(sq + 2);
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				factor.emplace_back(i);
				if(i * i != n) factor.emplace_back(n / i);
			}
		}
		auto isv = [&](int x) {
			return x <= sq ? f1[x] : f2[n / x];
		};
		auto vis = [&](int x) {
			if (x <= sq) f1[x] = true;
			else f2[n / x] = true;
		};
		std::cout << n << " ";
		printp(0);
		for (int i = 1; i < pfactor.size(); ++i) {
			int xx = pfactor[i - 1].first * pfactor[i].first;
			for (auto x : factor) if (!isv(x) && x % xx == 0) {
				vis(x);
				std::cout << x << " ";
			}
			printp(i);
		}
		int xx = pfactor.back().first * pfactor[0].first;
		for (auto x : factor) if (!isv(x) && x % xx == 0) {
			vis(x);
			std::cout << x << " ";
		}
		println;
		print(0);
	}
	return 0;
}