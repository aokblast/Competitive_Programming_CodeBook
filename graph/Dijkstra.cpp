vector<pair<int, int>> adjs[MAXLEN]; //first for 点 second for 边权
int dis[MAXLEN];
bool visit[MAXLEN];

void dij(int id){
    memset(dis, 0x3f, sizeof(dis));
    dis[id] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q; 
    //first for 目前距离 second for 点
    q.push({0, id});
    while(!q.empty()){
        pair<int, int> front = q.top(); q.pop();
        if(visit[front.second]) continue;
        visit[front.second] = true;
        for(auto adj : adjs[front.second]){
            if((adj.second + dis[front.second]) <  dis[adj.first]){
                dis[adj.first] = adj.second + dis[front.second];
                if(visit[adj.first]) continue;
                q.push({dis[adj.first], adj.first});
            }
        }
    }
}

