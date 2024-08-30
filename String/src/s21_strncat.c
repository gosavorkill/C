#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (src == s21_NULL || dest == s21_NULL) {
    return s21_NULL;
  }
  char *temp = dest;
  while (*temp != '\0') {
    ++temp;
  }
  while (n > 0 && *src != '\0') {
    *temp = *src;
    ++temp;
    ++src;
    --n;
  }
  *temp = '\0';
  return dest;
}