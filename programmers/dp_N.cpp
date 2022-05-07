#include <string>
#include <vector>

using namespace std;

const int MAX = 32000;

int dp[MAX] = {0,};

int solution(int N, int number) {
    int t = 1;
    for(int i = N; i<MAX; i = i*10 + N){
        dp[i] = t++;
    }
    for(int k=0;k<2;k++)
        for(int i = 1;i<MAX;i++){
            if(dp[i]&&dp[i]<=8){
                for(int j = 1; j<MAX;j++){
                    if(dp[j]&&dp[j]+dp[i]<=8){
                        if(i+j<MAX)
                            dp[i + j] = dp[i + j]? min(dp[i+j], dp[i]+dp[j]):dp[i]+dp[j];
                        if(i-j>0)
                        	dp[i - j] = dp[i - j]? min(dp[i-j], dp[i]+dp[j]):dp[i]+dp[j];
                        if(i*j<MAX)
                            dp[i * j] = dp[i * j]? min(dp[i*j], dp[i]+dp[j]):dp[i]+dp[j];
                        dp[i / j] = dp[i / j]? min(dp[i/j], dp[i]+dp[j]):dp[i]+dp[j];
                    }
                }
            }
        }
    return dp[number]==0?-1:dp[number];
}
