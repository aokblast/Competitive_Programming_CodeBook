// XOR 最大值

ll p[x];

bool insert(ll x) {
    for(int i = 63; i + 1; --i) {
        if(!(x & (1ll << i)))
            continue;
        
        if(!p[i]) {
            p[i] = x;
            return true;
        }
        x^= p[i];
    }
    return false;
}