ll vals[MAXN << 2] = {0};
ll tag[MAXN << 2] = {0};
ll arr[MAXN];


void build(int u, int l, int r) {
  if(l == r)
    return void(vals[u] = arr[l]);
  int mid = l + (r - l) / 2;

  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  vals[u] = vals[u << 1] + vals[u << 1 | 1];
}

void push_down(int u, int l, int r) { //拿parent的tag来更新
  vals[u] += tag[u >> 1] * (r - l + 1); 
  tag[u] += tag[u >> 1];
}

void insert(int u, int l, int r, int ul, int ur, int val) {

  if(l >= ul && r <= ur)
    return void((vals[u] += (r - l + 1) * val, tag[u] += val)); //标记添加在当前点上

  int mid = l + (r - l) / 2;
  
  push_down(u << 1, l, mid);
  push_down(u << 1 | 1, mid + 1, r);

  tag[u] = 0;

  if(ul <= mid)
    insert(u << 1, l, mid, ul, ur, val);
  if(mid < ur)
    insert(u << 1 | 1, mid + 1, r, ul, ur, val);

  vals[u] = vals[u << 1] + vals[u << 1 | 1]; //用child的值来算加总
}

ll query(int u, int l, int r, int ul, int ur) {
  if(l >= ul && r <= ur)
    return vals[u];

  int mid = l + (r - l) / 2;
  push_down(u << 1, l, mid);
  push_down(u << 1 | 1, mid + 1, r);
  tag[u] = 0;

  ll sum = 0;

  if(ul <= mid)
    sum += query(u << 1, l, mid, ul, ur);
  if(mid < ur)
    sum += query(u << 1 | 1, mid + 1, r, ul, ur);
  return sum;
}