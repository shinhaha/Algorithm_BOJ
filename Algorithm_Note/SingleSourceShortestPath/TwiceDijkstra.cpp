/* boj 1238

N���� ���ڷ� ���е� ������ ������ �� ���� �л��� ��� �ִ�.

��� �� �� N���� �л��� X (1 �� X �� N)�� ������ �𿩼� ��Ƽ�� ���̱�� �ߴ�.

�� ���� ���̿��� �� M���� �ܹ��� ���ε��� �ְ� i��° ���� �����µ� Ti(1 �� Ti �� 100)�� �ð��� �Һ��Ѵ�.

������ �л����� ��Ƽ�� �����ϱ� ���� �ɾ�� �ٽ� �׵��� ������ ���ƿ;� �Ѵ�. 

������ �� �л����� ���� �������� �ִ� �ð��� ���� ���⸦ ���Ѵ�.

�� ���ε��� �ܹ����̱� ������ �Ƹ� �׵��� ���� ���� ���� �ٸ����� �𸥴�. 

N���� �л��� �� ���� ���µ� ���� ���� �ð��� �Һ��ϴ� �л��� �������� ���Ͽ���.

---------------------------------------------------------------------------------------------------------------------------

<<Solution>>

X�� �������� �ٸ� ������ ���� �ִܰŸ��� X�� ������ source�� �Ͽ� ���ͽ�Ʈ�� �˰����� ����Ͽ� �� �� �ִ�.

������, ��� ���� U���� X�� ���� �ִܰŸ��� U1, U2, U3... Un-1�� source�� �� �������� ���ͽ�Ʈ�� �˰����� ������ �ұ�?

�׷��� �ʴ�. Edge�� ������ �ݴ�� �ٲ� �ڿ� X�� ������ source�� �Ͽ� ���ͽ�Ʈ�� �˰����� ����ϸ�

�ٸ� �������� X�� ������ ���� �ִܰŸ��� ���س� �� �ִ�.

������ ���� ���� ������ �ͳ����� ����Ѵٸ�,

������ �� �� U,X�� ���� �ִܰ�� P�� ���� X1�� P�� ���ϰ� X1�� X�� �̿��ϴٰ� �������� ��,

Edge�� ������ �ݴ�� �ϸ� X->X1�� �ִܰ�ΰ� �ȴ�. �̷��� ����� Ȯ���ؼ� �ݺ��Ѵ�.

�� ������ �÷��̵�-���� �˰������ε� �ذ��� �� ������ �÷��̵�-���� �˰����� O(v^3)���� ���ſ� �˰����̴�.

�׷��Ƿ� ���� �� �ִٸ� ���ؾ� �ϰ� ���� ���� ���ͽ�Ʈ�� �˰����� 2�� ����ϴ� ������� O(|E|logV) ���� �ذ��� �� �ִ�.

*/

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define Vertice pair<int,int>//weight,vertice
#define Edge pair<int,int>//dest,weight
#define INF 1e9

int main() {
	int V, E,src; scanf("%d %d %d", &V, &E,&src);
	priority_queue<Vertice, vector<Vertice>, greater<Vertice>> pq;
	vector<Edge>* v = new vector<Edge>[V + 1]();//Edge vector
	vector<Edge>* _v = new vector<Edge>[V + 1]();//Swap Edge vector
	int* dist = new int[V + 1](); fill(dist, dist + V + 1, INF);
	vector<int> party; int ret = -1;

	for (int i = 0; i < E; i++) {
		int from, to, weight; scanf("%d %d %d", &from, &to, &weight);
		v[from].push_back({ to,weight }),_v[to].push_back({ from,weight });
	}

	dist[src] = 0;	pq.push({ dist[src],src });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second; pq.pop();
		if (dist[curr] < weight)continue;
		for (int i = 0; i<v[curr].size(); i++)
			if (dist[v[curr][i].first] > dist[curr] + v[curr][i].second) {
				dist[v[curr][i].first] = dist[curr] + v[curr][i].second;
				pq.push({ dist[v[curr][i].first],v[curr][i].first });
			}
	}

	for (int i = 1; i <= V; i++)
		party.push_back(dist[i]),v[i].clear();

	fill(dist, dist + V + 1, INF);

	dist[src] = 0;	pq.push({ dist[src],src });
	while (!pq.empty()) {
		int weight = pq.top().first;
		int curr = pq.top().second; pq.pop();
		if (dist[curr] < weight)continue;
		for (int i = 0; i<_v[curr].size(); i++)
			if (dist[_v[curr][i].first] > dist[curr] + _v[curr][i].second) {
				dist[_v[curr][i].first] = dist[curr] + _v[curr][i].second;
				pq.push({ dist[_v[curr][i].first],_v[curr][i].first });
			}
	}

	for (int i = 1; i <= V; i++) 
		_v[i].clear(),ret = max(ret, dist[i] + party[i - 1]);

	printf("%d", ret);
	
	return 0;
}