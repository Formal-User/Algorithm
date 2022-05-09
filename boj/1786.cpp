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

void preprocess() {
	int bef = 0;
	for (int i = 1; P[i]; i++) {
		if (P[i] == P[bef]) {
			pre[i] = ++bef;
		}
		else {
			if (bef != 0 && P[i] == P[pre[bef - 1]])
				pre[i] = bef = pre[bef - 1] + 1;
			else
				bef = 0;
		}
	}
}

void process() {
	int j = 0;
	for (int i = 0; T[i]; i++) {
		if (T[i] == P[j]) {
			j++;
		}
		else if (j) {
			j = pre[j - 1];
			j = (P[j] != T[i]) ? 0 : j + 1;
		}
		if (P[j] == '\0') {
			ret.push_back(i - j + 2);
		}
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
