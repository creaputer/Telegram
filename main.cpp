#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // node
int M; // road
int C; // start node

#define MAX_N 30000
#define MAX_M 200000
#define INF 1e9

vector<pair<int, int>> graph[MAX_N + 1];
int d[MAX_N + 1];

void dijkstra(int start) {
  priority_queue<pair<int, int>> pq;

  fill_n(d, MAX_N + 1, INF);

  pq.push({-0, start});
  d[start] = 0;

  while (!pq.empty()) {
    int dis = -pq.top().first;
    int now = pq.top().second;

    pq.pop();

    if (d[now] < dis) continue;

    for (int i = 0 ; i < graph[now].size() ; ++i) {
      pair<int, int> cur = graph[now].at(i);

      int cost = cur.second + dis;
      if (d[cur.first] > cost) {
        d[cur.first] = cost;
        pq.push({-cost, cur.first});
      }
    }
  }
}

int main(int argc, char** argv) {
  int test_case;
  int T;

  freopen("input.txt", "r", stdin);

  T = 1;

  for (test_case = 1; test_case <= T; ++test_case) {
    cin >> N >> M >> C;

    for (int i = 1 ; i <= M ; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      graph[a].push_back({b, c});
    }

    dijkstra(C);

    int count = 0;
    int max = 0;
    for (int i = 1 ; i <= N; i++) {
      // cout << d[i] << ", ";
      if ((d[i] != INF) && (d[i] != 0)) {
        count++;
        if (d[i] > max) max = d[i];
      }
    }
// cout << endl;

    cout << count << " " << max << endl;
  }

  return 0;
}