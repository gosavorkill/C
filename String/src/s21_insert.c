#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  s21_size_t length = 0;
  if (str && src && start_index <= s21_strlen(src)) {
    length = s21_strlen(src) + s21_strlen(str);
    res = malloc(length + 1);
  }
  if (res) {
    s21_size_t i = 0, j = 0;
    for (; i < start_index; i++) res[i] = src[i];
    for (; i < s21_strlen(str) + start_index; i++, j++) res[i] = str[j];
    for (j = start_index; i < length; i++, j++) res[i] = src[j];
    res[length] = '\0';
  }
  return res;
}
