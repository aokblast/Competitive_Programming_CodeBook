//Andrew


// 点，上凸包，下凸包

using pdd = pair<double, double>
pdd ps[MAXN], u[MAXN], d[MAXN];

int ui = 0, di = 0;

inline double cross(const pdd &p1, const pdd &p2, const pdd &p3){
    return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
}


void andrew(){
    sort(ps, ps + n);
    for(int i = 0; i < n; ++i){
        while(ui >= 2 && cross(u[ui - 2], u[ui - 1], ps[i]) <= 0)
            --ui;
        while(di >= 2 && cross(d[di - 2], d[di - 1], ps[i]) >= 0)
            --di;
        
        u[ui++] = ps[i];
        d[di++] = ps[i];
    }
    
}