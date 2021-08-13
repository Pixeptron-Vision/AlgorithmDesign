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

    }
    return graph;
}
vector<pair<int,int>>changeDirection(vector<pair<int,int>>edges)
{
    vector<pair<int,int>>edges2;
    for(auto it=edges.begin();it!=edges.end();++it)
    {
        pair<int,int>p = *it;
        // Reverse the direction of the edge
        pair<int,int>p1 = make_pair(p.second,p.first);
        edges2.push_back(p1);
    }
    return edges2;
}
vector<vector<int>>edgeMapping(vector<pair<int,int>>edges,vector<int>m)
{
    vector<vector<int>>graph(m.size());
    for(auto it=edges.begin();it!=edges.end();it++)
    {
        pair<int,int> p = *it;
        int newNodeID1,newNodeID2;
        newNodeID1 = m[p.first];
        newNodeID2 = m[p.second];
        //Assign new nodeIDs and reverse the existing edge direction into an adjacency list
        graph[newNodeID2].push_back(newNodeID1);
    }
    return graph;
}

void DFS(vector<vector<int>>graph,int node, vector<bool>&visitedNodes,vector<int>&correspondences, int &sequence,bool selection)
{
    visitedNodes[node]=true;
    for(auto it=graph[node].begin();it!=graph[node].end();++it)
    {
        int vertex = *it;
        if(!visitedNodes[vertex])
        {
            visitedNodes[vertex]=true;
            DFS(graph,vertex,visitedNodes,correspondences,sequence,selection);
        }
    }
    if(selection)
    {
        sequence++;
    }
    correspondences[node]=sequence;
    //cout<<"DFS CC: "<<node<<"--"<<sequence<<endl;
}
vector<pair<int,int>>connectedComponents(vector<pair<int,int>>edges,int nodes)
{
    /* Assumptions: Node ID's start from 1 */
    // Change the direction of the Graph edges
    vector<pair<int,int>>edges2 = changeDirection(edges);
    vector<vector<int>>graph = createGraph(edges2,nodes);
    // Compute the first step of Kosaraju Two Pass Algorithm
    vector<bool>visitedNodes(nodes+1,false);
    vector<int>correspondences(nodes+1,0);
    int sequence = 0;
    int ccLabel = 1;
    for(int i=nodes;i>0;i--)
    {
        if(!visitedNodes[i])
        {
            //DFS
            DFS(graph,i,visitedNodes,correspondences,sequence,true);
        }
    }

    // Compute the new graph with opposite directions and updated node IDs
    vector<vector<int>>graph2 = edgeMapping(edges2,correspondences);
    // Compute the second pass on the new graph to determine the Strong connected components
    visitedNodes.assign(nodes+1,false);
    vector<int>ccCorrespondences(nodes+1,0);
    for(int i=nodes;i>0;i--)
    {
        ccLabel = i;
        if(!visitedNodes[i])
        {
            //DFS
            DFS(graph2,i,visitedNodes,ccCorrespondences,ccLabel,false);

        }
    }

    /* Update the correspondences according to the original node ID's
       Step-1 : Determine the transverse correspondences
       Step-2 :
    */
    // Step-1 : Determine transverse correspondences
    vector<int> Tcorrespondences(nodes+1,0);
    for(int i=1;i<=nodes;i++)
    {
        Tcorrespondences[correspondences[i]]=i;
    }
    /*
    for(int i=1;i<=nodes;i++)
    {
        cout<<"TC: "<<i<<" -- "<<Tcorrespondences[i]<<endl;
    }
        for(int i=1;i<=nodes;i++)
    {
        cout<<"CC: "<<i<<" -- "<<ccCorrespondences[i]<<endl;
    }
    */
    // step - 2: Map the connected component result in order to reflect true graph node IDs
    vector<pair<int,int>> result;
    for(int i=1;i<=nodes;i++)
    {
        int val1,val2,val1Correspondence, val2Correspondence;
        val1 = i;
        val2 = ccCorrespondences[i];
        val1Correspondence=Tcorrespondences[val1];
        val2Correspondence=Tcorrespondences[val2];
        pair<int,int> p = make_pair(val1Correspondence,val2Correspondence);
        result.push_back(p);
    }
    return result;
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

    vector<pair<int,int>> cc = connectedComponents(edges,n);
    cout<<"Connected component correspondences:-\n ( Node ID --> Master Node)";

    for(auto it=cc.begin();it!=cc.end();++it)
    {
        pair<int,int>p = *it;
        cout<<" (    "<<p.first<<" --> "<<p.second<<" )\n";
    }

    return 0;
}
