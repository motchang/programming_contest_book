#include <queue>
#include <cstdio>

using namespace std;

int N = 10, M = 12;
char field[10][13] =
  {
    //23456789012
    "W........WW.", // 1 => 13bytes
    ".WWW.....WWW", // 2
    "....WW...WW.", // 3
    ".........WW.", // 4
    ".........W..", // 5
    "..W......W..", // 6
    ".W.W.....WW.", // 7
    "W.W.W.....W.", // 8
    ".W.W......W.", // 9
    "..W.......W.", // 10
  }; // 庭

void hexdump(void *ptr, int buflen) {
  unsigned char *buf = (unsigned char*)ptr;
  int i, j;
  for (i=0; i<buflen; i+=13) {
    printf("%06x: ", i);
    for (j=0; j<13; j++)
      if (i+j < buflen)
        printf("%02x ", buf[i+j]);
      else
        printf("   ");
    printf(" ");

    for (j=0; j<13; j++)
      if (i+j < buflen)
        printf("%c", isprint(buf[i+j]) ? buf[i+j] : '.');
    printf("\n");
  }
}

// 現在位置(x, y)
void dfs(int x, int y) {
  printf("dfs(x, y) x: %d, y: %d\n", x, y);
  hexdump(field, 10*13);

  // 今居るところを . に置き換える
  field[x][y] = '.';

  // 移動する8方向をループ
  for (int dx = 0; dx <= 1; dx ++) {
    for (int dy = -1; dy <= 1; dy ++) {
      // x方向に dx, y方向に dy 異動した場所を (nx, ny) とする
      if (dx == 0 && dy == -1) {
        continue;
      }

      int nx = x + dx, ny = y + dy;
      printf("nx: %d, ny: %d\n", nx, ny);

      // nx と ny が庭の範囲内かどうかと field[nx][ny]が水たまりかどうかを判定
      if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
  return;
}

int main() {
  int res = 0;
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < M; j ++) {
      printf("main() i: %d, j: %d\n", i, j);

      if (field[i][j] == 'W') {
        // Wが残っているならそこから dfs をはじめる
        dfs(i, j);
        res ++;
      }
    }
  }

  printf("%d\n", res);
}
