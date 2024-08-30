#include <stdlib.h>

#include "s21_string.h"
void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src) {
    char truble_chars[7] = " \t\n\v\r\f\0";
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0)
      trim_chars = truble_chars;
    s21_size_t len = s21_strlen(src);
    const char *start = src;
    const char *end = src + len - 1;
    while (*start && s21_strchr(trim_chars, *start)) {
      start++;
    }
    while (end > start && s21_strchr(trim_chars, *end)) {
      end--;
    }
    s21_size_t len2 = end - start + 1;
    res = calloc(len2 + 1, sizeof(char));

    if (res) {
      s21_strncpy(res, start, len2);
      res[len2] = 0;
    }
  }
  return res;
}
