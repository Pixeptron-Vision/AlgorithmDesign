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
vector<int> depthFirstSearch(vector<vector<int>>nodeList, int start)
{
    // Declare the Queue, vector for storing path and array to store flags
    vector<int>Q;
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
        auto lastIn = Q.end();
        lastIn--;
        int v = *lastIn;
        Q.pop_back();
        for(auto it=nodeList[v].begin();it!=nodeList[v].end();it++)
        {
            if(visitedNodeFlags[*it]==0)
            {
                Q.push_back(*it);
                visitedNodeFlags[*it]=1;
            }

        }
        path.push_back(v);


    }
    return path;
}

vector<int> depthFirstSearchRecursive(vector<vector<int>>nodeList,int start,int* visitedNodeList)
{
    vector<int>result;
    result.push_back(start);
    visitedNodeList[start]=1;
    for(auto it=nodeList[start].begin();it!=nodeList[start].end();it++)
    {
        if(visitedNodeList[*it]==0)
        {
            vector<int> partResult = depthFirstSearchRecursive(nodeList,*it,visitedNodeList);
            for(auto it1=partResult.begin();it1!=partResult.end();it1++)result.push_back(*it1);
        }

    }
    return result;
}
int main()
{
    int e,v1,v2,n;
    cout<<"Enter the number of Nodes:\n";
    cin>>n;
    cout<<"Enter the number of Edges:\n";
    cin>>e;
    cout<<"Enter the Edge list. Example: 1 0 <-` 1 2 <-` 0 2 <-`\n";
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
    vector<int>path=depthFirstSearch(graph,s);
    cout<<"Depth First Traversal Sequence of given Graph:-\n";
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<"\n";
    int visitedNodeList[n];
    for(int i=0;i<n;++i)visitedNodeList[i]=0;
    path = depthFirstSearchRecursive(graph,s,visitedNodeList);
    cout<<"Depth First Traversal Sequence (Recursive - Left to right) of given Graph:-\n";
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    return 0;
}

