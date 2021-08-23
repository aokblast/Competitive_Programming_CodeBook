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
        parent[p1] = p2;
        //一些操作
        if((--cnt) == 1) break;
    }
}

//Prim 普利姆算法 (待续)

void prim(){

}