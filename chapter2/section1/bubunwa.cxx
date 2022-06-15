#include <queue>
#include <cstdio>

using namespace std;

// 整数 a1, a2, ... an が与えられます。その中からいくつか選び、その和をちょうどｋにすうｒことができるかを判定しなさい

/*
 n = 4
 a = {1, 2, 4, 7}
 k = 13
*/

/*
 Yes(13 = 2 + 4 + 7)
 */

/*
 n = 4
 a = {1, 2, 4, 7}
 k = 15
*/

/*
 No
 */

#define MAX_N 4

int a[] = {1, 2, 4, 7};
int n = 4;
int k = 15;

/*
0
1 0 1

i: 4, sum: 0
i: 4, sum: 7
i: 4, sum: 4
i: 4, sum: 11
i: 4, sum: 2
i: 4, sum: 9
i: 4, sum: 6
i: 4, sum: 13

*/



// i まで sum を作って、残りi以降を調べる
bool dfs(int i, int sum) {
  // n個決め終わったら、今までの話sumがkと等しいかを返す
  if (i == n) {
    printf("i: %d, sum: %d\n", i, sum);
    return sum == k;
  }

  // a[i] を使わない場合
  if (dfs(i + 1, sum)) {
    return true;
  }

  // a[i] を使う場合
  if (dfs(i + 1, sum + a[i])) {
    return true;
  }

  // a[i] を使う使わないに拘わらず k が作れないので false を返す
  return false;
}

int main() {
  if (dfs(0, 0)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

  // i: 0, sum: 0, a[i]: 1
  // i: 1, sum: 0, a[i]: 2
  // i: 2, sum: 0, a[i]: 4
  // i: 3, sum: 0, a[i]: 7
  // i: 4, sum: 0, a[i]: 4
  // i: 4, sum: 7, a[i]: 4
  // i: 3, sum: 4, a[i]: 7
  // i: 4, sum: 4, a[i]: 4
  // i: 4, sum: 11, a[i]: 4
  // i: 2, sum: 2, a[i]: 4
  // i: 3, sum: 2, a[i]: 7
  // i: 4, sum: 2, a[i]: 4
  // i: 4, sum: 9, a[i]: 4
  // i: 3, sum: 6, a[i]: 7
  // i: 4, sum: 6, a[i]: 4
  // i: 4, sum: 13, a[i]: 4
