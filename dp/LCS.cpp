char s1[MAXLEN], s2[MAXLEN];
int n, m; //字串长度
vector<int> tmp[128]; //所有可能
vector<int> lis;

void lcs(){
    for(int i = 0; i < n; ++i) tmp[s1[i]].push_back(i);
    lis.push_back(-1);
    for(int i = 0; i < m; ++i){
        char c = s2[i];
        for(int j = tmp[c].size(); j >= 0; --j  ){
            if(tmp[c][j] > lis.back()){
                lis.push_back(tmp[c][j]);
            }else{
                *lower_bound(lis.begin(), lis.end(), tmp[c][j]) = tmp[c][j];
            }
        }
    }
    int ans = lis.size() -1;

}