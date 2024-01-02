/*Implement DFS and BFS , Use undirected Graph and develop a recursive algorithm for searching 
all the vertices of a graph or tree data structure.*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V; //for number of vertices
    vector<vector<int>> adj; //adjacency list

    Graph(int vertices) {
        V = vertices;
        adj.resize(vertices + 1); //starts from 1
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void recbfs(vector<int>& visit, queue<int>& q, vector<int>& ans) {
        if (q.empty()) {
            return;
        }
        int ele = q.front();
        q.pop();
        ans.push_back(ele);
        vector<int> a = adj[ele];
        for (int i = 0; i < a.size(); i++) {
            if (!visit[a[i]]) {
                visit[a[i]] = 1;
                q.push(a[i]);
            }
        }
        recbfs(visit, q, ans);
    }

    void BFS(int n) {
        vector<int> visit(n + 1, 0);
        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0) {
                visit[i] = 1;
                q.push(i);
                recbfs(visit, q, ans);
            }
        }
        cout << "\nBFS Traversal is : ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    void BFSSearch(int n, int target) {
        vector<int> visit(n + 1, 0);
        queue<int> q;
        vector<int> ans_s;
        int find = 0;
        for (int i = 1; i <= n; i++) {
            if (visit[i] == 0) {
                visit[i] = 1;
                q.push(i);
                recbfs_search(visit, q, ans_s, find, target);
                if (find == 1) {
                    break;
                }
            }
        }
        if (find == 1) {
            cout << "\nVertex Found \n";
            cout << "\nBFS Traversal for vertex " << target << " is : ";
            for (int i = 0; i < ans_s.size(); i++) {
                cout << ans_s[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "\nVertex Not Found \n";
        }
    }

    void recbfs_search(vector<int>& visit, queue<int>& q, vector<int>& ans_s, int& find, int target) {
        if (q.empty()) {
            return;
        }
        int ele = q.front();
        q.pop();
        ans_s.push_back(ele);
        if (ele == target) {
            find = 1;
            return;
        }
        vector<int> b = adj[ele];
        for (int i = 0; i < b.size(); i++) {
            if (!visit[b[i]]) {
                visit[b[i]] = 1;
                q.push(b[i]);
            }
            if (find == 1) {
                break;
            }
        }
        if (find != 1) {
            recbfs_search(visit, q, ans_s, find, target);
        }
    }

        //DFS begins 
    void DFS(int n){
      vector<int> ans;
      vector<int> visit(n+1,0);
      stack<int> st;
      for(int i=1;i<=n;i++){
        if(visit[i]==0){
          visit[i]=1;
          cout<<"Visiting "<<i<<" Vertex and inserting it into stack\n";
          st.push(i);
          recdfs(visit,st,ans);
        }
      }
    }

   void recdfs(vector<int> &visit, stack<int> st,vector<int> &ans){
            int top=st.top();
            st.pop();
            vector<int> a=adj[top];
            ans.push_back(top);
            for(int i=0;i<a.size();i++){
              int ele=a[i];
              if(visit[a[i]]==0){
                visit[i]=1;
                cout<<"Visisting "<<a[i]<<" vertex and inserting it into stack\n";
                st.push(a[i]);
                recdfs(visit,st,ans);
              }
            }
    }
  void DFSSearch(int n, int target){
    vector<int> b2;
    vector<int> visit(n+1,0);
    stack<int> st;
    int find=0;
    for(int i=1;i<=n;i++){
      if(visit[i]==0){
        visit[i]=1;
        st.push(i);
        recdfs_search(visit,st,b2,find,target);
     if ( find==1){
      break;
     }
      }}
      if(find==1){
        cout<<"\nVertex Found\n";
        cout<<"\nDFS Traversal for vertex is: ";
        for(int i=0;i<b2.size();i++){
          cout<<b2[i]<<" ";
        }
        cout<<"\n";
      }
      else{
        cout<<"\nVertex Not Found \n";
      }
    }

    void recdfs_search(vector<int> &visit,stack<int> &st, vector<int>&ans,int&find,int target){
        int n=st.top();
    st.pop();
     vector<int>a=adj[n];
     ans.push_back(n);
     if(n==target)
     {
         find=1;
         return;
     }

     for(int i=0;i<a.size();i++)
     {
         int ele=a[i];
         if(visit[a[i]]==0)
         {
             visit[a[i]]=1;

             st.push(a[i]);
             recdfs_search(visit,st,ans,find,target);
             if(find==1)
             {
                 break;
             }
         }
     }
    }
  };

  int main() {
    int n, edge, u, v;
    cout << "Enter Number of Vertices : ";
    cin >> n; //no. of vertices
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

    int choice;
    while (true) {
        cout << "\n\nEnter the node you want to search : ";
        int node;
        cin >> node;
        cout << "\n1. BFS";
        cout << "\n2. DFS ";
        cout << "\n3. Exit ";
        cout << "\nChoice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                graph.BFSSearch(n, node);
                break;
            case 2:
                graph.DFSSearch(n, node);
                break;
            case 3:
                exit(1);
            default:
                cout << "invalid choice\n";
        }
    }
    return 0;
}