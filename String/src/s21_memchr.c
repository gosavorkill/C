#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  if (str == s21_NULL) return s21_NULL;
  const unsigned char *ptr = (const unsigned char *)str;
  while ((--n) > 0 && (*ptr) != (unsigned char)c) {
    ++ptr;
  }
  return (*ptr == (unsigned char)c) ? (void *)ptr : s21_NULL;
}