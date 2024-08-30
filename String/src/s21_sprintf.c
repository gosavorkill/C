#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *start = str;
  va_list ap;
  va_start(ap, format);
  int i = 0;
  while (*format) {
    if (*format != '%') {
      i += s21_putchar(start, *format);
      start++;
      format++;
    } else {
      flags_t flags = parseFlags((char *)format, &ap);
      if (flags.flagSize) format += flags.flagSize;
      format++;
      int b = checkFormat(start, *format, &ap, flags);
      i += b;
      start += b;
      format++;
    }
  }
  va_end(ap);
  str[i] = '\0';
  return i;
}

int s21_putchar(char *str, int ap) {
  *str = ap;
  return 1;
}

int isNumFormat(char format) {
  return (format == 'd' || format == 'f' || format == 'u' || format == 'x' ||
          format == 'X' || format == 'o' || format == 'e' || format == 'E' ||
          format == 'g' || format == 'G');
}

int s21_putstr(char *str, char *ap, flags_t flags) {
  s21_size_t size = s21_strlen(ap);
  if (flags.percision == -1) flags.percision = size;
  int i = 0;
  while (ap[i] && i < flags.percision) {
    s21_putchar(str, ap[i]);
    str++;
    i++;
  }
  return i;
}

int s21_putEFG(char *str, long double num, flags_t flags, int flagCase,
               int format) {
  char *numStr = s21_NULL;
  flags.percision = flags.percision == -1 ? 6 : flags.percision;
  if (flags.width) flags.width -= (flags.plus || flags.space);
  if (flags.minus) flags.minus -= (flags.plus || flags.space);
  if (format == 1) {
    numStr = ftoa(num, flags.percision);
  } else if (format == 2) {
    numStr = doubleToExp(num, flags.percision, flagCase);
  } else {
    numStr = doubleToFormat(num, flags.percision, flagCase);
  }
  flags.percision = -1;
  return numUtil(str, numStr, flags, num);
}

int s21_putnbr(char *str, long long int num, flags_t flags) {
  int i = 0;
  if (flags.width)
    flags.width -= ((flags.plus && num > 0) || (flags.space && num > 0));
  if (flags.minus) flags.minus -= (flags.plus != 0 || (flags.space));  //
  char *numStr = s21_itoa(num);
  if (flags.zero && flags.percision > 2 && flags.width) flags.zero = 0;
  int s = s21_strlen(numStr);
  if (s > flags.percision && flags.percision <= flags.width &&
      flags.percision != -1) {
    flags.percision = flags.width;
  }
  if (flags.percision < s && s > flags.width && num != 0) {
    flags.percision = s;
    flags.width = s;
  }
  return numUtil(str, numStr, flags, num) + i;
}

int s21_puthex(char *str, long long int num, int flagCase, flags_t flags,
               int flagBase) {
  flags_t tmp = {};
  tmp.percision = -1;
  flags.isHex = 1 + flagCase;
  int i = 0;
  flags.plus = 0;
  flags.space = 0;
  char *numStr = s21_intToHexOrOct(num, flagCase, flagBase);
  if (flags.tag && flags.width > 2) {
    if (flagBase)
      flags.width -= 2;
    else
      flags.width -= 1;
  }
  str += i;
  if ((flags.tag && !flags.width) || (flags.tag && flags.zero)) {
    if (flagCase) {
      i += s21_putstr(str, "0X", tmp);
    } else {
      if (flagBase)
        i += s21_putstr(str, "0x", tmp);
      else
        i += s21_putstr(str, "0", tmp);
    }
    str += i;
  }
  flags.isHex = flagBase ? flags.isHex : 3;
  if (!flagBase && flags.tag && flags.percision) flags.percision -= 1;
  return numUtil(str, numStr, flags, num) + i;
}

int s21_putunbr(char *str, unsigned long long int num, flags_t flags) {
  int i = 0;
  char *numStr = s21_utoa(num);
  i += putZeros(str, flags.percision, numStr);
  str += i;
  flags.percision = -1;
  return numUtil(str, numStr, flags, num);
}

int countNum(char *str) {
  int count = 0;
  while (isdigit(*(str++))) {
    count++;
  }
  return count;
}

int subAtoi(char *str, int count) {
  char substr[20];
  int num = 0;
  for (int i = 0; i < count && i < 20; i++) {
    substr[i] = *str;
    str++;
  }
  substr[count] = '\0';
  num = atoi(substr);
  return num;
}

int isNotSpec(char symbol) {
  int isSpec = 1;
  if (symbol == 'c' || symbol == '%' || symbol == 's' || symbol == 'i' ||
      symbol == 'd' || symbol == 'f' || symbol == 'u' || symbol == 'x' ||
      symbol == 'X' || symbol == 'p' || symbol == 'o' || symbol == 'E' ||
      symbol == 'e' || symbol == 'g' || symbol == 'G')
    isSpec = 0;
  return isSpec;
}

flags_t parseFlags(char *format, va_list *ap) {
  format++;
  flags_t flags = {0};
  flags.percision = -1;
  int numSize = 0;
  while (format && isNotSpec(*format)) {
    switch (*format) {
      case '+':
        flags.plus = 1;
        flags.flagSize++;
        break;
      case '-':
        if (*(format + 1) != '*') {
          if (*(format + 1) == '+') {
            flags.plus = 1;
            format += 1;
            flags.flagSize += 1;
          } else if (*(format + 1) == ' ') {
            flags.space = 1;
            format++;
            flags.flagSize++;
          }
          format += numFromFormat(&flags.minus, &flags.flagSize, format);
        } else {
          flags.minus = va_arg(*ap, int);
          format++;
          flags.flagSize += 2;
        }
        break;

      case '.':
        if (*(format + 1) != '*') {
          format += numFromFormat(&flags.percision, &flags.flagSize, format);
        } else {
          flags.percision = va_arg(*ap, int);
          format++;
          flags.flagSize += 2;
        }
        break;
      case ' ':
        flags.space = 1;
        flags.flagSize++;
        break;
      case '*':
        flags.width = va_arg(*ap, int);
        flags.flagSize += 1;
        break;
      case 'l':
        flags.l = 1;
        flags.flagSize += 1;
        break;
      case 'h':
        flags.h = 1;
        flags.flagSize += 1;
        break;
      case 'L':
        flags.L = 1;
        flags.flagSize += 1;
        break;
      case '#':
        flags.tag = 1;
        flags.flagSize += 1;
        break;
      case '0':
        flags.zero = 1;
        flags.flagSize += 1;
        break;
      default:
        if (isdigit(*format)) {
          numSize = countNum(format);
          flags.width = subAtoi(format, numSize);
          format += numSize;
          flags.flagSize += numSize;
          format--;
        }
        break;
    }
    format++;
  }
  return flags;
}

int checkFormat(char *str, char format, va_list *ap, flags_t flags) {
  int i = 0;
  char *arg;
  if (format == 'i') format = 'd';
  switch (format) {
    case 'c':
      i = s21_putchar(str, va_arg(*ap, int));
      break;
    case 's':
      arg = va_arg(*ap, char *);
      if (flags.width)
        str += widthFlags(str, arg, flags.width, &i, flags.percision);
      i += s21_putstr(str, arg, flags);
      if (flags.minus) {
        str += i;
        str += widthFlags(str, arg, flags.minus, &i, flags.percision);
      }
      break;
    case '%':
      i = s21_putchar(str, '%');
      break;
    case 'p':
      flags.tag = 1;
      i = s21_puthex(str, va_arg(*ap, unsigned long long), 0, flags, 1);
      break;
    default:
      if (isNumFormat(format)) {
        i = callPutsNumFunc(format, str, flags, ap);
      } else
        i = s21_putchar(str, format);
      break;
  }
  return i;
}

char *s21_utoa(unsigned long long int value) {
  char *str = s21_NULL;
  if (value == 0) {
    str = (char *)malloc(2 * sizeof(char));
    if (str != s21_NULL) {
      str[0] = '0';
      str[1] = '\0';
    }
  } else {
    int num_digits = 0;
    unsigned long long int temp = value;

    while (temp > 0) {
      temp /= 10;
      num_digits++;
    }

    str = (char *)malloc((num_digits + 1) * sizeof(char));
    if (str != s21_NULL) {
      str += num_digits;
      *str = '\0';

      while (value > 0) {
        *(--str) = '0' + (value % 10);
        value /= 10;
      }
    }
  }
  return str;
}

int widthFlags(char *str, char *strNum, int countSpace, int *i, int percision) {
  int s = s21_strlen(strNum);
  int size = percision == -1 ? s : percision;
  if (countSpace && countSpace > size) {
    for (int f = 0; f < countSpace - size; f++) {
      str += s21_putchar(str, ' ');
      *i += 1;
    }
  } else {
    countSpace = size;
  }
  return countSpace - size;
}

int putZeros(char *str, int percision, char *numStr) {
  int i = 0;
  s21_size_t s = s21_strlen(numStr);
  if (percision != -1 && (int)s <= percision) {
    while (i < percision - (int)s) {
      i += s21_putchar(str, '0');
      str += 1;
    }
  }
  return i;
}

int numWorkWithFlags(char *str, long long int num, flags_t flags, int *i) {
  int flag = 0;
  flags.percision = -1;
  if (num > 0 && flags.space) {
    *i += s21_putstr(str, " ", flags);
    flag = 1;
  } else if (num > 0 && flags.plus) {
    *i += s21_putstr(str, "+", flags);
    flag = 1;
  }
  return flag;
}

int numUtil(char *str, char *numStr, flags_t flags, long long int num) {
  int i = 0;
  if (numStr != s21_NULL) {
    if (flags.space) str += numWorkWithFlags(str, num, flags, &i);
    if (flags.width && !flags.zero && !flags.isHex)
      str += widthFlags(str, numStr, flags.width, &i, flags.percision);
    else if (flags.width && !flags.zero && flags.isHex)
      str += widthFlags(str, numStr, flags.width, &i, flags.percision);
    if ((flags.zero && flags.width && !flags.isHex) ||
        (!flags.percision && flags.isHex) ||
        (flags.zero && flags.width && flags.isHex && flags.percision == -1)) {
      int a = putZeros(str, flags.width, numStr);
      i += a;
      str += a;
    }
    if (flags.isHex && flags.tag && flags.width && !flags.zero) {
      int a = 0;
      if (flags.isHex == 1)
        a = s21_putstr(str, "0x", flags);
      else if (flags.isHex == 2)
        a = s21_putstr(str, "0X", flags);
      else
        a = s21_putstr(str, "0", flags);
      i += a;
      str += a;
    }
    if (flags.plus) str += numWorkWithFlags(str, num, flags, &i);
    if (flags.percision > 0) {
      int a = putZeros(str, flags.percision, numStr);
      i += a;
      str += a;
    }
    int a = s21_putstr(str, numStr, flags);
    i += a;
    if (flags.minus) {
      str += a;
      if (flags.tag) {
        if (flags.isHex != 3)
          flags.minus -= 2;
        else
          flags.minus -= 1;
      }
      str += widthFlags(str, numStr, flags.minus, &i, flags.percision);
    }
    free(numStr);
  } else {
    i += s21_putstr(str, "(null)", flags);
  }
  return i;
}

void *parseVaArg(flags_t flags, char format, va_list *ap) {
  void *arg = s21_NULL;
  switch (format) {
    case 'd':
    case 'x':
    case 'X':
    case 'o': {
      long long int *i = malloc(sizeof(long long int));
      if (flags.h)
        *i = (long long int)(short int)va_arg(*ap, int);
      else if (flags.l)
        *i = va_arg(*ap, long long int);
      else if (!flags.L)
        *i = (long long int)va_arg(*ap, int);
      arg = i;
      break;
    }
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G': {
      long double *d = malloc(sizeof(long double));
      if (!flags.L)
        *d = (long double)va_arg(*ap, double);
      else
        *d = va_arg(*ap, long double);
      arg = d;
      break;
    }
    case 'u': {
      unsigned long long int *u = malloc(sizeof(unsigned long long int));
      *u = va_arg(*ap, unsigned long long int);
      arg = u;
      break;
    }
    default:
      arg = &format;
      break;
  }
  return arg;
}

int callPutsNumFunc(char format, char *str, flags_t flags, va_list *ap) {
  int i = 0;
  void *a = s21_NULL;
  a = parseVaArg(flags, format, ap);
  switch (format) {
    case 'd':
      if (flags.percision > 0 && flags.width <= flags.percision &&
          *(long long int *)a < 0) {
        flags.space = 0;
        i += 1;
        str += s21_putchar(str, '-');
        *(long long int *)a *= -1;
        flags.plus = 0;
      }
      i += s21_putnbr(str, *(long long int *)a, flags);
      break;
    case 'f':
      i = s21_putEFG(str, *(long double *)a, flags, 0, 1);
      break;
    case 'u':
      i = s21_putunbr(str, *(unsigned long long int *)a, flags);
      break;
    case 'x':
      i = s21_puthex(str, *(long long int *)a, 0, flags, 1);
      break;
    case 'X':
      i = s21_puthex(str, *(long long int *)a, 1, flags, 1);
      break;
    case 'o':
      i = s21_puthex(str, *(long long int *)a, 0, flags, 0);
      break;
    case 'e':
      i = s21_putEFG(str, *(long double *)a, flags, 0, 2);
      break;
    case 'E':
      i = s21_putEFG(str, *(long double *)a, flags, 1, 2);
      break;
    case 'g':
      i = s21_putEFG(str, *(long double *)a, flags, 0, 3);
      break;
    case 'G':
      i = s21_putEFG(str, *(long double *)a, flags, 1, 3);
      break;
    default:
      i = s21_putchar(str, *(char *)a);
      break;
  }
  if (format != 'c') free(a);
  return i;
}

int numFromFormat(int *changeValue, int *flagSize, char *format) {
  format++;
  int numSize = 0;
  if (*format != '*') {
    numSize = countNum(format);
    *changeValue = subAtoi(format, numSize);
    *flagSize += numSize + 1;
    format += numSize;
  }
  return numSize;
}

char *s21_intToHexOrOct(long long int num, int flagFont, int flagBase) {
  int size = 0;
  long long int temp = num;
  int base = flagBase ? 16 : 8;
  if (temp < 0) {
    temp = (unsigned int)temp;
    num = (unsigned int)temp;
  }

  if (temp == 0) {
    size = 1;
  } else {
    while (temp != 0) {
      size++;
      temp = temp / base;
    }
  }

  char *str = (char *)malloc(size * sizeof(char) + 1);

  if (str != s21_NULL) {
    int index = size - 1;

    if (num == 0) {
      str[index] = '0';
    } else {
      while (num != 0) {
        int digit = num % base;

        if (digit < 10) {
          str[index] = '0' + digit;
        } else {
          if (flagFont == 1) {
            str[index] = 'A' + digit - 10;
          } else {
            str[index] = 'a' + digit - 10;
          }
        }

        index--;
        num = num / base;
      }
    }

    str[size] = '\0';
  }

  return str;
}

int s21_sizen(long long int n) {
  int size = 0;
  if (n == 0)
    return (1);
  else if (n == -__LONG_LONG_MAX__)
    return (20);
  else if (n < 0) {
    size++;
    n = n * -1;
  }
  while (n > 0) {
    n = n / 10;
    size++;
  }
  return size;
}

char *s21_nbrstr(char *res, int i, long long int n) {
  res[i--] = 0;
  if (n == 0)
    res[i] = '0';
  else if (n < 0) {
    res[0] = '-';
    if (n == -2147483648) {
      res[1] = '2';
      n = 147483648;
    } else
      n = n * -1;
  }
  while (n > 0) {
    res[i] = n % 10 + '0';
    n /= 10;
    i--;
  }
  return (res);
}

char *s21_itoa(long long int n) {
  int i = s21_sizen(n);
  char *res = {0};
  res = (char *)malloc(sizeof(char) * (i + 2));
  if (res) {
    res[i] = '\0';
    res = s21_nbrstr(res, i, n);
  }
  return (res);
}

int zeroCounter(double num, int percision) {
  int count = 0;
  if (num < 0) num = -num;
  num *= 10;
  while (num < 0.99999991 && count < percision) {
    num *= 10;
    count++;
  }
  return count;
}

char *ftoa(long double num, int percision) {
  flags_t flags = {};
  flags.percision = percision;
  if (percision == 0) num = llroundl(num);
  long long int intPart = (long long int)num;
  long double floatPart = (long double)num - intPart;
  char *startPos = s21_NULL;
  if (floatPart < 0) floatPart *= -1;

  floatPart *= powl(10, percision);
  floatPart = llroundl(floatPart);
  if (floatPart >= powl(10, percision)) {
    floatPart = 0;
    intPart++;
  }
  if (floatPart >= __LDBL_MAX__) {
    floatPart = 0;
    percision = 0;
  }

  if (num < 0 && intPart == 0) intPart = -1;

  char *strIntPart = s21_itoa(intPart);
  char *strFloatPart = s21_itoa(floatPart);
  if (strIntPart != s21_NULL && strFloatPart != s21_NULL) {
    s21_size_t size = s21_strlen(strIntPart);
    if (intPart == -1 && num < 0 && num > -1) {
      size += 1;
      percision -= 1;
      strIntPart[1] = '0';
    }
    char *strNum = (char *)malloc((size + percision + 2) * sizeof(char));
    if (strNum != s21_NULL) {
      int zeroCount = zeroCounter(num - (int)num, percision);
      flags.percision = -1;
      int i = s21_putstr(strNum, strIntPart, flags);
      startPos = strNum;
      if (floatPart == 0) zeroCount = percision - 1;
      if (percision != 0) {
        strNum += i;
        *strNum = '.';
        while (zeroCount >= 1) {
          strNum++;
          *strNum = '0';
          zeroCount--;
        }
        i = s21_putstr(++strNum, strFloatPart, flags);
      }
      strNum[i] = '\0';
      free(strIntPart);
      free(strFloatPart);
    } else if (strIntPart != s21_NULL) {
      free(strIntPart);
    } else if (strFloatPart != s21_NULL) {
      free(strFloatPart);
    }
  }
  return startPos;
}

long double s21_rountlf(long double num, int precision) {
  if (precision == 0) num = llroundl(num);
  long long int intPart = (long long int)num;
  long double floatPart = (long double)num - intPart;
  if (floatPart < 0) floatPart *= -1.0;

  floatPart *= powl(10, precision);
  floatPart = llroundl(floatPart);
  if (floatPart >= powl(10, precision)) {
    floatPart = 0;
    intPart++;
  }
  if (floatPart >= __LDBL_MAX__) {
    floatPart = 0;
    precision = 0;
  }
  floatPart = floatPart / powl(10, precision);
  floatPart += 0.000000000001;
  return (long double)intPart + floatPart;
}

int intLength(long double number) {
  int size = 0;
  if (number == 0) {
    size = 1;
  } else if (number < 0) {
    number = -number;
  }
  if (number != 0) size = (int)log10(number) + 1;

  return size;
}

char *doubleToExp(long double number, int precision, int flagCase) {
  number = s21_rountlf(number, precision);
  int sign = (number < 0) ? -1 : 1;
  number *= sign;
  int exponent = 0;

  while (number >= 10) {
    number /= 10;
    exponent++;
  }

  int intDigits = intLength(number);
  int totalLength = intDigits + precision + 3;
  if (sign == -1) {
    totalLength++;
  }

  char *buffer = (char *)malloc((totalLength + 3) * sizeof(char));
  if (buffer != s21_NULL) {
    int index = 0;
    if (sign == -1) {
      buffer[index++] = '-';
    }
    buffer[index++] = '0' + (int)number;

    if (precision > 0) {
      buffer[index++] = '.';
      number -= (int)number;
      while (precision > 0) {
        number *= 10;
        int digit = (int)number;
        number -= digit;
        buffer[index++] = '0' + digit;
        precision--;
      }
    }

    if (flagCase) {
      buffer[index++] = 'E';
    } else {
      buffer[index++] = 'e';
    }
    if (exponent >= 0) {
      buffer[index++] = '+';
    } else {
      buffer[index++] = '-';
      exponent = -exponent;
    }
    buffer[index++] = '0' + (exponent / 10);
    buffer[index++] = '0' + (exponent % 10);

    buffer[index] = '\0';
  }
  return buffer;
}

int countNumInt(int num) {
  int count = 0;
  while (num > 0) {
    num /= 10;
    count++;
  }
  return count;
}

char *removeLastZeros(char *strNum) {
  char *newStr = s21_NULL;
  int len = s21_strlen(strNum);
  int countZero = 0;
  for (int i = len - 1; i != 0 && strNum[i] == '0'; i--) {
    if (strNum[i] == '0') {
      countZero++;
    }
  }
  newStr = (char *)malloc((sizeof(char)) * (len - countZero + 1));
  for (int i = 0; i < len - countZero; i++) {
    newStr[i] = strNum[i];
  }
  newStr[len - countZero] = '\0';
  free(strNum);
  return newStr;
}

char *gtoa(long double num, int precision) {
  long long int intPart = (long long int)num;
  long double floatPart = num - (long double)intPart;
  char *strNum = (char *)malloc((precision + 3) * sizeof(char));
  int countInt = countNumInt(intPart);
  char *intPartStr = s21_itoa(intPart);
  char *startNum = strNum;
  if (intPartStr != s21_NULL && strNum != s21_NULL) {
    for (int i = 0; i < precision && intPartStr[i] != '\0'; i++) {
      *strNum = intPartStr[i];
      strNum++;
    }
    free(intPartStr);
    if (precision - countInt > 0) {
      *strNum = '.';
      strNum++;
      int countFloatPart = precision - countInt;
      floatPart *= powl(10, countFloatPart);
      floatPart = lroundl(floatPart);
      char *floatPartStr = s21_itoa((long long int)floatPart);
      if (floatPartStr != s21_NULL) {
        for (int i = 0; i < countFloatPart; i++) {
          *strNum = floatPartStr[i];
          strNum++;
        }
        free(floatPartStr);
      }
    }
    *(strNum) = '\0';
  }
  startNum = removeLastZeros(startNum);
  return startNum;
}

char *doubleToFormat(long double number, int precision, int flagCase) {
  if (fabsl(number) < pow(10, -precision) ||
      fabsl(number) >= pow(10, precision)) {
    return doubleToExp(number, precision, flagCase);
  } else {
    return gtoa(number, precision);
  }
}