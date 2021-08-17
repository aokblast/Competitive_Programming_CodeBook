int v[MAXLEN][MAXLEN]; 
//初始化成0x3f3f3f3f，有边的地方为权重，自己为0

for(int k = 0; k < n; ++k){
    for(int  i = 0; i < n; ++i){
        for(int  j = 0; j < n; ++j){
            v[i][j] = min(v[i][k] + v[k][j], v[i][j]); //最短路径
            v[i][j] = min(v[i][j], max(v[i][k], v[k][j])); //最大的最小
        }
    }
}