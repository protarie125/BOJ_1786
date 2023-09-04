#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

string T, P;
vi pi;

void makePi() {
	pi = vi(P.length(), 0);
	auto j = int{ 0 };
	for (auto i = 1; i < P.length(); ++i) {
		while (0 < j && P[i] != P[j]) {
			j = pi[j - 1];
		}

		if (P[i] == P[j]) {
			++j;
			pi[i] = j;
		}
	}
}

vi kmp() {
	auto ret = vi{};
	auto j = int{ 0 };
	for (auto i = 0; i < T.length(); ++i) {
		while (0 < j && T[i] != P[j]) {
			j = pi[j - 1];
		}

		if (T[i] == P[j]) {
			if (P.length() - 1 == j) {
				ret.push_back(i - P.length() + 1);
				j = pi[j];
			}
			else {
				++j;
			}
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	getline(cin, T);
	getline(cin, P);

	makePi();
	auto ans = kmp();
	cout << ans.size() << '\n';
	for (const auto& x : ans) {
		cout << x + 1 << ' ';
	}

	return 0;
}