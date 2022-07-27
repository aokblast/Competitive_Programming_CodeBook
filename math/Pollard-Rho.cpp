// remember srand(time(NULL))

ll PR(ll n){
    if(n == 4)
        return 2;
    
    if(is_prime(n))
        return n;

    while(1){
        ll c = (rand() % (n - 1)) + 1;
        auto f = [&](const ll x){
            return ((lll) x * x + c) % n;
        };
        ll t = 0, r = 0, p = 1, q;
        do{
            for(int i = 0; i < 128; ++i){
                t = f(t), r = f(f(r));
                if(t == r || (q = (lll) p * abs(t - r)  % n) == 0)
                    break;
                p = q;
            }
            ll d = __gcd(p, n);
            if(d > 1)
                return d;
        }while(t != r);
    }
}