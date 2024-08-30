#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;
#define s21_NULL (void *)0

typedef struct {
  int flagSize;
  int percision;
  int width;
  int plus;
  int space;
  int minus;
  int zero;
  int isHex;
  int tag;
  int l;
  int h;
  int L;
} flags_t;

void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);

char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);

char *s21_strerror(int errnum);

s21_size_t s21_strlen(const char *str);

char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);

int s21_putchar(char *str, int ap);
int isNumFormat(char format);
int s21_putstr(char *str, char *ap, flags_t flags);
int s21_putEFG(char *str, long double num, flags_t flags, int flagCase,
               int format);
int s21_putnbr(char *str, long long int num, flags_t flags);
int s21_puthex(char *str, long long int num, int flagCase, flags_t flags,
               int flagBase);
int s21_putunbr(char *str, unsigned long long int num, flags_t flags);
int countNum(char *str);
int subAtoi(char *str, int count);
int isNotSpec(char symbol);
flags_t parseFlags(char *format, va_list *ap);
int checkFormat(char *str, char format, va_list *ap, flags_t flags);
char *s21_utoa(unsigned long long int value);
int widthFlags(char *str, char *strNum, int countSpace, int *i, int percision);
int putZeros(char *str, int percision, char *numStr);
int numWorkWithFlags(char *str, long long int num, flags_t flags, int *i);
int numUtil(char *str, char *numStr, flags_t flags, long long int num);
void *parseVaArg(flags_t flags, char format, va_list *ap);
int callPutsNumFunc(char format, char *str, flags_t flags, va_list *ap);
int numFromFormat(int *changeValue, int *flagSize, char *format);
char *s21_intToHexOrOct(long long int num, int flagFont, int flagBase);
int s21_sizen(long long int n);
char *s21_nbrstr(char *res, int i, long long int n);
char *s21_itoa(long long int n);
int zeroCounter(double num, int percision);
char *ftoa(long double num, int percision);
long double s21_rountlf(long double num, int precision);
int intLength(long double number);
char *doubleToExp(long double number, int precision, int flagCase);
int countNumInt(int num);
char *removeLastZeros(char *strNum);
char *gtoa(long double num, int precision);
char *doubleToFormat(long double number, int precision, int flagCase);

void *s21_to_upper(const char *str);

void *s21_to_lower(const char *str);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);

#endif