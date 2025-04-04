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

    // Manacher's Algorithm

    // Pre-process the string to have odd length (|S| = 2n + 1)

    string str = "";

    for (int i = 0; i < N; i++) {
        str += "#";
        str += S[i];
    }

    str += "#";

    int maxLps = 0;
    
    int lps[str.length()];
    memset(lps, 0, sizeof(lps));

    int center = 0, right = 0;

    for (int pos = 0; pos < str.length(); pos++) {
        int mirroredPos = 2 * center - pos;

        if (pos < right) lps[pos] = min(right - pos, lps[mirroredPos]);

        while (pos - lps[pos] - 1 >= 0 and pos + lps[pos] + 1 < str.length() and str[pos - lps[pos] - 1] == str[pos + lps[pos] + 1]) lps[pos]++;

        if (pos + lps[pos] > right) {
            center = pos;
            right = pos + lps[pos];
        }

        maxLps = max(maxLps, lps[pos]);
    }

    cout << maxLps;
}