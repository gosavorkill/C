#include "s21_string.h"

char *s21_strchr(const char *src, int c) {
  s21_size_t i = 0;
  char *res = s21_NULL;
  s21_size_t n = s21_strlen(src);

  while (i <= n) {
    if (src[i] == c) {
      res = &((char *)src)[i];
      break;
    }
    i++;
  }

  return res;
}
