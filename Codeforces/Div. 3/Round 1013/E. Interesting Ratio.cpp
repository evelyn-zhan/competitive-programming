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

vector<bool> isPrime(10000001);

void eratosthenes(int n) {
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) isPrime[i] = true;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
}

signed main() {
    GRIND

    eratosthenes(10000000);

    int t;  cin >> t;

    while (t--) {
        int n;  cin >> n;

        int ans = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) ans += n / i;
        }

        cout << ans << endl;
    }
}