#include <cstdio>
#include <vector>
using namespace std;

int n, k, p;
int maxSeqSum = 0;
bool find = false;
vector<int> number;
vector<int> ans;
vector<int> pows;

int power(int n, int p) {
    int sum = 1;
    for (int i = 1; i <= p; i++) sum *= n;
    return sum;
}

void init() {
    int i = 0, temp;
    while ((temp =  power(i, p)) <= n) {
        pows.push_back(temp);
        i++;
    }
}

//index: currently select the index-th number
//curBaseIndex: the value we choose, for example we choose from {169, 144, 121 ...} respectively
void dfs(int index, int curBaseIndex, int expSum, int seqSum) {
    //printf("(%d, %d, %d, %d)\n", index, curBaseIndex, expSum, seqSum);
    if (index == k && expSum == n) {
        find = true; //find it
        //printf("find\n");
        if (seqSum > maxSeqSum) {
            maxSeqSum = seqSum;
            ans.clear();
            ans.assign(number.begin(), number.end());
        }
        return;
    }
    if (index >= k || expSum >= n) return; //prune
    if (curBaseIndex >= 1) { //because we don't need power 0
        //choose curBase
        number.push_back(curBaseIndex);
        dfs(index + 1, curBaseIndex, expSum + pows[curBaseIndex], seqSum + curBaseIndex);
        number.pop_back();
        //not choose curBase
        dfs(index, curBaseIndex - 1, expSum, seqSum);
    }
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    init();
    dfs(0, pows.size() - 1, 0, 0);
    if (!find) {
        printf("Impossible");
        return 0;
    } else {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); i++) {
            printf(" + %d^%d", ans[i], p);
        }
    }
}

//Solutions:
//for sample input1 we can generate power array [0, 1, 4, 9, 16 ..., 169]
//In first step, we can choose number1 = 169 and select next number from [0,..,169]
//we can also choose number1 = 144 and select next number from [0, .., 144]


