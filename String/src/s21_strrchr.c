#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *result = s21_NULL;
  // ищем с конца строки
  for (int i = s21_strlen(str); i >= 0; i--) {
    // если находим символ с, то возвращаем строку после него (включительно)
    if (str[i] == c) {
      result = str + i;
      break;
    }
  }

  return (char *)result;
}