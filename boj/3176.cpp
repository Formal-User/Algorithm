#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<algorithm>
#define UNDEBUG

using namespace std;

const int MAXT = 20;
int N,M;
int a,b,d;
int P[MAXT][100001][3];
int depth[100001];
vector<pair<int,int>> tree[100001];

void findP(int bef,int cur){
    for(auto item : tree[cur]){
        if(item.first == bef) continue;
        P[0][item.first][0] = cur;
        P[0][item.first][1] = item.second;
        P[0][item.first][2] = item.second;
        depth[item.first] = depth[cur] + 1;
        findP(cur,item.first);
    }
}

void preprocess(){
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        scanf("%d %d %d",&a,&b,&d);
        tree[a].push_back({b,d});
        tree[b].push_back({a,d});
    }
    P[0][1][2] = 10000000;
    findP(0,1);
    for(int i=1;i<MAXT;i++){
        for(int j=1;j<=N;j++){ 
            int befstep = P[i-1][j][0];
            P[i][j][0] = P[i-1][befstep][0];
            P[i][j][1] = max(P[i-1][befstep][1],P[i-1][j][1]);
            P[i][j][2] = min(P[i-1][befstep][2],P[i-1][j][2]);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    preprocess();
    scanf("%d",&M);
    for(int tc=0;tc<M;tc++){
        scanf("%d %d",&a,&b);
        if(depth[a] < depth[b]) swap(a,b);
        int maxx = 0,minn = 1000000;
#ifdef DEBUG
        printf("depth : %d %d\n",depth[a],depth[b]);
#endif
        for(int i=MAXT-1;i>=0;i--){
            if(P[i][a][0]&&depth[P[i][a][0]]>=depth[b]){
                maxx = max(P[i][a][1],maxx);
                minn = min(P[i][a][2],minn);
                a = P[i][a][0];
            }
        }
#ifdef DEBUG
        printf("depth : %d %d %d %d\n",a,depth[a],b,depth[b]);
#endif
        //depth setting
        if(a != b){
            for(int i=MAXT-1;i>=0;i--){
                if(P[i][a][0] != P[i][b][0]){
                    maxx = max({P[i][b][1],P[i][a][1],maxx});
                    minn = min({P[i][b][2],P[i][a][2],minn});
                    a = P[i][a][0],b = P[i][b][0];
                }
            }
            maxx = max({P[0][b][1],P[0][a][1],maxx});
            minn = min({P[0][b][2],P[0][a][2],minn});
        }
        printf("%d %d\n",minn,maxx);
    }
    return 0;
}
