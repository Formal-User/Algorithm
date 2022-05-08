#include <string>
#include <vector>

using namespace std;

int N;
vector<int> start_, end_;

int process(){
    int ans = 0;
    for(int i = 0 ;i<N;i++){
        int tmp = 1;
        for(int j = i+1;j<N;j++){
            if(start_[j]<=end_[i] + 999) tmp ++;
        }
        ans = max(ans,tmp);
    }
    return ans;
}

pair<int, int> stot(string time) {
    char day[11];
    int h,m,s,ms;
    double fl;
    sscanf(time.c_str(),"%s %d:%d:%d.%d %lfs",day,&h,&m,&s,&ms,&fl);
    int en = (3600*h + 60*m + s)*1000 + ms;
    int st = en - fl*1000 + 1;
    return { st,en };
}

int solution(vector<string> lines) {
    int answer = 0;
    N = lines.size();
    for (int i = 0; i < N; i++) {
        pair<int, int> t = stot(lines[i]);
        start_.push_back(t.first);
        end_.push_back(t.second);
    }
    answer = process();
    return answer;
}
