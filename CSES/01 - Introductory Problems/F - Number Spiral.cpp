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
        int y, x;  cin >> y >> x;

        int layer = max(y, x);

        if (layer % 2 == 0) {
            if (y == layer) cout << layer * layer - x + 1;
            else cout << layer * layer - layer + 1 - (layer - y);
        } else {
            if (x == layer) cout << layer * layer - y + 1;
            else cout << layer * layer - layer + 1 - (layer - x);
        }

        cout << endl;
    }
}