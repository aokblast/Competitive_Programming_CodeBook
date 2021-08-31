struct edge
{
    int to;
    int val;
    int rev;
    int cost;
    edge(int _to, int _val, int _rev, int _cost):to(_to), val(_val), rev(_rev), cost(_cost){}
};

int n, m, s, t; 

vector<edge> adjs[MAXLEN];

int dis[MAXLEN];
bool visit[MAXLEN];



long long zuidaliu = 0, zuixiaofeiyong = 0;

bool spfa(int id = t){
	memset(visit, 0, sizeof(visit));
	memset(dis, 0x3f, sizeof(dis));
	visit[id]  = true;
	dis[id] = 0;
	deque<int> q;
	q.push_front(id);
	
	while(!q.empty()){
		int front = q.front(); q.pop_front();
		
		for(edge &adj : adjs[front]){
			if(adjs[adj.to][adj.rev].val > 0 && dis[adj.to]  > dis[front] - adj.cost ){
				dis[adj.to] = dis[front] - adj.cost;
				if(!visit[adj.to]){
					visit[adj.to] = true;
					if(!q.empty() && dis[adj.to] < dis[q.front()]) q.push_front(adj.to);
					else q.push_back(adj.to);
				}
			}
		}
		visit[front] = false; 
	}
	return dis[s] != 0x3f3f3f3f;
}

int dfs(int u = s, int flow =  0x3f3f3f3f){
	if(u == t){
		visit[u] = true;
		return flow;
	}
	int in = flow;
	int out = 0;
	visit[u] = true;
	for(edge &adj : adjs[u]){

		if(adj.val >0 && !visit[adj.to] && dis[adj.to] == (dis[u] - adj.cost)){
			int dis = dfs(adj.to, min(in, adj.val));
			if(dis > 0){
				in -= dis;
				adj.val -= dis;
				out += dis;
				zuixiaofeiyong += dis * adj.cost;
				adjs[adj.to][adj.rev].val += dis;
			}
			if(!in) break;

		}
	}
	
	return out;
}



void dinic(){
	while(spfa()){
		while(int d = dfs()){
			memset(visit, 0, sizeof(visit));
			zuidaliu += d;
		}
	}
}
