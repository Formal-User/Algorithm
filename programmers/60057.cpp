#include <string>
#include <vector>
#include <map>

const int inf = 987654231;

using namespace std;

int divide(string s,int n){
    string ret = ""; string bef = ""; string sub = "";
    int count = 1;
    while(s.size()>=n){
        sub = s.substr(0,n);
        s = s.substr(n);
        if(bef != sub){
            ret+=(count!=1)?to_string(count)+bef:bef;
            count = 1;
            bef = sub;
        }
        else{
            count ++;
        }
    }
    ret+=(count!=1)?to_string(count)+bef:bef;
    ret+=s;
    return ret.size();
}



int solution(string s) {
    int ans = s.size();
    for(int i=1;i<=s.size()/2;i++){
        ans = min(ans,divide(s,i));
    }
    return ans;
}
