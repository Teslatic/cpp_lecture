// Copyright 2018, Hendrik Vloet
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
  // __________________________________________________________________________
  // int x = 42;
  // printf("%d\n", x);
  // printf("%zu\n", sizeof(x));   // zu: sized unsigned type
  // printf("%p\n", &x);
  //
  // int* p = &x;
  // printf("%p\n", p);
  // printf("%zu\n", sizeof(p));   // zu: sized unsigned type
  //

  // p = p + 1;
  // printf("%p\n", p);
  // printf("%zu\n", sizeof(p));   // zu: sized unsigned type
  // printf("%d\n", *p);

  // __________________________________________________________________________

  // int y = 137;
  // int a[3] = {1, 2, 3};
  // printf("%d\n", y);
  // printf("%d\n", a[-1]);
  // a[-1] = 485;
  // printf("%d\n", y);

  // __________________________________________________________________________

  // int a[3] = { 2, 5, 63 };
  // printf("%d\n", a[0]);
  // printf("%d\n", a[1]);
  // printf("%d\n", a[2]);
  // printf("%zu\n", sizeof(a));
  // printf("%p\n", a);
  // int* p = a;
  // printf("%p\n", p);

  // printf("%p\n", p);
  // printf("%d\n", *p);
  // printf("%d\n", *(p+1));
  // printf("%d\n", *(p+2));
  // printf("%d\n", p[0]);
  // printf("%d\n", p[1]);
  // printf("%d\n", p[2]);
  // printf("\n");
  // p[3340] = 42;
  // printf("%d\n", p[3340]);

  // __________________________________________________________________________

  // int b[4][2] = { {10, 11}, {20, 21}, {30, 31}, {40, 41} };
  // printf("%d\n", b[3][1]);
  // // printf("%d\n", b[7]);
  // printf("%zu\n", sizeof(b));
  // printf("%p\n", b);
  // int (*q)[2] = b;    //  zeiger auf felder der größe 2
  // // int** q = b;          // does not compile
  // printf("%p\n", q);
  // printf("%d\n", q[3][1]);
  //
  // int* p = &b[0][0];
  // printf("%p\n", p);
  // printf("%d\n", p[7]);

  // __________________________________________________________________________

  char s[4] = {'d', 'o', 'o', 'f'};
  // const char* s = "Doof";
  printf("%d\n", s[0]);
  printf("%d\n", s[1]);
  printf("%d\n", s[2]);
  printf("%d\n", s[3]);
  printf("%d\n", s[4]);
  printf("%s\n", s);
}
