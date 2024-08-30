#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ptr1 = str1;
  const unsigned char *ptr2 = str2;
  int ans = 0;
  for (s21_size_t i = 0; i < n && ans == 0; ++i) {
    if (ptr1[i] != ptr2[i]) {
      ans += ptr1[i] - ptr2[i];
    }
  }
  return ans;
}
