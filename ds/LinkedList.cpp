struct {
    int l = 0, r = 0;
} lst[MAXLEN]; 

void init() {
    memset(lst, -1, sizeof(lst));
    lst[1].l = 0;
    lst[0].r = 1;
}

void addl(int now, int node) { //加在node的左边
    lst[now].r = node;
    lst[lst[node].l].r = now;
    lst[now].l = lst[node].l;
    lst[node].l = now;
}

void addr(int now, int node) { //加在node的右边
    lst[now].l = node;
    lst[lst[node].r].l = now;
    lst[now].r = lst[node].r;
    lst[node].r = now;
}

void remove(int node) {
    if (!~lst[node].l)return;
    lst[lst[node].l].r = lst[node].r;
    lst[lst[node].r].l = lst[node].l;
    lst[node].l = lst[node].r = -1;
}