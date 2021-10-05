// kruskal

pair<int, pii> adjs[MAXLEN]; //first for 权重 //second.first for 起点 //second.second for 终点
int n; //边的数量
int m; //点的数量
int djs[MAXLEN];


int parent(int i){
    return (djs[i] == i) ? i : djs[i] = parent(djs[i]);
}

void kruskal(){
    for(int i = 0; i <= m; ++i){
        djs[i] = i;
    }
    
    sort(adjs, adjs + n);
    int cnt = m; //计算边的数量
    for(int i = 0; i < n; ++i){
        int p1 = parent(adjs[i].second.first), p2 = parent(adj[i].second.second); 
        if(p1 == p2) continue;
        djs[p1] = p2;
        //一些操作
        if((--cnt) == 1) break;
    }
}

//Prim 普利姆算法 

vector<pii> adjs[MAXLEN]; //first for 点, second for 权重
bool visit[MAXLEN];

int n, m;
void prim(){
	priority_queue<pii, vector<pii>, greater<pii>> q;
	int ans = 0; //最小距离
	q.push({0, 1});
	int cnt = n; //是否联通
	while(!q.empty()){
		pii top = q.top();q.pop();
		if(visit[top.second])continue;
		ans += top.first; 
		visit[top.second] = true;
		--cnt;
		for(const pii &adj : adjs[top.second]){
			if(!visit[adj.first]){
				q.push({adj.second, adj.first});
			}
		}
	}
	if(cnt){
		printf("orz\n");
	}else{
		printf("%d\n", ans);
	}

}