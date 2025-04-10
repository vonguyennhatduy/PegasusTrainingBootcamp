#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD = 1e9 + 7;

int n, m, a[105], b[105];

bool check (int mid) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = mid / (b[i] + 1);
        int du = mid % (b[i] + 1);
        sum += 1LL * a[i] * b[i] * tmp + 1LL * du * a[i];
    }
    return sum >= m;
}

void binary_search () {
    int l = 1, r = 2e15, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << endl;
}

void MAIN () {

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    for (int i = 1; i <= 100; i++) {
        if (check(i)) {
            cout << i << " ";
            return ;
        }
    }
    

    binary_search();
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numTests = 1;
    // cin >> numTests;
    for (int i = 1; i <= numTests; i++) 
        MAIN();
    return 0;
}
