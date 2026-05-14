#include <iostream>
#include <queue>
#include <list>

using namespace std;

class graph{
	public:
	int v;
	list<int >adj [10];
	
	graph(int val){
		v=val;
		
	}
	void edge(int u,int v){
		adj[u].push_back(v);
	}
	
	void bfsrec(queue<int> &q,bool visited[]){
		if(q.empty()){
			return ;
		}
		int node= q.front();
		q.pop();
		
		cout<<node<<" ";
		
		for(int i : adj[node]){
			if(!visited[i]){
				visited[i]=true;
				q.push(i);			
		}
	}
	bfsrec(q,visited);
	
}
	void BFS(int start){
		bool visited[10]={false};
		queue<int> q;
		visited [start]=true;
		q.push(start);
		bfsrec(q, visited);
		
	}
};
int main(){
	graph g(10);
	g.edge(0,1);
	g.edge(0,3);
	g.edge(1,5);
	g.edge(5,7);
	cout<<"BFS";
	g.BFS(0);
	return 0;
}
	

