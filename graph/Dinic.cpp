struct edge
{
    int to;
    long long val;
    int rev;
    edge(int _to, long long _val, int _rev):to(_to), val(_val), rev(_rev){}
};

int n, m, s, t; 


vector<edge> adjs[MAXLEN];

int depth[MAXLEN];

bool bfs(){ //分层 + 确定没有回去找
    memset(depth, 0, sizeof(depth)); 
    depth[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int f = q.front(); q.pop();
        for(edge &adj : adjs[f]){
            if(!depth[adj.to] && adj.val){
                depth[adj.to] = depth[f] + 1;
                q.push(adj.to);
            }
        }
    }
    return depth[t];
}

long long dfs(int u = s, long long in = 0x3f3f3f3f3f3f3f3f){ //多路增广
    if(u == t) return in;
    if(in == 0) return 0;
    long long out = 0;
    for(edge &adj : adjs[u]){
        if((depth[adj.to] == (depth[u] + 1)) && adj.val){
            long long dist = dfs(adj.to, min(in, adj.val));
            adj.val -= dist;
            adjs[adj.to][adj.rev].val += dist;
            in -= dist;
            out += dist;
        }
    }
    if(!out) depth[u] = 0;
    return out;
}

long long ans = 0;

void dinic(){
    while(bfs()){
        while(long long d = dfs()){
            ans += d;
        }
    }
}
