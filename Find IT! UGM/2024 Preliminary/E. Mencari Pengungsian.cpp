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
    
    int N, Q;  cin >> N >> Q;

    int X[N + 1];
    for (int i = 1; i <= N; i++) cin >> X[i];

    sort(X + 1, X + N + 1);

    int pref[N + 1], suff[N + 2];

    pref[0] = 0, suff[N + 1] = 0;

    for (int i = 1; i <= N; i++) pref[i] = pref[i - 1] + (i - 1) * (X[i] - X[i - 1]);
    for (int i = N; i >= 1; i--) suff[i] = suff[i + 1] + (N - i) * (X[i + 1] - X[i]);

    int left, right, mid, leftPos, rightPos;
    
    while (Q--) {
        int L, R;  cin >> L >> R;

        // Left wall
        left = 1, right = N, leftPos = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (X[mid] <= L) {
                leftPos = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Right wall
        left = 1, right = N, rightPos = N + 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (X[mid] >= R) {
                rightPos = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        int ans = 0;

        if (leftPos > 0) {
            ans += pref[leftPos] + leftPos * (L - X[leftPos]);
        }

        if (rightPos < N + 1) {
            ans += suff[rightPos] + (N - rightPos + 1) * (X[rightPos] - R);
        }

        cout << ans << endl;
    }
}