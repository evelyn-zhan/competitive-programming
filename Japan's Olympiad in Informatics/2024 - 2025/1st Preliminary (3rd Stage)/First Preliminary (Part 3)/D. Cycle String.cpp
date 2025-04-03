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
    
    int N;  cin >> N;
    string S;  cin >> S;

    bool isPossible = false;

    for (int sz = 1; sz <= N / 2 and !isPossible; sz++) {
        if (N % sz != 0) continue;
        bool flag = true;
        for (int i = 0; i < N and flag; i++) {
            if (S[i] != S[i % sz]) flag = false;
        }
        if (flag) isPossible = true;
    }

    cout << (isPossible ? "Yes" : "No") << endl;
}