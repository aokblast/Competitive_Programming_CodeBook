vector<int> adjs[MAXLEN];
int rd[MAXLEN]; //入度
int n; //点的数量
vector<int> ans; //结果

void topSort(){
    queue<int> q;
    int cnt= 0;
    for(int i = 0; i < n; ++i) if(!rd[i]) q.push(i), ++cnt, ans.push_back(i);
    while(!q.empty()){
        int f = q.front(); q.pop();
        for(auto adj : adjs[f]){
            --rd[adj];
            if(!rd[adj]) q.push(adj), ++cnt, ans.push_back(adj);
        }
    }
    if(cnt == n) {}//有找到
    else {} //没找到
}