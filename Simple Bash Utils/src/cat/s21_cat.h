#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <string.h>
struct flags {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
};
struct stroks {
  int numbering;
  int first;
  int secondary;
  int third;
  int g;
};
void check_flags(char a, struct flags *features, int *sum_flags);
void flag_b(struct stroks *fun, struct flags features, char l);
int flag_t(struct flags features, char *l);
void flag_e(struct stroks *fun, struct flags features, char l);
void flag_n(struct stroks *fun, struct flags features);
void flag_s(struct stroks *fun, struct flags features, char l);
int flag_v(struct stroks *fun, struct flags features, char *l);
void File_open(char *file_name, struct flags features);
int parsLongFlag(int argc, char *argv[], struct flags *features);
int parsShortFlag(int argc, char *argv[], struct flags *features);
#endif  // SRC_CAT_S21_CAT_H_
