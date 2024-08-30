#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int founded = 0;
  s21_size_t count = 0;

  // если еще не нашли вхлождение str2 в str1
  for (s21_size_t lengthStr1 = 0; lengthStr1 < s21_strlen(str1) && !founded;
       lengthStr1++) {
    for (s21_size_t lengthStr2 = 0; lengthStr2 < s21_strlen(str2);
         lengthStr2++) {
      // если любой из символов str2 есть в str1, то заканчиваем цикл и
      // возвращаем количество символов до этого нахождения
      if (str1[lengthStr1] == str2[lengthStr2]) {
        founded = 1;
        break;
      }
    }
    // если еще не нашли, то добавляем 1 к длине
    if (!founded) count++;
  }

  // возвращаем наибольшую длину начального участка str1, в котором нет символов
  // из str2
  return count;
}