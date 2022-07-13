int d[MAXN];
vector<int> adjs[MAXN];

int last; //最远点，  d[last] 为数的直径

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