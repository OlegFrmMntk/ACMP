#include <iostream>
#include <algorithm>

using namespace std;

int a[100];

pair <int, bool> check(const int& size, const int& k)
{
	int sum = 0, mx = 0, cnt = 1;
	for (const int& numberOfLists : a) {
		if (numberOfLists + sum > size) {
			mx = max(mx, sum);
			sum = numberOfLists;
			cnt++;
		}
		else sum += numberOfLists;
	}
	mx = max(mx, sum);

	if (cnt > k) return make_pair(mx, false);
	else return make_pair(mx, true);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int k;
	cin >> k;

	int l = 0;
	for (auto numberOfLists : a)
		l = max(l, numberOfLists);

	int ans = INT_MAX, r = 32767, mx;
	while (r - l > 1) {
		int mid = (l + r) / 2;

		if (check(mid, k).second) r = mid;
		else l = mid;
	}

	mx = check(l, k).first;
	if (check(l, k).second) {
		ans = min(ans, mx);
	}
	else ans = min(ans, check(r, k).first);

	cout << ans;
	return 0;
}
