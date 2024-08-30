#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *token;
  char *res;
  if (str != s21_NULL) {
    token = str;
  }
  if (token == s21_NULL || *token == '\0') {
    return s21_NULL;
  }
  while (*token != '\0' && s21_strchr(delim, *token) != NULL) {
    token++;
  }
  char *delim_pos = s21_strpbrk(token, delim);
  if (delim_pos != s21_NULL) {
    *delim_pos = '\0';
    res = token;
    token = delim_pos + 1;
  } else {
    res = token;
    token = s21_NULL;
  }
  return res;
}
