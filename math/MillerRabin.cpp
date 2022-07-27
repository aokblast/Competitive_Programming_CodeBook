// allow condition 1, 1, 1, 1, ..... 
//                 X, X, X, X, X, p - 1, 1, 1, 1, ....
//                 p - 1, 1, 1, 1, 1, 1, .....
//                 0 (cannot check) multiply of p

bool is_prime(ll p){
    if(p < 3 || p % 2 == 0)
        return p == 2;
    ll u = p - 1;
    int t = 0;
    while(!(u & 1))
        u >>= 1, ++t;
    
    const static ll ud[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    for(const ll a : ud){
        ll v = qpow(a, u, p);
        if(v <= 1 || v == p - 1)
            continue;
        
        for(int j = 1; j <= t; ++j){
            v = qmul(v, v, p);
            if(v == p - 1 && j != t){
                v = 1;
                break;
            }
            if(v == 1)
                return false;
        }
        if(v != 1)
            return false;
    }
    return true;
}