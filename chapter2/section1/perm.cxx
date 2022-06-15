#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

#define MAX_N 3

bool used[MAX_N];
int perm[MAX_N];

// {0, 1, 2, 3, 4,...., n-1}の並び替え n! 通りを生成する

void debug(int i) {
  cout << "perm / used / i : ";
  for(int i = 0; i < MAX_N; i ++){
    cout << perm[i];
    cout << " ";
  }
  cout << " | ";
  for(int i = 0; i < MAX_N; i ++){
    cout << used[i];
    if(i != 3) cout << " ";
  }
  cout << " | ";
  cout << i;
  cout << endl;
}

void permutation1(int pos, int n) {
  printf("pos: %d, n: %d\n", pos, n);

  if (pos == n) {
    debug(-1);
    return;
  }

  // perm の pos番目を n〜n-1のどれにするかのループ
  for (int i = 0; i < n; i ++) {
    debug(i);
    if (!used[i]) {
      // perm[pos] = perm[i];
      perm[pos] = i;
      // i をつかったのでフラグを true にしておく
      used[i] = true;

      permutation1(pos + 1, n);
      // 戻ってきたらフラグを戻しておく
      used[i] = false;
    }
  }

  return;
}

int main() {
  permutation1(0, 3);
}


#include <algorithm>

// 重複があってもすべての順列を生成する
// next_permutationは辞書順で次の順列を生成する
int perm2[MAX_N];

void permutation2(int n) {
  for (int i = 0; i < n; i ++) {
    perm2[i] = i;
  }

  do {
    // perm2 に対する操作

  } while (next_permutation(perm2, perm2 + n));
  // すべての順列を生成し終わったら next_permutation は false を返す
  return;
}
