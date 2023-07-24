#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // write code for krager's min cut
  int G[4][4] = {
      {0, 1, 1, 1},
      {1, 0, 0, 1},
      {1, 0, 0, 1},
      {1, 1, 1, 0},
  };
  int n = 4;
  int iter = 0;
  int num = n;

  while (iter < 100 * n * (n - 1)) {
    if(num < 2){
      break;
    }
    vector<vector<int> > G1(num, vector<int>(num, 0));
    vector<vector<int> > G2(num - 1, vector<int>(num - 1, 0));
    srand(time(0));
    // step 1
    // pick a random edge
    int u = rand() % n;
    int v = rand() % n;

    // check if there is edge
    if (G[u][v] == 0) {
      continue;
    }
    // step 2
    for (int i = 0; i < n - 1; i++) {
      for (int j = 1; j < n; j++) {
        int cnt = 0;
        if (i == u && j == v) {
          G1[i][j] = G1[j][i] = 0;
        } else if (i == u or i == v) {
          if (G[u][j] > 0) {
            cnt += G[u][j];
          }
          if (G[v][j] > 0) {
            cnt += G[v][j];
          }
          G1[u][j] = G1[v][j] = cnt;
        } else if (j == u or j == v) {
          if (G[i][u] > 0) {
            cnt += G[i][u];
          }
          if (G[i][v] > 0) {
            cnt += G[i][v];
          }
          G1[i][u] = G1[i][v] = cnt;
        } else {
          G1[i][j] = G1[j][i] = G[i][j];
        }
        // step 3
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            if (i >= j) {
              G1[i][j] = G1[j][i];
            }
          }
        }
          // step 4

          // copy G1 to G2 but don't copy vth row and vth column
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        while(i1 < n){
          if(i1 == v) {
            i1++;
            continue;
          }
          while(j1 < n){
            if(j1 == v){
              j1++;
              continue;
            }else {
              G2[i2][j2] = G1[i1][j1];
              j1++;
              j2++;
            }
          }
          i2++;
          i1++;
        }

          // step 5
          for (int i = 0; i < n - 1; i++)
          {
            for (int j = 0; j < n - 1; j++)
            {
              G[i][j] = G2[i][j];
            }
          }
        num -= 1;
      }
    }

    iter++;
  }
  cout << G[0][1] << endl;
  return 0;
}
