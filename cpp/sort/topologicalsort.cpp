#include <iostream>
#include <list>
#include <vector>
#include <stack>

class Graph{
private:
    // adjacency list
    std::vector<std::list<int>> adj;
    uint32_t _size;
public:
    Graph() : _size(0) { this->adj.resize(0); }
    Graph(uint32_t s) : _size(s) { this->adj.resize(s); }

    void addEdge(int u, int v){// adds directed edge to digraph 
        this->adj[u].push_back(v);     
    }

    void printAdj(){// debug (prints the adjacency list)
        std::cout << "Adjacency List: \n";
        uint32_t c{};
        for(const auto& l : this->adj){
            std::cout << c++ << ": ";
            auto it = l.begin();
            for(; it != l.end(); ++it)
                std::cout << *it << " ";
            std::cout << "\n";
        }
    }

    void dfs(int v, std::vector<bool>& visited, 
                        std::list<int>& L){
        // visit v
        visited[v] = 1;

        // dfs all neighbours of v
        auto& l = this->adj[v];
        auto it = l.begin();
        for(; it != l.end(); ++it){
            int u = *it;
            if(!visited[u]){
                dfs(u, visited, L);
            }
        }
        L.push_front(v);
    }

    void topologicalsort(){
        std::vector<bool> visited(this->_size);
        std::list<int> L;

        for(int x{}; x < this->_size; ++x){
            if(!visited[x]){
                dfs(x, visited, L);//dfs starting at x
            }
        }
        // print the topologically sorted list
        auto it = L.begin();
        for(; it != L.end(); ++it){
            std::cout << *it << " ";
        }std::cout << "\n";
    }

};

int main(){
    Graph dg(8);// directed graph
    dg.addEdge(0, 1);
    dg.addEdge(1, 6);
    dg.addEdge(0, 4);
    dg.addEdge(2, 4);
    dg.addEdge(4, 7);
    dg.addEdge(5, 7);
    dg.addEdge(3, 5);
    dg.addEdge(5, 6);

    dg.topologicalsort();
    return 0;
}