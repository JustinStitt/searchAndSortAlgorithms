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

    void addEdge(int u, int v){
        this->adj[u].push_back(v);// add directed edge        
    }

    void printAdj(){
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

    bool dfs(int find){
        std::vector<bool> visited(this->_size);
        return this->dfs(0, find , visited);
    }

    bool dfs(int v, const int& f, std::vector<bool>& visited){
        visited[v] = true;
        if(v == f) return true;
        // find unvisited neighbours
        const auto& l = this->adj[v];
        auto it = l.begin();
        for(; it != l.end(); ++it){
            if(!visited[*it]){
                return dfs(*it, f,  visited);
            }
        }
        return false;
    }

};

int main(){
    Graph dg(6);// directed graph
    dg.addEdge(0, 1);
    dg.addEdge(1, 2);
    dg.addEdge(0, 3);
    dg.addEdge(3, 4);
    dg.addEdge(2, 5);

    std::cout << (dg.dfs(2) == 1 ? " true" : " false") << "\n";
    return 0;
}