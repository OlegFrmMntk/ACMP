#include <iostream>

using namespace std;

int main()
{
    unsigned long long w, h, n;
    cin >> w >> h >> n;

    unsigned long long l = 0, r = 10000000000000000000;
    while (r - l > 1) {
        unsigned long long mid = (l + r) / 2;
        if (((mid / w) * (mid / h)) >= n) r = mid;
        else l = mid;
    }

    unsigned long long ans;
    if (((l / w) * (l / h)) >= n) ans = l;
    else ans = r;

    cout << ans;
    return 0;
}