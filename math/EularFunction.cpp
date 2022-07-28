// 单一

int Ep(int n){
    int lim = sqrt(n);
    int res = n;
    
    for(int i = 2; i <= lim; ++i){
        if(n % i == 0){
            res = res / i * (i - 1);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        res = res / n * (n - 1);
    return res;
}

// 值域

bool vis[MAXN] = {false};
int primes[MAXN];
int phi[MAXN];

void build(){
    int tot = 0;
    phi[1] = 1;
    
    for(int i = 2; i <= n; ++i){
        if(!vis[i])
            primes[tot++] = i, phi[i] = i - 1;
        for(int j = 0; j < tot && i * primes[j] <= n; ++j){
            vis[i * primes[j]]  = true;
            if(i % primes[j])
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            else{
                phi[i * primes[j]] = primes[j] * phi[i];
                break;
            }
        }
    }
}


