#include<iostream>                     
using namespace std;
int visited[100]={0},  a[100][100];       
void DFS(int k, int n)             
{
    visited[k]=1;                        
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0&&a[k][i]==1)    
        {
            visited[i]=1;                
            DFS(i,n);                   
        }
    }
}
int main()
{
    int n, sum=0;                       
    cin >> n;                          
    for(int i=0;i<n;i++)                 
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];             
        }
    }
    for(int i=0;i<n;i++)                 
    {
        if(visited[i]==0)                
        {
            sum++;                                     
            DFS(i, n);                   
        }
    }
    cout << sum;

    return 0;
}