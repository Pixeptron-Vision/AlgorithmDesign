#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void DFS(vector<vector<int>>&graph,int current_node,vector<bool>&visited_nodes,int &node_label,vector<pair<int,int>>&topology );
vector<vector<int>> createGraph(vector<pair<int,int>>edges,int nodes)
{
    vector<vector<int>> nodeList(nodes);
    for(auto it=edges.begin();it!=edges.end();it++)
    {
        auto p = *it;
        nodeList[p.first].push_back(p.second);
        //nodeList[p.second].push_back(p.first); commented as edges are directed
    }
    return nodeList;

}

void displayGraph(vector<vector<int>>nodeList)
{
    int n=0;
    for(auto it=nodeList.begin(); it!=nodeList.end();it++)
    {
        auto jab = *it;
        for(auto it2 = jab.begin();it2!=jab.end();it2++)
        {
            cout<<"("<<n<<" --> "<<*it2<<" )"<<endl;
        }
        n++;
    }
}
void displayTopology(vector<pair<int,int>>topology)
{
    cout<<"Topology sequence:-\n"<<"( Node --> Sequence_Rank )\n";
    for(auto it=topology.begin();it!=topology.end();it++)
    {
        auto p = *it;
        cout<<"( "<<p.first<<"--> "<<p.second<<" )\n";
    }
}
vector<pair<int,int>> topologicalSort(vector<vector<int>>graph)
{
    vector<pair<int,int>> topology;
    int node_label = graph.size();
    vector<bool> visited_nodes(node_label,false);
    for(int i=0;i<graph.size();i++)
    {
        if(!visited_nodes[i])
        {
            DFS(graph,i,visited_nodes,node_label,topology);
        }
    }
    return topology;
}
void DFS(vector<vector<int>>&graph,int current_node,vector<bool>&visited_nodes,int &node_label,vector<pair<int,int>>&topology )
{
    visited_nodes[current_node]=true;
    for(auto it = graph[current_node].begin();it!=graph[current_node].end();++it)
    {
        if(!visited_nodes[*it])
        {
            //cout<<current_node<<"--"<<*it<<endl;
            DFS(graph,*it,visited_nodes,node_label,topology);

        }
    }
    pair<int,int> p = make_pair(current_node,node_label);
    topology.push_back(p);
    node_label--;
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
    vector<pair<int,int>>topology = topologicalSort(nodeList);
    displayTopology(topology);
    //displayGraph(nodeList);
    return 0;
}
