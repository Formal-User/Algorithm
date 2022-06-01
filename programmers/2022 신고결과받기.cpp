#include <string>
#include <vector>

using namespace std;

struct Table{
    long long int key;
    int idx;
}table[4000];

int attack[1000][1000];

long long int transInt(string str){
    long long int ret = 0;
    for(auto s : str){
        ret = (ret<<5) + int(s);
    }
    return ret;
}

vector<string> stringSplit(string str){
    vector<string> ret;
    int loc = str.find(' ');
    ret.push_back(str.substr(0,loc));
    ret.push_back(str.substr(loc + 1));
    return ret;
}

int hashFnc(string str){
    int h = 401;
    for(int i=0;i<str.size();i++){
        h = ((h<<5) + str[i])%4000;
    }
    return h;
}

void hasing(string str,int idx){
    int h = hashFnc(str);
    long long key = transInt(str);
    while(table[h].key&&table[h].key!=key){h++;h%=4000;}
    table[h].key = key;
    table[h].idx = idx;
    return;
}

int find(string str){
    int h = hashFnc(str);
    long long key = transInt(str);
    while(table[h].key!=key){h++;h%=4000;}
    return table[h].idx;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    for(int i=0;i<id_list.size();i++)
        hasing(id_list[i],i);
    for(int i=0;i<report.size();i++){
        vector<string> strspl = stringSplit(report[i]);
        int a = find(strspl[0]), b = find(strspl[1]);
        attack[a][b] = 1;
    }
    for(int i=0;i<id_list.size();i++){
        int attacked = 0;
        vector<int> tmp;
        for(int j=0;j<id_list.size();j++)
            if(attack[j][i]){
                attacked++;
                tmp.push_back(j);
            }
        if(attacked>=k){
            for(int j=0;j<tmp.size();j++)
                answer[tmp[j]]++;
        }
    }
    return answer;
}
