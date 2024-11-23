//#include <iostream>
//#include<limits.h>
//using namespace std;
//static unsigned cont;
//void Merge( unsigned Arr[], unsigned p, unsigned q, unsigned r)
//{
// unsigned n1, n2, i, j, k;
// n1 = q - p + 1;
// n2 = r - q;
// unsigned *L = new unsigned[n1 + 1];
// unsigned *R = new unsigned[n2 + 1];
// for(i =0; i < n1; ++i)
// {
// L[i] = Arr[p + i];
// }
// for(j =0; j < n2; ++j)
// {
// R[j] = Arr[q + j +1];
// }
// L[n1] = INT_MAX;
// R[n2] = INT_MAX;
// i=0;
// j=0;
// for(k=p; k <= r; ++k)
// {
// if(L[i] <= R[j])
// {
// Arr[k] = L[i];
// i++;
// cont += j;
// }
// else
// {
// Arr[k] = R[j];
// j++;
// }
// }
//}
//void MergeSort( unsigned Arr[], unsigned p, unsigned r)
//{
// unsigned q;
// if(p < r)
// {
// q = (p + r)/2;
// MergeSort(Arr, p, q);
// MergeSort(Arr, q +1, r);
// Merge(Arr, p, q, r);
// }
//}
//int main()
//{
// unsigned Arr[1023], n, i;
//while(cin >> n )
//{
// cont = 0;
// for(i=0; i<n; ++i)
// {
// cin >> Arr[i];
// }
// MergeSort(Arr,0, n-1);
// cout << "Minimum exchange operations : " << cont << "\n";
//}
// return 0;
//}
//cout << " " << source;
//int j,i=0, next;

//void DFS(int source)
//{
// traversed[source] =1;
// for(j =0; j< Graph[source].size(); j++)
// {
//    next = Graph[source][j];
//    if(traversed[next] == 0)
//    {
//        DFS(next);
//    }
// }
//}


// Graph DFS with Adjacent List for Directed Graph
#include<bits/stdc++.h>
using namespace std;

vector <int> Graph[100];
bool traversed[100];

void DFS(int source)
{
int j,i=0, next;

traversed[source] =1;


cout << " " << source;
for(j =0; j< Graph[source].size(); j++)
{

next = Graph[source][j];
if(traversed[next] == 0)
{
DFS(next);
}

}

}

void displayGraph(vector <int> Graph[], int siz)
{
int i, j;
cout << " The Adjacent List Representation of the graph is:" << endl;
for(i=0; i< siz; i++){
cout << i << " -> ";
for(j=0;j<Graph[i].size(); j++)
{
cout << Graph[i][j] << ' ';
}
cout << endl;
}

}

int main()
{
int vertex, edge, i, u, v,j, DFSCall=0;
cout<< "Input number of vertex and edges for the Directed Graph:" << endl;
cin>> vertex >> edge ;
cout<< "Input the edges of the Directed graph as (U, V) pair:" << endl;
for(i=0; i < edge; i++)
{

cin >> u >> v;

Graph[u].push_back(v);


}

displayGraph(Graph, vertex);

cout << "\n" << "After performing DFS the Vertex traversal sequences is:" << endl;


for(i=0; i<vertex; i++ )
{
    if(traversed[i] == 0)
    {
        DFS(i);
        DFSCall++;
    }
}

cout << "\n" << "Total DFS call to traverse all the vertex of the Directed  Graph is:" << DFSCall<< endl;

if(DFSCall == 1)
{

    cout<< "The input Directed Graph is strongly connected" << endl;
}
else if(DFSCall> 1)
{
    cout<< "The input Directed Graph is weakly connected and connected component is" << DFSCall<<endl;
}

return 0;
}







