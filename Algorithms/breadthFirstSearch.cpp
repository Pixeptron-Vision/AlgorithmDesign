#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;
vector<vector<int>> createGraph(vector<pair<int,int>> edges,int nodes)
{
    vector<vector<int>> nodeList(nodes);
    for(auto it=edges.begin();it!=edges.end();++it)
    {
        pair<int,int> edgepair = *it;
        nodeList[edgepair.first].push_back(edgepair.second);
        nodeList[edgepair.second].push_back(edgepair.first);
    }
    return nodeList;
}
void displayNodeList(vector<vector<int>>nodeList)
{
    int i=0;
    for(auto it=nodeList.begin();it!=nodeList.end();++it)
    {
        auto vec = *it;
        for(auto it2=vec.begin();it2!=vec.end();it2++)
        {
            cout<<"("<<i<<","<<*it2<<")\n";
        }
        i++;
    }

}
vector<int> breadFirstSearch(vector<vector<int>>nodeList, int start)
{
    // Declare the Queue, vector for storing path and array to store flags
    deque<int>Q;
    vector<int>path;
    int visitedNodeFlags[nodeList.size()];
    for(int i=0;i<nodeList.size();++i) visitedNodeFlags[i]=0;
    // Initialize Queue and flag array
    visitedNodeFlags[start]=1;
    Q.push_back(start);
    while(Q.size()>0)
    {
        //for(auto iq=Q.begin();iq!=Q.end();iq++)cout<<*iq<<" ";
        //cout<<"\n";
        int v = Q[0];
        for(auto it=nodeList[v].begin();it!=nodeList[v].end();it++)
        {
            if(visitedNodeFlags[*it]==0)
            {
                Q.push_back(*it);
                visitedNodeFlags[*it]=1;
            }

        }
        Q.pop_front();
        path.push_back(v);


    }
    return path;
}
deque<int> shortestPathBFS(vector<vector<int>>nodeList,int start,int finish)
{
    // Declare the Queue, vector for storing path and array to store flags
    deque<int>Q;
    vector<int>path;
    int visitedNodeFlags[nodeList.size()];
    for(int i=0;i<nodeList.size();++i) visitedNodeFlags[i]=0;
    int previousNode[nodeList.size()];
    previousNode[start]=0;
    // Initialize Queue and flag array
    visitedNodeFlags[start]=1;
    Q.push_back(start);
    while(Q.size()>0)
    {
        //for(auto iq=Q.begin();iq!=Q.end();iq++)cout<<*iq<<" ";
        //cout<<"\n";
        int v = Q[0];
        if(v==finish)
        {
            path.push_back(v);
            break;
        }
        for(auto it=nodeList[v].begin();it!=nodeList[v].end();it++)
        {
            if(visitedNodeFlags[*it]==0)
            {
                Q.push_back(*it);
                visitedNodeFlags[*it]=1;
                previousNode[*it]=v;
            }

        }
        Q.pop_front();
        path.push_back(v);


    }

    int index =finish;
    deque<int>shortestPath;
    shortestPath.push_back(finish);
    int shortestPathLength = 0;
    while(index!=start)
    {
        shortestPathLength++;
        index = previousNode[index];
        shortestPath.push_front(index);
    }
    cout<<"Shortest Path Length:- "<<shortestPathLength<<endl;
    return shortestPath;
}
int main()
{
    int e,v1,v2,n;
    cout<<"Enter the number of Nodes:\n";
    cin>>n;
    cout<<"Enter the number of Edges:\n";
    cin>>e;
    vector<pair<int,int>>edges;
    for(int i=0;i<e;++i)
    {
        cin>>v1>>v2;
        pair<int,int> edge = make_pair(v1,v2);
        edges.push_back(edge);
    }
    vector<vector<int>> graph = createGraph(edges,n);
    displayNodeList(graph);

    cout<<"Enter the starting Node\n"<<endl;
    int s;
    cin>>s;
    vector<int>path=breadFirstSearch(graph,s);
    cout<<"Breadth First Traversal Sequence of given Graph:-\n";
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<"\nShortest Path Search:- Enter the starting Node and Finish Node\n"<<endl;
    int f;
    cin>>s>>f;
    deque<int>spath=shortestPathBFS(graph,s,f);
    cout<<"Shortest path sequence from:-"<<s<<" to "<<f<<"\n";
    for(int i=0;i<spath.size();i++)
    {
        cout<<spath[i]<<" ";
    }
    return 0;
}
