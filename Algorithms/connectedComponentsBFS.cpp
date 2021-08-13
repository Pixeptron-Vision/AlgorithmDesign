#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;
vector<vector<int>> createGraph(vector<pair<int,int>>edges,int nodes)
{
    vector<vector<int>> graph(nodes+1);
    for(auto it=edges.begin();it!=edges.end();it++)
    {
        pair<int,int> p = *it;
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }
    return graph;
}
void BFS(vector<vector<int>>& graph,int node,vector<bool>& visitedNodes,vector<pair<int,int>>& cc,int &ccLabel)
{
    deque<int> Q;
    Q.push_front(node);
    visitedNodes[node]=true;
    while(Q.size()>0)
    {
        int vertex = Q[0];
        for(auto it=graph[vertex].begin();it!=graph[vertex].end();it++)
        {
            if(!visitedNodes[*it])
            {
                Q.push_back(*it);
                visitedNodes[*it]=true;
                pair<int,int> p = make_pair(*it,ccLabel);
                cc.push_back(p);
            }
        }
        Q.pop_front();
    }

}
vector<pair<int,int>>connectedComponents(vector<vector<int>>graph)
{
    vector<pair<int,int>> cc;
    int nodes = graph.size()-1;
    int ccLabel = 1;
    vector<bool> visitedNodes(nodes+1,false);
    for(int i=1;i<=nodes;i++)
    {
        if(!visitedNodes[i])
        {
            //BFS
            BFS(graph,i,visitedNodes,cc,ccLabel);
            ccLabel++;
        }
    }

    return cc;

}
void displayCC(vector<pair<int,int>>cc)
{
    cout<<"Connected Components Assignment for nodes :-\n"<<"( Node --> component Label )\n";
    for(auto it=cc.begin();it!=cc.end();it++)
    {
        auto p = *it;
        cout<<"( "<<p.first<<" --> "<<p.second<<" )\n";
    }
}
int main()
{

    int n,e;
    vector<pair<int,int>>edges;
    cout<<"Enter the number of nodes in the graph\n";
    cin>>n;
    cout<<"Enter the number of edges\n";
    cin>>e;
    cout<<"Enter the edge list\n";
    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        pair<int,int> p = make_pair(a,b);
        edges.push_back(p);
    }
    vector<vector<int>>nodeList = createGraph(edges,n);
    vector<pair<int,int>>cc = connectedComponents(nodeList);
    displayCC(cc);
    return 0;
}


