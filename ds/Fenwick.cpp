#define lowbit(x) (x & -x) 
int n; //总数量
//逆序数对由"大排到小", search(loc - 1)就行了回圈就行了

namespace fw{
	int tree[MAXLEN] = {0};
	void insert(int pos, int val){ //单点插入
		for(;pos <= n; pos += lowbit(pos))tree[pos] += val;
	}
	int search(int pos){ //单点前缀和查询
		int ans = 0;
		for(;pos; pos -= lowbit(pos)){
			ans += tree[pos];
		}
		return ans;
	}
	int query(int l, int r){  //区间查询
		return search(r) - search(l - 1);
	}
}