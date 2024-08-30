#include "s21_grep.h"
int main(int argc, char *argv[]) {
  char think[4096] = {'\0'};
  char template[4096] = {'\0'};
  flags features = {0};
  parsFlag(argc, argv, &features, think);
  int filePattern = 0;
  if (features.f != 1 && features.e != 1)
    snprintf(template, 4096, "%s", argv[optind++]);
  if (features.f != 1 && features.e == 1) snprintf(template, 4096, "%s", think);
  if (features.f == 1) filePattern = readFile(template, think, &features);
  if (filePattern != -1) {
    int countfile = 0;
    if (argc - optind > 1) countfile = 1;
    for (int i = optind; i < argc; i++) {
      grep(&features, template, argv[i], countfile);
    }
  }
  return 0;
}
void parsFlag(int argc, char *argv[], flags *features, char *think) {
  const char *opti = "e:ivclnhsf:o";
  int res = 0;
  int countE = 0;
  while ((res = getopt_long(argc, argv, opti, 0, 0)) != -1) {
    if (res == 'e') {
      if (countE++) strcat(think, "|");
      strcat(think, optarg);
      features->e = 1;
      snprintf(think, 4096, "%s", optarg);
    } else if (res == 'i') {
      features->i = 1;
    } else if (res == 'v') {
      features->v = 1;
    } else if (res == 'c') {
      features->c = 1;
    } else if (res == 'l') {
      features->l = 1;
    } else if (res == 'n') {
      features->n = 1;
    } else if (res == 'h') {
      features->h = 1;
    } else if (res == 's') {
      features->s = 1;
    } else if (res == 'f') {
      features->f = 1;
      snprintf(think, 4096, "%s", optarg);
    } else if (res == 'o') {
      features->o = 1;
    } else {
      if (argc == 2 && argv[1][0] == '-' &&
          (argv[1][1] == 'e' || argv[1][1] == 'f')) {
        printf("grep: option requires an argument -- %c\n", argv[1][1]);
        failPrint();
      } else {
        failPrint();
      }
    }
  }
}
void failPrint() {
  printf("usage: grep [-eivclnhsfo]\n");
  printf("\t[-e pattern] [-f file]\n");
  printf("\t[pattern] [file ...]\n");
}

int readFile(char *template, char *fileName, flags *features) {
  FILE *file = fopen(fileName, "r");
  int i = 0;
  if (file) {
    int ch = 0;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == 13 || ch == 10) {
        template[i++] = '|';
      } else {
        template[i++] = (char)ch;
      }
    }
  } else {
    if (features->s != 1) {
      printf("grep: %s: No such file or directory\n", fileName);
      i = -1;
    }
  }
  if (template[i - 1] == '|') template[i - 1] = '\0';
  fclose(file);
  return i;
}

void grep(flags *features, char *template, char *fileName, int countfile) {
  regex_t reg;
  FILE *file = fopen(fileName, "r");
  int compilation = REG_EXTENDED;
  if (features->i == 1) compilation = REG_ICASE;
  if (file) {
    regcomp(&reg, template, compilation);
    char str[4096];
    regmatch_t pmatch[1];
    int line = 0, number = 1, matchL = 0;
    while (fgets(str, 4095, file) != NULL) {
      int match = 0;
      int result = regexec(&reg, str, 1, pmatch, 0);
      if (strchr(str, '\n') == NULL) strcat(str, "\n");
      if (result == 0 && features->v != 1) {
        match = 1;
        matchL = matchL + 1;
      }
      if (result == REG_NOMATCH && features->v == 1) {
        match = 1;
        matchL = matchL + 1;
      }
      if (match == 1 && features->h != 1 && features->l != 1 &&
          features->c != 1 && countfile == 1)
        printf("%s:", fileName);
      if (match == 1 && features->n == 1 && features->c != 1 &&
          features->l != 1)
        printf("%d:", number);
      if (match == 1 && features->o != 1 && features->l != 1 &&
          features->c != 1)
        printf("%s", str);
      if (match == 1 && features->o == 1) {
        for (int i = (int)pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
          printf("%c", str[i]);
        }
        printf("\n");
      }
      line = line + match;
      number = number + 1;
    }
    if (features->c == 1 && features->l == 1) printf("%s:", fileName);
    if (features->l == 1 && line > 1) line = 1;
    if (features->c == 1) printf("%d\n", line);
    if (features->l && matchL) printf("%s\n", fileName);
    regfree(&reg);
    fclose(file);
  } else {
    if (features->s != 1)
      printf("s21_grep: %s: No such file or directory\n", fileName);
  }
}
