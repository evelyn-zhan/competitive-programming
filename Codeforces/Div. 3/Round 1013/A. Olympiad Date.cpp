# include <bits/stdc++.h>
using namespace std;

# define GRIND    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

# define db(x) cout << #x << " -> " << x << endl

// Data Type
# define int      long long

// Constants
const int INF      = 1e18;
const int mod      = 1e9 + 7;
const int mod_2    = 998244353;
const int MAXN     = 100000;
const int MAXN2    = 200000;

// Pairs
# define pii      pair<int, int>
# define fi       first
# define se       second

// Vector
# define pb         push_back
# define All(v)     v.begin(), v.end()
# define AllR(v)    v.rbegin(), v.rend()
# define Rev(v)     reverse(All(v))
# define Sort(v)    sort(All(v))
# define SortR(v)   sort(AllR(v))

signed main() {
    GRIND
    
    int t;  cin >> t;

    while (t--) {
        int n;  cin >> n;

        int a[n + 1];
        for (int i = 1; i <= n; i++) cin >> a[i];

        int count[10];
        memset(count, 0, sizeof(count));

        bool formed = false;

        int pull = 0;

        // 01.03.2025

        for (int i = 1; i <= n and !formed; i++) {
            pull++;
            count[a[i]]++;
            if (count[0] >= 3 and count[1] >= 1 and count[2] >= 2 and count[3] >= 1 and count[5] >= 1) formed = true;
        }

        cout << (formed ? pull : 0) << endl;
    }
}