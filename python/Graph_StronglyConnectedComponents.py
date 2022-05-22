class Graph:
    # Initialise the graph as an adjacency list
    def __init__(self, n):
        self.n = n
        self.graph = {i:[] for i in range(self.n)}

    # Adding a directed edge
    def addEdge(self, s, d):
        self.graph[s].append(d)

    # Performing DFS on the Graph
    def dfs(self, source, visited):
        
        visited[source] = True
        print(source, end=' ')
        
        for i in self.graph[source]:
            if not visited[i]:
                self.dfs(i, visited)

    # Gives the order in which the vertex were accessed
    def fillOrder(self, source, visited, stack):
        
        visited[source] = True
        for i in self.graph[source]:
            if not visited[i]:
                self.fillOrder(i, visited, stack)
        stack = stack.append(source)

    # Transpose of the graph
    def transpose(self):
        g = Graph(self.n)

        for i in self.graph:
            for j in self.graph[i]:
                g.addEdge(j, i)
        return g

    # Print stongly connected components of the graph
    def printSCC(self):

        # Using an array to implement a stack to track the order of vertices
        stack = []
        visited = [False for _ in range(self.n)]

        for i in range(self.n):
            if not visited[i]:
                self.fillOrder(i, visited, stack)

        gr = self.transpose()
        visited = [False for _ in range(self.n)]

        while stack:
            i = stack.pop()
            if not visited[i]:
                gr.dfs(i, visited)
                print("")

# Input the number of vertices and the number of the edges in the Graph
n, m = map(int, input().split())

# Make the graph from the edges
g = Graph(n)
for _ in range(m):
    a, b = map(int, input().split())
    g.addEdge(a,b)

# Print Strongly Connected Components
print("Strongly Connected Components:")
g.printSCC()

"""
Sample Test Case : 
8 9
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4
6 7
"""