#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *hay = (char *)haystack;
  char *nl = (char *)needle;
  char *res = s21_NULL;
  int len_needle = 0;
  len_needle = s21_strlen(nl);
  if (len_needle == 0) res = hay;
  int i = 0;
  while (hay[i] != 0) {
    if (hay[i] == *nl) {
      int i1 = i;
      for (int count_nl = 0; count_nl <= len_needle; i1++, count_nl++) {
        if (count_nl == len_needle) {
          int ptr = i;
          res = &hay[ptr];
        }
        if (hay[i1] != nl[count_nl]) break;
      }
    }
    i++;
  }
  return res;
}
