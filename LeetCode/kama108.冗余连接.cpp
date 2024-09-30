#include<iostream>
#include<vector>

using namespace std;

int length = 1000;
vector<int> set = vector<int>(length, 0);

void init(){
    for(int i = 0; i < length; ++i){
        set[i] = i;
    }
}

int find(int u){
    if(set[u] == u){
        return u;
    }
    else{
        return set[u] = find(set[u]);
    }
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return ;
    }
    set[v] = u;
}


int main(){
    // 这道题意思是要删除冗余连接
    // 实际上，只要删除第一条，两边顶点都已经在集合里面的那条就可以了，后面的边不用担心
    // 即当isSame(u, v)=true的时候，就删除(u, v)这条边，然后返回
    init();
    int n, u, v;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>u>>v;
        if(isSame(u, v)){
            cout << u << ' ' << v << endl;
            return 0;
        }
        else{
            join(u, v);
        }
    }
    return 0;
}