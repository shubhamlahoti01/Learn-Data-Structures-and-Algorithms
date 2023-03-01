/* Shubham lahoti */
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define	fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void fileIO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/* --------------------------( Shubham Lahoti )-------------------------- */



void solve() {
	int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	int n = 9;
	int V;
	cin >> V;
	vector<int>ans;

	for (int i = n - 1; i >= 0; i--) {
		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}


int32_t main() {
	fastIO
	fileIO();

	int t = 1;
	// cin>>t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}
