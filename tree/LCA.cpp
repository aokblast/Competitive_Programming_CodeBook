//倍增

int dep[MAXN];
int pa[MAXN][32];
vector<int> ch[MAXN];


void dfs(int u, int p){ // Pre-process
    dep[u] = dep[p] + 1;
    pa[u][0] = p;

    for(int i = 1; i < 32; ++i)
        pa[u][i] = pa[pa[u][i - 1]][i - 1];
    
    for(const int v : ch[u]){
        if(v == p)
            continue;
        dfs(v, u);
    }
}

int lca(int a, int b){
    if(dep[a] > dep[b])
        swap(a, b);

    int diff = dep[b] - dep[a];
    int i = 0;

    //调整高度
    for(; diff; ++i, diff >>= 1)
        if(diff & 1)
            b = pa[b][i];

    if(a == b)
        return a;

    i = 0;

    for(i = 31; i >= 0; --i)
        if(pa[a][i] != pa[b][i])
            a = pa[a][i], b = pa[b][i];
    
    return pa[a][0];
    
}