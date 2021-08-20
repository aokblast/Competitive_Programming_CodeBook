pii intv[MAXLEN];
int n; //区间数量
int end; //终点


int solve(){
    sort(intv, intv + n);
    int tmp = 0 /* 暂存 */ , r = 0 /* 右边更新 */; 
    int sum = 0; //答案
    int i = 0;
    while(i < n && r < end){
        if(intv[i].first > r) break;
        while(intv[i].first <= r  && tmp < end){
            tmp = max(intv[i].second, tmp);
            ++i;
        }
        r = tmp;
        ++sum;
    }
    return r >= end : sum ? 0; // 没有则回传0
}