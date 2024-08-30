#include <stdlib.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *ptr = s21_NULL;
  if (str) {
    int length = s21_strlen(str);
    ptr = (char *)calloc(length + 1, sizeof(char));
    if (ptr != s21_NULL) {
      for (int i = 0; i < length; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          ptr[i] = str[i] + 32;
        } else {
          ptr[i] = str[i];
        }
      }
    }
  }
  return (void *)ptr;
}
