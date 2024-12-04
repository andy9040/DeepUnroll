#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE (100000)

int* node[MAX_NODE];
int* route[MAX_NODE];
int* r_size[MAX_NODE];
int n_size[MAX_NODE] = {0};
int parent[MAX_NODE] = {0};
int so_list[MAX_NODE];
int si_list[MAX_NODE];
int so;
int si;

int solve(int source, int sink, int root) {
	int node, so_visit, si_visit;
	int i, j;
	if(source == sink) return source;
	so = si = 0;
	so_visit = si_visit = 0;
	
	// sourceからrootへ行く際に通るnodeを登録
	node = source;
	while(node != root) {
		so_list[so++] = node;
		node = parent[node];
	}
	route[source] = (int*)malloc(so*sizeof(int));
	memcpy(route[source], so_list, sizeof(so*sizeof(int)));
	r_size[node] = so;
	
	// sinkからrootへ行く際に通るnodeを登録
	node = sink;
	while(node != root) {
		si_list[si++] = node;
		node = parent[node];
	}
	route[node] = (int*)malloc(si*sizeof(int));
	memcpy(route[node], si_list, sizeof(si*sizeof(int)));
	r_size[node] = si;

	// ルートから順番に追ってみて、同じ親じゃなくなったら
	// ひとつ前のノードを結果とする
	node = root;
	for(i=si-1, j=so-1; i>= 0 && j>=0; i--, j--) {
		if(so_list[j] != si_list[i]) {
			return node;
		}

		node = so_list[j];
	}
	
	return node;
	
}

int main(void) {
	int i, j, x, m, n, t, q;
	int source, sink;
	int is_root[MAX_NODE] = {0};
	int root;
	
	scanf("%d\n", &n);
	for(i=0;i<n;i++) {
		scanf("%d", &m);

		for(j=0;j<m;j++) {
			scanf("%d", &t);
			is_root[t] = -1;
			parent[t] = i;
		}
	}
	
	// ルート
	root = 0;
	for(i=0;i<n;i++) {
		route[i] = NULL;
		r_size[i] = 0;
		if(is_root[i] == 0) {
			root = i;
			break;
		}
	}
	
	scanf("%d\n", &q);
	for(i=0;i<q;i++) {
		scanf("%d %d\n" ,&source, &sink);
		printf("%d\n", solve(source, sink, root));
	}

	return 0;
}