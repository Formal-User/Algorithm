#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX = 1000001;

typedef long long ll;
int N, M;
char T[MAX], P[MAX];
int pre[MAX];
vector<int> ret;

//bef는 이전까지 얼마나 매칭이 되었는가를 나타냄
//매칭되면 bef를 증가시킴.
//아닐경우 이전까지 매칭된 자리에서의 다음 글자와 같을 경우 그 매칭된 수로 넘어감. 또는 처음부터 시작
void preprocess() {
	int j = 0;
	for (int i = 1; P[i]; i++) {
		if (P[i] == P[j])
			j++;
		else if (j) {
			j = pre[j - 1];
			j = (P[i] == P[j]) ? j + 1 : 0;
		}
		pre[i] = j;
	}
}

void process() {
	int j = 0;
	for (int i = 0; T[i]; i++) {
		if (T[i] == P[j])
			j++;
		else if (j) {
			j = pre[j - 1];
			j = (T[i] == P[j]) ? j + 1 : 0;
		}
		if (!P[j])
			ret.push_back(i - j + 2);
	}
}

int main() {
	scanf("%[^\n]", T);
	getchar();
	scanf("%[^\n]", P);
	preprocess();
	process();
	printf("%d\n", ret.size());
	for (int i = 0; i < ret.size(); i++)
		printf("%d ", ret[i]);
	return 0;
}

