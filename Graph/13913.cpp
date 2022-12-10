// Somehow new and delete causes 'invalid pointer' error.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[200001];
int cnt[200001], before[200001];
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K; cin>>N>>K;
//	bool* visited = new bool[2*K+1];
//	int* cnt = new int[2*K+1];
//	int* before = new int[2*K+1];
	for(int i=0;i<=2*K;i++) visited[i] = false;
	visited[N] = true; cnt[N] = 0;
	
	queue<int> bfs; bfs.push(N);
	while(!bfs.empty()){
		int x = bfs.front();
		bfs.pop();
		if(K == x) break;
		for(int i=0;i<3;i++){
			int y=-1;
			if(i==0 && x>0 && !visited[x-1]) y = x-1;
			else if(i==1 && K>x && !visited[x+1]) y = x+1;
			else if(i==2 && K>x && !visited[2*x]) y = 2*x;
			if(y>-1){
				visited[y] = true; bfs.push(y);
				before[y] = x; cnt[y] = cnt[x]+1;
			}
		}
	}
	cout<<cnt[K]<<'\n';
	vector<int> arr(1, K);
	for(int i=0;i<cnt[K];i++) arr.push_back(before[arr[arr.size()-1]]);
	for(int i=arr.size()-1;i>=0;i--) cout<<arr[i]<<" ";
	
//	delete[] visited, cnt, before;
	return 0;
}
