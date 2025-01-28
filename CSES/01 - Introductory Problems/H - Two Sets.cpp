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

    int sum = (n * (n + 1)) / 2;
    
    if (sum % 2 == 0) {
        cout << "YES" << endl;

        set<int> firstSet, secondSet;

        int firstSetSum = 1;
        firstSet.insert(1);
        
        for (int i = n; i > 1; i--) {
            if (firstSetSum + i <= sum / 2) {
                firstSet.insert(i);
                firstSetSum += i;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (firstSet.find(i) == firstSet.end()) secondSet.insert(i);
        }

        cout << firstSet.size() << endl;
        for (auto x : firstSet) cout << x << " ";
        cout << endl;

        cout << secondSet.size() << endl;
        for (auto x : secondSet) cout << x << " ";

    } else {
        cout << "NO";
    }
}