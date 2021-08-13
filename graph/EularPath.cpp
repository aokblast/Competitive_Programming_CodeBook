int cd[MAXLEN], rd[MAXLEN]; //有向图
vector<pair<int, int>> adjs[MAXLEN]; //first for 点, second fir 边
bool visit[MAXLEN]; //边

int cnt = 0; //判断联通(cnt == size)

void dfs(int id){
    for(auto &adj : adjs){
        if(!visit[adj.second]){
            ++cnt;
            visit[adj.second] = true;
            dfs(adj.first);
            //一些操作       
        }
    }
}

bool judge(){
    //无向(边为偶数除了端点)
    int cnt = 0;
    int qidian  = 0; // 起点
    for(int i = 0; i < n; ++i){
        if(adjs[i].size() & 1) ++cnt, qidian = i;
    }
    return (cnt == 2 || cnt == 0);

    //有向((出度 - 入度) = 1 && (入度 - 出度) = 1 || 欧拉环)
    int rdc = 0, cdc = 0;
    int qidian = 0;
    for(int i = 0; i < n; ++i){
        if((cd[i] - rd[i] == 1)) ++cdc;
        else if((rd[i] - cd[i]) == 1) ++rdc, qidian = i;
        else if((rd[i] - cd[i]) != 0) return false;
    }

    return ((cdc == 1 && rdc == 1) || (cdc == 0 && rdc == 0));
}