#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>>createGraph(vector<pair<int,int>>edges,int nodes)
{
    /* Assumptions: Node ID's start from 1 */
    vector<vector<int>> graph(nodes+1);
    for(auto it = edges.begin();it!=edges.end();it++)
    {
        pair<int,int> p =*it;
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);

    }
    return graph;
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
    int start,stop;
    cout<<"Enter the starting Node\n";
    cin>>start;
    cout<<"Enter the stopping Node\n";
    cin>>stop;
    vector<int> path= dijkstraShortestPath(edges,n,start,stop);
    cout<<"Shortest Distance:- \n"<<distance<<endl;
    cout<<"Shortest Path:- ";
    for(auto it=path.begin();it!=path.end();++it)
    {
        cout<<*it<<" --> ";
    }

    return 0;
}
