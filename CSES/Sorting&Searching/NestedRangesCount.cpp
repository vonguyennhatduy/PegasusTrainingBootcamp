#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
const int MOD = 1e9 + 7;

int n, bit[400005], ans[200005], res[200005];
pair <pair <int, int>, int> a[200005];

bool cmp_contained (pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
    if (a.fi.fi != b.fi.fi) {
        return a.fi.fi < b.fi.fi;
    } else return a.fi.se > b.fi.se;
}

bool cmp_contains (pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
    if (a.fi.fi != b.fi.fi) {
        return a.fi.fi > b.fi.fi;
    } else return a.fi.se < b.fi.se;
}

void update (int pos, int val) {
    for (; pos <= 2 * n; pos += (pos & (-pos))) {
        bit[pos] += val;
    }
}

int fen (int pos) {
    int sum = 0;
    for (; pos > 0; pos -= (pos & (-pos))) {
        sum += bit[pos];
    }
    return sum;
}


void IHateThisProblem () {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i;
    }

    set <int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(a[i].fi.fi);
        s.insert(a[i].fi.se);
    }

    vector <int> compress (s.begin(), s.end());

    for (int i = 1; i <= n; i++) {
        int l = lower_bound(compress.begin(), compress.end(), a[i].fi.fi) - compress.begin();
        int r = lower_bound(compress.begin(), compress.end(), a[i].fi.se) - compress.begin();
        a[i].fi.fi = l + 1;
        a[i].fi.se = r + 1;
    }

    sort (a + 1, a + n + 1, cmp_contains);
    memset (bit, 0, sizeof bit);

    for (int i = 1; i <= n; i++) {
        int cnt = fen (a[i].fi.se);
        if (cnt > 0) {
            ans[a[i].se] += cnt;
        }
        update(a[i].fi.se, 1);
    }

    sort (a + 1, a + n + 1, cmp_contained);
    memset(bit, 0, sizeof bit);

    for (int i = 1; i <= n; i++) {
        int cnt = fen(2 * n) - fen(a[i].fi.se - 1);
        if (cnt > 0) {
            res[a[i].se] += cnt;
        }
        update(a[i].fi.se, 1);
    }

    for (int i = 1; i <= n; i++) 
        cout << ans[i] << " ";

    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    
}

signed main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int numTests = 1;
    // cin >> numTests;
    for (int i = 1; i <= numTests; i++) 
        IHateThisProblem();
    return 0;
}   

