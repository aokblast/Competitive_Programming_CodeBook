//DFS两次

int d[MAXN];
vector<int> adjs[MAXN];

int last; //最远点，  d[last] 为数的直径 不可做负边

int bfs(int u, int p){
    queue<pair<int, int>> q;
    q.push({u, p});
    while(!q.empty()){
        auto [u, p] = q.front(); q.pop();
        for(const int adj : adjs[u]){
            if(adj == p)
                continue;
            d[adj] = d[u] + 1;
            last = adj;
            q.push({adj, u});
        }
    }
}

int farPoint(int u, int p){
    last = u;
    bfs(u, p);
    d[last] = 0;
    bfs(last, p);
    return d[last];
}

//树形DP， 可做负边

int n, d = 0;
int d1[N], d2[N];
vector<int> adjs[N];

void dfs(int u, int p) {
  d1[u] = d2[u] = 0;
  for (int v : adjs[u]) {
    if (v == p) 
        continue;
    dfs(v, u);
    int t = d1[v] + 1; //可改权重
    if (t > d1[u])
      d2[u] = d1[u], d1[u] = t;
    else if (t > d2[u])
      d2[u] = t;
  }
  d = max(d, d1[u] + d2[u]);
}