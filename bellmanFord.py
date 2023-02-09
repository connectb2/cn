from sys import maxsize

class Graph:
    def __init__(self, v):
        self.V = v 
        self.graph = []
    
    def addEdge(self, u, v, wt):
        self.graph.append([u, v, wt])
    
    def bellmanFord(self, src):
        dist = [maxsize] * self.V # Array of size V in which all elements are initialized to maxsize
        dist[src] = 0

        #Relaxing all edges V-1 times
        for _ in range(self.V-1):
            for u, v, wt in self.graph:
                if(dist[u] != maxsize and dist[u] + wt < dist[v]):
                    dist[v] = dist[u] + wt

         #Relaxing one more time to detect if negative weghted cycle exists
        for u, v, wt in self.graph:
            if(dist[u] != maxsize and dist[u] + wt < dist[v]):
                print("The graph contains negative weighted cycle")
                return

        print("\n___Dist of all nodes from source___")
        for i in range(self.V):
            print(f"Dist of {i} from src : {dist[i]}")

if(__name__ == "__main__"):
    v = int(input("Enter no of vertices : "))
    e = int(input("Ennter no of edges : "))

    graph = Graph(v)
    print("Enter src dest and weight of edges")
    for _ in range(e):
        u, v, wt = map(int, input().split())
        graph.addEdge(u, v, wt)

    source = int(input("Enter source node : "))
    graph.bellmanFord(source)

