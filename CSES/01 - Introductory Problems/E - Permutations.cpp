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
    
    int n;  cin >> n;

    if (n == 2 or n == 3) {
        cout << "NO SOLUTION";
    } else {
        cout << (n + 1) / 2 << " ";

        if (n % 2 == 1) {
            for (int i = 1; i <= n / 2; i++) {
                cout << n - i + 1 << " " << i << " ";
            }
        } else {
            for (int i = 1; i < n / 2; i++) {
                cout << n - i + 1 << " " << i << " ";
            }
            cout << n / 2 + 1;
        }
    }
}