#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  unsigned int length1 = s21_strlen(str1);
  unsigned int length2 = s21_strlen(str2);
  int pos = -1;
  for (unsigned int i = 0; i < length1 && pos == -1; ++i) {
    for (unsigned int j = 0; j < length2 && pos == -1; ++j) {
      if (str1[i] == str2[j]) {
        pos = i;
      }
    }
  }
  char *ch = (char *)str1;
  ch += pos;
  return (pos > -1) ? ch : s21_NULL;
}