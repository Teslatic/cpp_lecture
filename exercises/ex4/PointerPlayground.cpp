#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

int main(int argc, char **argv) {
  // felder
  int FieldA[5][5] = { { 0, 1, 2, 3, 4 },
                        { 0 },
                        { 0 },
                        { 0 },
                        { 0 }};
  int FieldB[5][5] = { { 5, 6, 7, 8, 9 },
                      { 0 },
                      { 0 },
                      { 0 },
                      { 0 }};

  // pointer
  // int (*ptrCurrentState)[5] = FieldA;
  // int (*ptrNextState)[5] = FieldB;
  //
  // int cnt = 0;
  //
  //
  // ptrCurrentState = FieldB;
  // ptrNextState = FieldA;
  //
  //
  // while (true)  {
  // // printf("CurrentStatePointer  NextStatePointer\n");
  // // printf("%p       %p\n", ptrCurrentState,ptrNextState);
  // // printf("%d                    %d\n", ptrCurrentState[0][3],ptrNextState[0][3] );
  // printf("Pointer points at: %p\n", ptrCurrentState );
  // printf("Value at 0,3: %d\n", ptrCurrentState[0][3]);
  // printf("==========================================================\n");
  //
  //
  // usleep(1 * 1000* 1000);
  //
  //
  // ptrCurrentState = (cnt % 2 == 0) ? FieldA : FieldB;
  // // ptrNextState = (cnt % 2 == 0) ? FieldB : FieldA;
  //
  // cnt++;
  // }

  // // Glider
  //
  // // int glider[5][2] = { {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };
  // int glider[36][2] = {
  //   {24, 0},
  //   {22, 1}, {24, 1},
  //   {12, 2}, {13, 2}, {20, 2}, {21, 2}, {34, 2}, {35, 2},
  //   {11, 3}, {15, 3}, {20, 3}, {21, 3}, {34, 3}, {35, 3},
  //   {0, 4}, {1, 4}, {10, 4}, {16, 4}, {20, 4}, {21, 4},
  //   {0, 5}, {1, 5}, {10, 5}, {14, 5}, {16, 5}, {17, 5}, {22, 5}, {24, 5},
  //   {10, 6}, {16, 6}, {24, 6},
  //   {11, 7}, {15, 7},
  //   {12, 8}, {13, 8}
  // };
  // int (*ptrGlider)[2] = glider;
  // for (int i=0; i < 5; i++) {
  //   printf("=========================\n");
  //   printf("Component %d\n", i);
  //   for (int j=0; j < 2; j++) {
  //     if (j==0) {
  //       printf("x: %d\n",ptrGlider[i][j]);
  //     } else  {
  //       printf("y: %d\n",ptrGlider[i][j]);
  //     }
  //   }
  // }

  int random = (rand() % 100) ;
  int rnd_max = 100;
  float r = (rand() / (float)RAND_MAX * 0.1);  printf("%d\n",random );




}
