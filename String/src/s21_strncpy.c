#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (src == s21_NULL) {
    return s21_NULL;
  }
  if (dest != s21_NULL) {
    for (unsigned int i = 0; i < n && src[i] != '\0'; ++i) {
      dest[i] = src[i];
    }
    dest[s21_strlen(src)] = '\0';
  }
  return dest;
}