/****************************************** Topological Sort Using DFS *******************************************************

 -> Topological sorting for a graph is only possible if graph is directed and acyclic.
 -> It is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. 
 -> Topological Sorting for a graph is not possible if the graph is not a DAG(Directed Acyclic Graph).


Algorithm Used:

We can use DFS to find Topological Sorting of a graph:
    In DFS, we start from a vertex, first print it and then recursively call DFS for its adjacent vertices. 
    In topological sorting, we use a stack. First recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
    Finally, print contents of the stack. Also, a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack. 

******************************************************************************************************************************/


//Implementations of the function performing Topological Sort using DFS:

#include <bits/stdc++.h>

using namespace std;

class Solution {
  void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) {
    vis[node] = 1;

    //Calling the adjacent of the node
    for (auto it: adj[node]) {
      if (!vis[it]) {

        //Recursive call
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);
  }
  public:
    vector < int > topoSort(int N, vector < int > adj[]) {
      stack < int > st;               //Stack to push and pop the nodes after execution, as it works in LIFO
      vector < int > vis(N, 0);       //visited array, to track if particular node is visited or not
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;
    }
};

/************
For Example:
If we have to find the topo sort of the graph whose edges are:
    (5, 2)     --->  5 directed to 2
    (5, 0)     --->  5 directed to 0
    (4, 0)     --->  4 directed to 0
    (4, 1)     --->  4 directed to 1
    (2, 3)     --->  2 directed to 3
    (3, 1)     --->  3 directed to 1

Then its one of the topological sort is: 5 4 2 3 1 0 
***********/