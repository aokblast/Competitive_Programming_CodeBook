int tmp[MAXLEN]; //暂存
int arr[MAXLEN]; //待处理数组
int dp[MAXLEN]; //各个结尾的值

void LIS(){
    for(int i = 0; i <= n; ++i) tmp[i] = INT_MAX;
    tmp[0] = 0;
    for(int i = 0; i < n; ++i){
        int pos = lower_bound(tmp, tmp + n, arr[i]) - tmp; //lower_bound找< // upper_bound找<=
        tmp[pos] = arr[i], dp[i] = pos;
    }
}