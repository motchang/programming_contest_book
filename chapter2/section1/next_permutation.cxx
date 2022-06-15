#include<iostream>
#include<algorithm>//next_permutation
using namespace std;

int main(){
    int array[] = {1, 2, 3, 4};
    for(int i=0; i<4; i++){
      cout << array[i]; // 1文字プリント
      // printf("%d", array[i]);

      // a << 1;
      // a を左に1ビットシフト

      if(i != 3) {
        cout << " "; // スペースをプリント
        // printf(' ');
      }
    }
    cout << endl;
    // printf('\n');

    next_permutation(array, array+4); // array[] = {1, 2, 4, 3}
    for(int i=0; i<4; i++){
      cout << array[i];  // 1文字プリント

      if(i != 3) {
        cout << " "; // スペースをプリント
      }
    }
    cout << endl; // 改行

    next_permutation(array, array+4); // array[] = {1, 3, 2, 4}
    for(int i=0; i<4; i++){
      cout << array[i];  // 1文字プリント

      if(i != 3) {
        cout << " "; // スペースをプリント
      }
    }
    cout << endl; // 改行

    return 0;
}
