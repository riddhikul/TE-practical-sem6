#include<bits/stdc++.h>
using namespace std;
class Graph{ 
    public:
    int V; //for number of vertices
    vector<vector<int>> adj; //adjacency list
    
    Graph(int vertices){ 
        V=vertices;
        adj.resize(vertices+1); //starts from 1
    }

    void addEdge(int u,int v){
       adj[u].push_back(v);
       adj[v].push_back(u);   
    }

    void recbfs(vector<int>&visit , queue<int> &q,vector<int>&ans){
     if(q.empty()){
        return;
     }   
     int ele=q.front();
     q.pop();
     ans.push_back(ele);
     vector<int> a = adj[ele];
     for(int i=0;i<a.size();i++){
        if(!visit[a[i]]){
             visit[a[i]]=1;
             cout<<"Visiting "<<a[i]<<"Vertex and inserting it into queue\n";
             q.push(a[i]);
        } 
     }
     recbfs(visit,q,ans);
    }

    void BFS(int n){
      vector<int> visit(n+1,0);
      queue<int> q;
      vector<int> ans;
      for(int i=1;i<=n;i++){
        if(visit[i]==0){
            visit[i]=1;
            cout<<"Visiting "<<i<<" Vertex and inserting it into queue\n";
            q.push(i);
            recbfs(visit,q,ans);
        }
      } 
      cout<<"\nBFS Traversal is : ";
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
      }   
      cout<<"\n";
    }

    void BFSSearch(int n , int target){
        vector<int> visit(n+1,0);
        queue<int> q;
        vector<int> ans_s;
        int find=0;
        for(int i=1;i<=n;i++){
            if(visit[i]==0){
                visit[i]=1;
                q.push(i);
                recbfs_search(visit,q,ans_s,find,target);
            }
             if(find==1)
        {
            break;
        }
        }
          if(find==1)
    {
        cout<<"\nVertex Found \n";
        cout<<"\nBFS Traversal for vertex "<< target <<" is : ";
        for(int i=0;i<ans_s.size();i++)
        {
            cout<<ans_s[i]<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"\nVertex Not Found \n";
    }
       

    }

    void recbfs_search(vector<int> &visit ,queue<int> &q ,vector<int>&ans_s,int find,int target ){
      if(q.empty()){
        return;
      }
      int ele=q.front();
      q.pop();
      ans_s.push_back(ele); 
      if(ele==target){
        find=1;
        return;
      } 
      vector<int> b = adj[ele];
      for(int i=0;i<b.size();i++){
        if(!visit[b[i]]){
            visit[b[i]]=1;

            q.push(b[i]);
        }
        if(find==1){
            break;
        }
      }
      if(find!=1){
        recbfs_search(visit,q,ans_s,find,target);
      }
    } 
};

int main() {
    int n, edge, u, v;
    cout << "Enter Number of Vertices : ";
    cin >> n;
    Graph graph(n);

    cout << "Enter Number of Edges : ";
    cin >> edge;
    for (int i = 0; i < edge; i++) {
        cout << "Enter source index : ";
        cin >> u;
        cout << "Enter destination vertex : ";
        cin >> v;
        graph.addEdge(u, v);
    }

    cout << "\nGraph\n";
    for (int i = 1; i < n + 1; i++) {
        cout << i << " -> ";
        vector<int> a = graph.adj[i];
        for (int j = 0; j < graph.adj[i].size(); j++) {
            cout << a[j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\nBFS Traversal \n\n";
    graph.BFS(n);

    // Other function calls go here

    return 0;
}