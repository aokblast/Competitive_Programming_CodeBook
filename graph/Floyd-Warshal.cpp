int matrix[MAXLEN][MAXLEN]; 
//初始化成0x3f3f3f3f，有边的地方为权重，自己为0

for(int i = 0; i < n; ++i){
    for(int  j = 0; j < n; ++j){
        for(int  k = 0; k < n; ++k){
            matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
        }
    }
}