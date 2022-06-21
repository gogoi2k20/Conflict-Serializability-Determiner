#include "header_files.cpp"
using namespace std; 
bool checkConflict(string &s,string &t){
    
    if(s.back()!=t.back()){
        return false;  
    }
    if(s[0]=='W'||t[0]=='W'){
        return true; 
    }
    return false;
}
bool cycleDetector(set<int>adj[],vector<int>&indegrees,int &n){
    queue<int>q;  
    for(auto &it:indegrees){
        if(it==0){
            q.push(it);  
        }
    }
    int count=0;  
    while(q.empty()==false){
        int node=q.front(); 
        q.pop(); 
        count++;  
        for(auto &it:adj[node]){
            indegrees[it]--; 
            if(indegrees[it]==0){
                q.push(it);  
            }
        }
    }
    if(count==n)return false; 
    return true; 
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);

#endif
    int m,n; 
    cout<<"Enter the number of rows of matrix: ";
    cin>>m; 
    cout<<"Enter the number of columns of matrix: ";
    cin>>n; 
    vector<vector<string>>matrix(m,vector<string>(n,"NULL")); 

    vector<pair<int,int>>pairs;  
    
    cout<<"Now enter the matrix in row-major order\n";

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             string s; 
             cin>>s; 

             matrix[i][j]=s; 
             if(s!="NULL"){
                 pairs.push_back({i,j});
             }
        }
    }

    set<int> adj[n];  
    vector<int> indegrees(n,0);  
    int sz=pairs.size();
 
    for(int j=0;j<sz;j++){
        pair<int,int>p=pairs[j];  
        int transaction=p.second; 
        int row=p.first; 
       for(int k=0;k<sz;k++){
            if(j==k)continue;
            pair<int,int>pp=pairs[k]; 
            int other_transaction=pp.second; 
            int other_row=pp.first; 
            string s=matrix[row][transaction]; 
            string t=matrix[other_row][other_transaction];  
            if(transaction==other_transaction||adj[transaction].find(other_transaction)!=adj[transaction].end()||row>=other_row){
                continue;
            }

            else if(checkConflict(s,t) ){
                indegrees[other_transaction]++; 
                adj[transaction].insert(other_transaction); 
            }
       }
    }
    
    // for(int i=0;i<n;i++){
    //     cout<<i<<"->"; 
    //     for(auto &jt:adj[i]){
    //         cout<<jt<<" "; 
    //     }
    //     cout<<endl;
    // }

    bool cycle= cycleDetector(adj,indegrees,n);
    if(cycle){
        cout<<"The schedule is not conflict serializable as there was a cycle detected\n";
    }
    else {
        cout<<"The schedule is conflict serializable as there was no cycle detected\n"; 
    }

}


//sample testcases

//1 :
/*
9 3
RX NULL NULL
NULL NULL RZ
NULL NULL WZ
NULL RY NULL
RY NULL NULL
NULL WY NULL
NULL NULL WX
NULL WZ NULL
WX NULL NULL



*/

//2:
/*
8 3
RX NULL NULL
NULL RX NULL
NULL NULL RY
NULL WY NULL
WX NULL NULL
NULL NULL WX
NULL RX NULL
NULL WX NULL


*/