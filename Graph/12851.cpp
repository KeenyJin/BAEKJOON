// Got advice from below:
// https://velog.io/@dhelee/%EB%B0%B1%EC%A4%80-12851%EB%B2%88-%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%884-Python-%EB%84%88%EB%B9%84-%EC%9A%B0%EC%84%A0-%ED%83%90%EC%83%89BFS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int sec[200001], visited[200001];
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K; cin>>N>>K;
	for(int i=0;i<=2*K;i++){visited[i] = 0; sec[i] = -1;}
	visited[N] = 1; sec[N] = 0;
	
	queue<int> bfs; bfs.push(N);
	while(!bfs.empty()){
		int x = bfs.front();
		bfs.pop();
		if(K == x) break;
		for(int i=0;i<3;i++){
			int y=-1;
			if(i==0 && x>0) y = x-1;
			else if(i==1 && K>x) y = x+1;
			else if(i==2 && K>x) y = 2*x;
			if(y>-1){
				if(visited[y] == 0){
					bfs.push(y);
					visited[y] = visited[x];
					sec[y] = sec[x]+1;
				}
				else if(sec[y] == sec[x]+1) visited[y] += visited[x];
			}
		}
	}
	cout<<sec[K]<<'\n'<<visited[K];
	
	return 0;
}
