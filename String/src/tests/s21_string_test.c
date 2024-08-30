#include "../s21_string.h"

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

START_TEST(s21_memchr_test) {
  char str[] = "Hello World!";
  ck_assert_ptr_eq(s21_memchr(str, 'H', 5), memchr(str, 'H', 5));
  char str1[] = "Hello World!";
  ck_assert_ptr_eq(s21_memchr(str1, 'A', 10), memchr(str1, 'A', 10));
  //  ck_assert_ptr_eq(s21_memchr("", 'H', 5), memchr("", 'H', 5));
}

END_TEST

START_TEST(memcmp1) {
  char str[] = "Hello";
  char str1[] = "Hello";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp2) {
  char str[] = "Hello, School";
  char str1[] = "Hello, School";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}

END_TEST

START_TEST(memcmp3) {
  char str[] = "Hello, School 21!";
  char str1[] = "Hello, School 21!";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp4) {
  char str[] = "1234567890";
  char str1[] = "1234567890";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp5) {
  char str[] = "1234567890";
  char str1[] = "0987654321";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp6) {
  char str[] = "Hello, School";
  char str1[] = "Hello, \n School";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(memcmp7) {
  char str[] = "Hello, School";
  char str1[] = "Hello, School\0";
  s21_size_t len = strlen(str);
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST
START_TEST(memcmp8) {
  char str[] = "Hello, School";
  char str1[] = "Hello, School";
  s21_size_t len = 5;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST
START_TEST(memcmp9) {
  char str[] = "Hello";
  char str1[] = "Hello";
  s21_size_t len = 0;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST
START_TEST(memcmp10) {
  char str[] = "Hello";
  char str1[] = "School";
  s21_size_t len = 6;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST
START_TEST(memcmp11) {
  char str[] = "!@#$%^&*";
  char str1[] = "!@#$%^&*";
  s21_size_t len = 9;
  ck_assert_int_eq(memcmp(str, str1, len), s21_memcmp(str, str1, len));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char dest[20] = "HELLO", dest1[20] = "HELLO";
  ck_assert_str_eq(s21_memcpy(dest, " WORLD", 5), memcpy(dest1, " WORLD", 5));
  ck_assert_str_eq(s21_memcpy(dest, "123456", 2), memcpy(dest1, "123456", 2));
}

END_TEST

START_TEST(s21_memset_test) {
  char dest[20] = "HELLO", dest1[20] = "HELLO";
  ck_assert_str_eq(s21_memset(dest, 'A', 5), memset(dest1, 'A', 5));
  ck_assert_str_eq(s21_memset(dest, '1', 19), memset(dest1, '1', 19));
}

END_TEST

START_TEST(s21_strncat_test) {
  char dest[20] = "HELLO", dest1[20] = "HELLO";
  char src[7] = " world", src1[7] = " world";
  ck_assert_str_eq(s21_strncat(dest, src, s21_strlen(src)),
                   strncat(dest1, src1, strlen(src1)));
  ck_assert_str_eq(s21_strncat(dest, "123456", 2), strncat(dest1, "123456", 2));
  ck_assert_str_eq(s21_strncat(dest, "123456", 19),
                   strncat(dest1, "123456", 19));
}

END_TEST

START_TEST(s21_strncpy_test) {
  char *s1 = "Hello";
  char s2[100], s4[100];
  char *s3 = "Hello";
  ck_assert_str_eq(s21_strncpy(s2, s1, 10), strncpy(s4, s3, 10));
  ck_assert_ptr_null(s21_strncpy(s21_NULL, s21_NULL, 0));
}

END_TEST

START_TEST(s21_strcspn_test) {
  char dest[20] = "Prado", dest1[20] = "Prado", src[7] = "abc";
  ck_assert_uint_eq(s21_strcspn(dest, src), strcspn(dest1, src));
  ck_assert_uint_eq(s21_strcspn(dest, "p"), strcspn(dest1, "p"));
  ck_assert_uint_eq(s21_strcspn(dest, "bbb"), strcspn(dest1, "bbb"));
  char *s1 = "Hello world";
  char *s2 = "Hello";
  char *s3 = "World";
  char *s4 = "School";
  char *s5 = "0*/";
  char *s6 = "21";
  char *s7 = " ";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
  ck_assert_uint_eq(s21_strcspn(s3, s4), strcspn(s3, s4));
  ck_assert_uint_eq(s21_strcspn(s3, s5), strcspn(s3, s5));
  ck_assert_uint_eq(s21_strcspn(s3, s6), strcspn(s3, s6));
  ck_assert_uint_eq(s21_strcspn(s3, s7), strcspn(s3, s7));
}

END_TEST

START_TEST(s21_strerror_test) {
  for (int i = -1; i < 350; i++) {
    char *s1 = s21_strerror(i);
    char *s2 = strerror(i);
    ck_assert_uint_eq((unsigned long)*s1, (unsigned long)*s2);
  }
}

END_TEST

START_TEST(s21_strpbrk_test) {
  char dest[20] = "Prado", dest1[20] = "Prado", src[7] = "abc";
  ck_assert_str_eq(s21_strpbrk(dest, src), strpbrk(dest1, src));
  ck_assert_ptr_null(s21_strpbrk(dest, "bbb"));
  ck_assert_ptr_null(strpbrk(dest1, "bbb"));
  ck_assert_str_eq(s21_strpbrk(dest, "dado"), strpbrk(dest1, "dado"));
}

END_TEST

START_TEST(s21_strrchr_test) {
  char dest[20] = "Pradoabo", dest1[20] = "Pradoabo";
  ck_assert_str_eq(s21_strrchr(dest, 'a'), strrchr(dest1, 'a'));
  ck_assert_str_eq(s21_strrchr(dest, 'r'), strrchr(dest1, 'r'));
  ck_assert_str_eq(s21_strrchr(dest, 'o'), strrchr(dest1, 'o'));
  ck_assert_str_eq(s21_strrchr(dest, 'P'), strrchr(dest1, 'P'));
  ck_assert_ptr_null(s21_strrchr(dest, 'F'));
  ck_assert_ptr_null(strrchr(dest1, 'F'));
}

END_TEST

START_TEST(s21_strstr_test) {
  char dest[20] = "Pradoabo", dest1[20] = "Pradoabo", src[4] = "rad";
  ck_assert_str_eq(s21_strstr(dest, "doa"), strstr(dest1, "doa"));
  ck_assert_str_eq(s21_strstr(dest, src), strstr(dest1, src));
  ck_assert_ptr_eq(s21_strstr(dest, "ght"), strstr(dest1, "ght"));
  char *s1 = "Hello world";
  char *s2 = "Hello";
  char *s3 = "World";
  char *s4 = "School";
  char *s5 = "0*/";
  char *s6 = "21";
  char *s7 = " ";
  ck_assert_ptr_eq(s21_strstr(s1, s2), strstr(s1, s2));
  ck_assert_ptr_eq(s21_strstr(s3, s4), strstr(s3, s4));
  ck_assert_ptr_eq(s21_strstr(s5, s6), strstr(s5, s6));
  ck_assert_ptr_eq(s21_strstr(s4, s5), strstr(s4, s5));
  ck_assert_ptr_eq(s21_strstr(s7, s1), strstr(s7, s1));
}

END_TEST

START_TEST(s21_strchr_test) {
  char dest[20] = "HELLO", dest1[20] = "HELLO";
  ck_assert_ptr_eq(s21_strchr(dest, 'e'), strchr(dest1, 'e'));
  ck_assert_str_eq(s21_strchr("AZBUKA", 'Z'), strchr("AZBUKA", 'Z'));
  ck_assert_str_eq(s21_strchr("sg43ergfd", '3'), strchr("sg43ergfd", '3'));
  char *s1 = "Hello world";
  char *s2 = "Hello ";
  ck_assert_uint_eq((unsigned long)s21_strrchr(s1, 'o'),
                    (unsigned long)strrchr(s1, 'o'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(s1, 'd'),
                    (unsigned long)strrchr(s1, 'd'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(s1, 'w'),
                    (unsigned long)strrchr(s1, 'w'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(s2, ' '),
                    (unsigned long)strrchr(s2, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(s2, 'o'),
                    (unsigned long)strrchr(s2, 'o'));
}

END_TEST

START_TEST(s21_strncmp_test) {
  ck_assert_int_eq(s21_strncmp("abc", "cba", 2), strncmp("abc", "cba", 2));
  ck_assert_int_eq(s21_strncmp("abc", "abcd", 2), strncmp("abc", "abcd", 2));
  ck_assert_int_eq(s21_strncmp("abcdefg", "abcdef", 3),
                   strncmp("abcdefg", "abcdef", 3));
  ck_assert_int_eq(s21_strncmp("cbdef", "aacd", 5),
                   strncmp("cbdef", "aacd", 5));
}

END_TEST

START_TEST(s21_strlen_test) {
  char *s1 = "234234\0";
  char *s2 = "Hello";
  char *s3 = "World";
  char *s4 = " ";
  char *s5 = "120456";
  char *s6 = "world\\\0";
  char *s7 = "";
  char *s8 = "1";
  ck_assert_int_eq(s21_strlen(s1), strlen(s1));
  ck_assert_int_eq(s21_strlen(s2), strlen(s2));
  ck_assert_int_eq(s21_strlen(s3), strlen(s3));
  ck_assert_int_eq(s21_strlen(s4), strlen(s4));
  ck_assert_int_eq(s21_strlen(s5), strlen(s5));
  ck_assert_int_eq(s21_strlen(s6), strlen(s6));
  ck_assert_int_eq(s21_strlen(s7), strlen(s7));
  ck_assert_int_eq(s21_strlen(s8), strlen(s8));
}

END_TEST

START_TEST(s21_strtok_test) {
  char str1[] = "hello/world/school21";
  char del1[] = "/";

  char str2[] = "hello/world/school21";
  char del2[] = "/";
  char *res1 = s21_strtok(str1, del1);
  char *res2 = strtok(str2, del2);
  while (res1 != s21_NULL) {
    ck_assert_str_eq(res1, res2);
    res1 = s21_strtok(s21_NULL, del1);
    res2 = strtok(s21_NULL, del2);
  }
}

END_TEST

START_TEST(test_s21_sprintf_с) {
  char buff[70] = {0};
  char s21_buff[70] = {0};

  int x6 = 12345;
  char *format_string3 = "%+.*d\n";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string3, 8, 4, x6),
                   sprintf(buff, format_string3, 8, 4, x6));
  ck_assert_str_eq(buff, s21_buff);

  short x7 = -32768;
  char *format_string4 = "%hd\n";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string4, x7),
                   sprintf(buff, format_string4, x7));
  ck_assert_str_eq(buff, s21_buff);

  float x8 = 123.456;
  char *format_string5 = "% 010.2f\n";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string5, x8),
                   sprintf(buff, format_string5, x8));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_d_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};
  int x1 = 234;
  int x2 = -345;
  char *format_string1 = "love %+d % d love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string1, x1, x2),
                   sprintf(buff, format_string1, x1, x2));
  ck_assert_str_eq(buff, s21_buff);

  int x5 = 2342;
  int x6 = -345;
  char *format_string3 = "love %+10d %-10d love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string3, x5, x6),
                   sprintf(buff, format_string3, x5, x6));
  ck_assert_str_eq(buff, s21_buff);

  char *format_string4 = "precision test %.0d %.d %.*d";
  int x7 = 0;
  int x8 = 0;
  int x9 = 3;
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string4, x7, x8, x9, x1),
                   sprintf(buff, format_string4, x7, x8, x9, x1));
  ck_assert_str_eq(buff, s21_buff);
  int x10 = 123;
  char *format_string6 = "flag test %+d % d %#x %o %010d";
  unsigned int x12 = 42;
  int x13 = -42;
  ck_assert_int_eq(
      s21_sprintf(s21_buff, format_string6, x12, x13, x12, x12, x10),
      sprintf(buff, format_string6, x12, x13, x12, x12, x10));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_d_2) {
  char s21_buff[200] = {};
  char buff[200] = {};

  char *format_string1 = "%ld, %+-10.8d, % d, % -*.10d, %*d, %-20.10hd, %.0d";
  int res21 = s21_sprintf(s21_buff, format_string1, 12345, 321, 4444, 25, 55555,
                          10, 1, 22, 0);
  int res =
      sprintf(buff, format_string1, 12345, 321, 4444, 25, 55555, 10, 1, 22, 0);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);

  char *format_string2 = "%10ld, %-10ld, %+5hd, %20Lf, %-5hu";
  res21 =
      s21_sprintf(s21_buff, format_string2, __INT_MAX__, INT_MIN, SHRT_MAX - 1,
                  (long double)99999999999999999 - 10, (unsigned short int)225);
  res = sprintf(buff, format_string2, __INT_MAX__, INT_MIN, SHRT_MAX - 1,
                (long double)99999999999999999 - 10, (unsigned short int)225);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_i) {
  char buff[70] = {0};
  char s21_buff[70] = {0};
  long int x3 = 2323454;
  short int x4 = 3;
  char *format_string2 = "love %-3li %+03hi love";
  ck_assert_int_eq(s21_sprintf(buff, format_string2, x3, x4),
                   sprintf(s21_buff, format_string2, x3, x4));

  int x1 = 0x234;
  int x2 = 0x345;
  int input = 10;
  char *format_string1 = "love %*i %i love";
  ck_assert_int_eq(s21_sprintf(buff, format_string1, input, x1, x2),
                   sprintf(s21_buff, format_string1, input, x1, x2));
}
END_TEST

START_TEST(test_s21_sprintf_e_1) {
  char buff[100];
  char s21_buff[100];

  double x1 = 12345.2345;
  int input_width = 8;
  int input_precision = 2;
  char *format_string1 = "love %*.*e % E love";
  ck_assert_int_eq(
      s21_sprintf(s21_buff, format_string1, input_width, input_precision, x1,
                  x1),
      sprintf(buff, format_string1, input_width, input_precision, x1, x1));
  ck_assert_str_eq(buff, s21_buff);

  char *format_string5 = "love %*e love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string5, 10, x1),
                   sprintf(buff, format_string5, 10, x1));
  ck_assert_str_eq(buff, s21_buff);

  char *format_string6 = "love %.*e love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string6, 4, x1),
                   sprintf(buff, format_string6, 4, x1));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_e_2) {
  char s21_buff[200] = {};
  char buff[200] = {};

  char *format_string = "love %*.*e % E love";
  int res21 = s21_sprintf(s21_buff, format_string, 312.1121, 444.1231,
                          (long double)444.1, 55.142241, 10, 1.1, 555.123123, 1,
                          88.111, 4321.12);
  int res = sprintf(buff, format_string, 312.1121, 444.1231, (long double)444.1,
                    55.142241, 10, 1.1, 555.123123, 1, 88.111, 4321.12);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_f_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};
  float x11 = 234.123;
  float x21 = -345.678;
  char *format_string11 = "love %.f %+f love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string11, x11, x21),
                   sprintf(buff, format_string11, x11, x21));
  ck_assert_str_eq(s21_buff, buff);
  long double x31 = 21234.23434;
  long double x41 = -3234.56788;
  char *format_string21 = "love %10.2Lf %+.4Lf love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string21, x31, x41),
                   sprintf(buff, format_string21, x31, x41));
  ck_assert_str_eq(s21_buff, buff);
  double x51 = 0.2341;
  double x61 = -12345;
  char *format_string31 = "love %#f %010f love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string31, x51, x61),
                   sprintf(buff, format_string31, x51, x61));
  ck_assert_str_eq(s21_buff, buff);
  float x1 = 234.123;
  float width1 = -1.55;
  char *format_string1 = "%f";
  s21_sprintf(s21_buff, format_string1, width1, x1);
  sprintf(buff, format_string1, width1, x1);
  ck_assert_str_eq(s21_buff, buff);

  float x2 = -345.678;
  int width2 = 10;
  int precision2 = -0.5;
  char *format_string2 = "%*.*f";
  ck_assert_int_eq(
      s21_sprintf(s21_buff, format_string2, width2, precision2, x2),
      sprintf(buff, format_string2, width2, precision2, x2));
  ck_assert_str_eq(s21_buff, buff);
  long double x3 = 21234.23434;
  int precision3 = 4;
  char *format_string3 = "%.*Lf";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string3, precision3, x3),
                   sprintf(buff, format_string3, precision3, x3));
  ck_assert_str_eq(s21_buff, buff);
  long double x4 = -3234.56788;
  int precision4 = 4;
  char *format_string4 = "%.*Lf";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string4, precision4, x4),
                   sprintf(buff, format_string4, precision4, x4));
  ck_assert_str_eq(s21_buff, buff);
  long double x7 = 12345.6789;
  char *format_string7 = "%Lf";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string7, x7),
                   sprintf(buff, format_string7, x7));
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_f_2) {
  char s21_buff[200] = {};
  char buff[200] = {};
  const char *format_string =
      "%f, % -025.10f, % Lf, % 020.2f, %*f, %.3f, %.*f, %-10f";
  int res21 = s21_sprintf(s21_buff, format_string, 312.1121, 444.1231,
                          (long double)444.1, 555555.1, 10, 1.1, 555.123123, 1,
                          55555.111, 4321.1);
  int res = sprintf(buff, format_string, 312.1121, 444.1231, (long double)444.1,
                    555555.1, 10, 1.1, 555.123123, 1, 55555.111, 4321.1);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_g_G) {
  int res = 0;
  int resBI = 0;
  char result[200] = {};
  char resultBI[200] = {};
  const char *test11 = "%g, % -025.10g, % g, % 020.2g, %6g, %.3G, %.10G, %-10G";
  res = s21_sprintf(result, test11, 312.1121, 444.1231, 444.1, 56.199241, 1.1,
                    (double)123.456, (double)55555.111, 4321.1);
  resBI = sprintf(resultBI, test11, 312.1121, 444.1231, 444.1, 56.199241, 1.1,
                  (double)123.456, (double)55555.111, 4321.1);
  ck_assert_str_eq(result, resultBI);
  ck_assert_int_eq(res, resBI);
}
END_TEST

START_TEST(test_s21_sprintf_o_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};

  int x1 = 234234;
  unsigned short x2 = 34;

  char *format_string1 = "love %o %o %o love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string1, x1, x2, x1),
                   sprintf(buff, format_string1, x1, x2, x1));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_o_2) {
  char s21_buff[200] = {};
  char buff[200] = {};
  const char *format_string =
      "%#20.20o, %#.20o, %#020.20o, %#-030.20o, %lo, %ho";
  int res21 =
      s21_sprintf(s21_buff, format_string, 255, -255, 123321, 123, 225, 333);
  int res = sprintf(buff, format_string, 255, -255, 123321, 123, 225, 333);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_s_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};
  char *x1 = "you";
  char *x2 = "peer";
  char *format_string1 = "%10.2s my favourite %-10s";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string1, x1, x2),
                   sprintf(buff, format_string1, x1, x2));
  ck_assert_str_eq(buff, s21_buff);

  double d = 3.14159265358979323846;
  char *format_string5 = "%.*s";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string5, 3, "hello world"),
                   sprintf(buff, format_string5, 3, "hello world"));
  ck_assert_str_eq(buff, s21_buff);

  char *format_string6 = "%10.2f";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string6, d),
                   sprintf(buff, format_string6, d));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_s_2) {
  char s21_buff[200] = {};
  char buff[200] = {};
  const char *format_string = "%s, %4s, %.2s, %5.2s, %-*s";
  int res21 = s21_sprintf(s21_buff, format_string, "hello world", "hello",
                          "hello", "hello w", 10, "hellow");
  int res = sprintf(buff, format_string, "hello world", "hello", "hello",
                    "hello w", 10, "hellow");
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_u_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};
  unsigned int x1 = 234;
  unsigned int x2 = 345;
  char *format_string1 = "love %u %u love";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string1, x1, x2),
                   sprintf(buff, format_string1, x1, x2));
  ck_assert_str_eq(buff, s21_buff);

  long unsigned int x3 = 2323454;
  short unsigned int x4 = 3;
  char *format_string2 = "love %lu %hu love";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string2, x3, x4),
                   sprintf(buff, format_string2, x3, x4));
  ck_assert_str_eq(buff, s21_buff);

  unsigned int x5 = 2342;
  unsigned int x6 = 345;

  char *format_string3 = "love %10u %10u love";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string3, x5, x6),
                   sprintf(buff, format_string3, x5, x6));
  ck_assert_str_eq(buff, s21_buff);

  format_string3 = "love %#-010X %#08x % 10o %+d %.2f love";
  double x12 = 1.23456789;
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string3, x5, x6, x5, -5, x12),
                   sprintf(buff, format_string3, x5, x6, x5, -5, x12));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_u_2) {
  char s21_buff[200] = {};
  char buff[200] = {};
  const char *format_string = "%hu, %.3u, %10u, %-10u";
  int res21 =
      s21_sprintf(s21_buff, format_string, (unsigned int)12345,
                  (unsigned int)32122, (unsigned int)4444, (unsigned int)0);
  int res = sprintf(buff, format_string, (unsigned int)12345,
                    (unsigned int)32122, (unsigned int)4444, (unsigned int)0);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_x_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};

  long int x3 = 23423423;
  long int x4 = 3451231;
  char *format_string2 = "love %#lx %#lX love";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string2, x3, x4),
                   sprintf(buff, format_string2, x3, x4));
  ck_assert_str_eq(buff, s21_buff);

  long int x = 4095;
  char *format_string = "%03X";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_x_2) {
  char buff[70] = {0};
  char s21_buff[70] = {0};

  long int x = 65535;
  char *format_string = "%X";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  long int x1 = 255;
  char *format_string1 = "0x%x";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string1, x1),
                   sprintf(buff, format_string1, x1));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_x_3) {
  char buff[70] = {0};
  char s21_buff[70] = {0};

  long int x = 255;
  char *format_string = "0x%X";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_x_4) {
  char buff[70] = {0};
  char s21_buff[70] = {0};

  long int x = 4095;
  char *format_string = "%03X";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_x_X) {
  char s21_buff[200] = {};
  char buff[200] = {};
  const char *format_string =
      "%#20.20x, %#.20X, %#020.20X, %#-030.20X, %lx, %hX";
  int res21 = s21_sprintf(s21_buff, format_string, 255, -255, 123321, 123,
                          (long int)225, (short int)333);
  int res = sprintf(buff, format_string, 255, -255, 123321, 123, (long int)225,
                    (short int)333);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_p_1) {
  char buff[70] = {0};
  char s21_buff[70] = {0};
  int x1 = 234;
  int x2 = 345;
  ck_assert_int_eq(s21_sprintf(s21_buff, "love %10p %-10p love", &x1, &x2),
                   sprintf(buff, "love %10p %-10p love", &x1, &x2));
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_p_2) {
  char s21_buff[200] = {0};
  char buff[200] = {0};
  const char *format_string = "%30.20p, %20.20p, %-20p, %-020p, %-030.20p";
  int res21 = s21_sprintf(s21_buff, format_string, s21_buff, buff, s21_buff,
                          buff, s21_buff);
  int res =
      sprintf(buff, format_string, s21_buff, buff, s21_buff, buff, s21_buff);
  ck_assert_int_eq(res21, res);
  ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test_s21_sprintf_flags) {
  char buff[100] = {0};
  char s21_buff[100] = {0};
  int x = 42;
  char *format_string = "%-10d";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%+d";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "% d";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%#x";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%05d";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_width) {
  char buff[100] = {0};
  char s21_buff[100] = {0};
  int x = 42;
  char *format_string = "%5d";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%*d";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, 5, x),
                   sprintf(buff, format_string, 5, x));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_length) {
  char buff[100] = {0};
  char s21_buff[100] = {0};
  short y = 12345;
  long z = 987654321;
  long long w = 123456789012345;

  char *format_string = "%hd";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, y),
                   sprintf(buff, format_string, y));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%ld";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, z),
                   sprintf(buff, format_string, z));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%lld";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, w),
                   sprintf(buff, format_string, w));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(test_s21_sprintf_precision) {
  char buff[100] = {0};
  char s21_buff[100] = {0};
  double x = 3.141592653589793;
  float y = 2.71828;
  int z = 42;

  char *format_string = "%.2f";

  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%.3f";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, x),
                   sprintf(buff, format_string, x));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%.1f";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, y),
                   sprintf(buff, format_string, y));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%.4f";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, y),
                   sprintf(buff, format_string, y));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%.3d";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, z),
                   sprintf(buff, format_string, z));
  ck_assert_str_eq(buff, s21_buff);

  format_string = "%.6d";
  ck_assert_int_eq(s21_sprintf(s21_buff, format_string, z),
                   sprintf(buff, format_string, z));
  ck_assert_str_eq(buff, s21_buff);
}
END_TEST

START_TEST(s21_to_upper_test) {
  ck_assert_str_eq(s21_to_upper("Hello World!"), "HELLO WORLD!");
  ck_assert_str_eq(s21_to_upper("AaBbCcDd"), "AABBCCDD");
  ck_assert_str_eq(s21_to_upper("123"), "123");
}

END_TEST

START_TEST(s21_to_lower_test) {
  char str[] = "Hello World!";
  ck_assert_str_eq(s21_to_lower(str), "hello world!");
  ck_assert_str_eq(s21_to_lower("AaBbCcDd"), "aabbccdd");
  ck_assert_str_eq(s21_to_lower("123"), "123");
}

END_TEST

START_TEST(s21_insert_test) {
  char *s1 = "Hello", *s2 = "world";
  ck_assert_str_eq(s21_insert(s1, s2, 2), "Heworldllo");
  ck_assert_ptr_null(s21_insert(s21_NULL, s2, 2));
  ck_assert_str_eq(s21_insert(s1, s2, 0), "worldHello");
}

END_TEST

START_TEST(s21_trim_test) {
  char *s1 = "---Hello-World----", *s2 = "aaaworldabaaabba";
  ck_assert_str_eq(s21_trim(s1, "-"), "Hello-World");
  ck_assert_str_eq(s21_trim(s2, "a"), "worldabaaabb");
}

END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, memcmp1);
  tcase_add_test(tc1_1, memcmp2);
  tcase_add_test(tc1_1, memcmp3);
  tcase_add_test(tc1_1, memcmp4);
  tcase_add_test(tc1_1, memcmp5);
  tcase_add_test(tc1_1, memcmp6);
  tcase_add_test(tc1_1, memcmp7);
  tcase_add_test(tc1_1, memcmp8);
  tcase_add_test(tc1_1, memcmp9);
  tcase_add_test(tc1_1, memcmp10);
  tcase_add_test(tc1_1, memcmp11);
  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, s21_strerror_test);
  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, s21_strtok_test);

  tcase_add_test(tc1_1, test_s21_sprintf_с);
  tcase_add_test(tc1_1, test_s21_sprintf_d_1);
  tcase_add_test(tc1_1, test_s21_sprintf_d_2);
  tcase_add_test(tc1_1, test_s21_sprintf_i);
  tcase_add_test(tc1_1, test_s21_sprintf_e_1);
  tcase_add_test(tc1_1, test_s21_sprintf_e_2);
  tcase_add_test(tc1_1, test_s21_sprintf_f_1);
  tcase_add_test(tc1_1, test_s21_sprintf_f_2);
  tcase_add_test(tc1_1, test_s21_sprintf_g_G);
  tcase_add_test(tc1_1, test_s21_sprintf_o_1);
  tcase_add_test(tc1_1, test_s21_sprintf_o_2);
  tcase_add_test(tc1_1, test_s21_sprintf_s_1);
  tcase_add_test(tc1_1, test_s21_sprintf_s_2);
  tcase_add_test(tc1_1, test_s21_sprintf_u_1);
  tcase_add_test(tc1_1, test_s21_sprintf_u_2);
  tcase_add_test(tc1_1, test_s21_sprintf_x_1);
  tcase_add_test(tc1_1, test_s21_sprintf_x_2);
  tcase_add_test(tc1_1, test_s21_sprintf_x_3);
  tcase_add_test(tc1_1, test_s21_sprintf_x_4);
  tcase_add_test(tc1_1, test_s21_sprintf_x_X);
  tcase_add_test(tc1_1, test_s21_sprintf_p_1);
  tcase_add_test(tc1_1, test_s21_sprintf_p_2);
  tcase_add_test(tc1_1, test_s21_sprintf_flags);
  tcase_add_test(tc1_1, test_s21_sprintf_width);
  tcase_add_test(tc1_1, test_s21_sprintf_length);
  tcase_add_test(tc1_1, test_s21_sprintf_precision);

  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);
  srunner_run_all(sr, CK_ENV);
  srunner_free(sr);
  return 0;
}
