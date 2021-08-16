vector<pair<int, int>> adjs[MAXLEN]; //first for 点 second for 权重
int dis[MAXLEN]; //最短路径
int m, n; //n 点数 m 边数 

bool bellman(){
    memset(dis, 0x3f, 4 * n);
    for(int c = 0; c < n - 1; ++c){
	    for(int i = 0; i < n; ++i){
		    for(auto adj : adjs[i]){
			    dis[adj.first] = min(dis[adj.first], dis[i] + adj.second);
		    }
	    }
    }
    bool hasAnswer = false;
	for(int i = 0; i < n; ++i){
		for(auto adj : adjs[i]){
			if(dis[adj.first] > dis[i] + adj.second){
				hasAnswer = true;
				goto ans;
			}
		}
	}
    ans:
    return hasAnswer;
}