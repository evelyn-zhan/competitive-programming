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
    
    int Sx, Sy, Fx, Fy;  cin >> Sx >> Sy >> Fx >> Fy;

    int N;  cin >> N;

    vector<pii> point;
    vector<pair<pii, pii>> line;

    point.pb({Sx, Sy});
    point.pb({Fx, Fy});

    for (int i = 1; i <= N; i++) {
        int Ax, Ay, Bx, By;  cin >> Ax >> Ay >> Bx >> By;
        point.pb({Ax, Ay});
        point.pb({Bx, By});
        line.pb({{Ax, Ay}, {Bx, By}});
    }

    vector<pair<int, double>> adj[point.size()];

    bool connected[point.size()][point.size()];
    memset(connected, false, sizeof(connected));

    for (int i = 0; i < point.size(); i++) {
        for (int j = 0; j < point.size(); j++) {
            bool intersect = false;

            for (int k = 0; k < line.size(); k++) {
                if (point[i].fi == line[k].fi.fi and point[i].se == line[k].fi.se and point[j].fi == line[k].se.fi and point[j].se == line[k].se.se) {
                    intersect = true;
                    break;
                }
                
                pii delta_1, delta_2, delta_3, delta_4, delta_5, delta_6;
                int res_1, res_2, res_3, res_4;

                delta_1 = {line[k].fi.fi - line[k].se.fi, line[k].fi.se - line[k].se.se};
                delta_2 = {line[k].fi.fi - point[i].fi, line[k].fi.se - point[i].se};
                delta_3 = {line[k].fi.fi - point[j].fi, line[k].fi.se - point[j].se};

                res_1 = delta_1.fi * delta_2.se - delta_1.se * delta_2.fi;
                res_2 = delta_1.fi * delta_3.se - delta_1.se * delta_3.fi;

                delta_4 = {point[i].fi - point[j].fi, point[i].se - point[j].se};
                delta_5 = {point[i].fi - line[k].fi.fi, point[i].se - line[k].fi.se};
                delta_6 = {point[j].fi - line[k].se.fi, point[j].se - line[k].se.se};

                res_3 = delta_4.fi * delta_5.se - delta_4.se * delta_5.fi;
                res_4 = delta_4.fi * delta_6.se - delta_4.se * delta_6.fi;

                if ((res_1 < 0 and res_2 > 0 or res_1 > 0 and res_2 < 0) and (res_3 < 0 and res_4 > 0 or res_3 > 0 and res_4 < 0)) {
                    intersect = true;
                    break;
                }
            }

            if (!intersect and !connected[i][j]) {
                double distance = sqrt((point[i].fi - point[j].fi) * (point[i].fi - point[j].fi) + (point[i].se - point[j].se) * (point[i].se - point[j].se));
                adj[i].pb({j, distance});
                adj[j].pb({i, distance});
                connected[i][j] = connected[j][i] = true;
            }
        }
    }

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    
    vector<double> distance;
    distance.assign(point.size(), INF);

    pq.push({0, 0});
    distance[0] = 0;

    while (!pq.empty()) {
        double dist = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        for (auto v : adj[u]) {
            if (dist + v.se < distance[v.fi]) {
                distance[v.fi] = dist + v.se;
                pq.push({distance[v.fi], v.fi});
            }
        }
    }

    cout << fixed << setprecision(2) << distance[1];
}