#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> mymap;
vector<int> numbers;

int process(){
    int ans = 1;
    for(auto iter:mymap){
        ans*=(iter.second+1);
    }
    return ans-1;
}

void init(vector<vector<string>> clothes){
    for(int i=0;i<clothes.size();i++)
            mymap[clothes[i][1]]++;
}

int solution(vector<vector<string>> clothes) {
    init(clothes);
    return process();
}
