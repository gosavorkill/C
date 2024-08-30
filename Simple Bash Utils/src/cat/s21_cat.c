#include "s21_cat.h"
int main(int argc, char *argv[]) {
  struct flags features = {0};
  int sum = parsLongFlag(argc, argv, &features);
  int sum2 = parsShortFlag(argc, argv, &features);
  if (sum != 100 || sum2 != 100) {
    for (int i = 1; i < argc; ++i) {
      if (argv[i][0] != '-') {
        File_open(argv[i], features);
      }
    }
  }
  return (0);
}
int parsLongFlag(int argc, char *argv[], struct flags *features) {
  int sum_flags = 0;
  char fault;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] == '-') {
      if (strcmp("--number-nonblank", argv[i]) == 0) {
        features->b = 1;
        sum_flags = +1;
      } else if ((strcmp("--squeeze-blank", argv[i]) == 0)) {
        features->s = 1;
        sum_flags = +1;
      } else if ((strcmp("--number", argv[i]) == 0)) {
        features->n = 1;
        sum_flags = +1;
      } else {
        fault = argv[i][1];
        printf(
            "cat: illegal option -- %c\nusage: cat[-benstuv] [file "
            "...]\n",
            fault);
        sum_flags = 100;
      }
    }
  }
  return sum_flags;
}
int parsShortFlag(int argc, char *argv[], struct flags *features) {
  int sum_flags = 0;

  for (int i = 1; i < argc - 1; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-' && sum_flags != 100 &&
        argv[1][1] != '-') {
      for (size_t j = 1; j < strlen(argv[i]); ++j) {
        char a = argv[i][j];
        check_flags(a, features, &sum_flags);
      }
    }
  }

  return sum_flags;
}

void File_open(char *name, struct flags features) {
  FILE *file = fopen(name, "rt");
  if (file == NULL) {
    printf("cat: %s: No such file or directory\n", name);
  } else {
    char l;
    struct stroks fun = {0};
    fun.numbering = 1, fun.first = 1, fun.secondary = 1;
    fun.third = 0;
    fun.g = 0;
    l = fgetc(file);
    while (!feof(file)) {
      flag_s(&fun, features, l);
      flag_n(&fun, features);
      flag_b(&fun, features, l);
      flag_e(&fun, features, l);
      flag_t(features, &l);
      flag_v(&fun, features, &l);
      if (fun.third != -1 && fun.g != 1) {
        printf("%c", l);
      }
      fun.first = (l == '\n') ? 1 : 0;
      fun.third = (fun.secondary && l == '\n') ? 1 : 0;
      fun.secondary = (fun.first && l == '\n') ? 1 : 0;
      fun.g = 0;
      l = fgetc(file);
    }
    fclose(file);
  }
}

int flag_v(struct stroks *fun, struct flags features, char *l) {
  if (features.v == 1) {
    int ch = (int)*l;
    if (*l < 0) {
      *l &= 127;
      ch = (int)*l;
      ch += 128;
    }
    if (ch != 9 && ch != 10 && ch < 32) {
      printf("^");
      *l += 64;
    } else if (ch == 127) {
      printf("^");
      *l = '?';
    } else if (ch > 127 && ch < 160) {
      printf("M-^");
      *l = ch - 64;
      if (*l == 'J' && (features.b || features.n)) {
        printf("%c", *l);
        printf("%6d\t", fun->numbering);
        fun->numbering += 1;
        fun->g = 1;
      }
    } else if (ch > 160 && ch <= 255) {
      *l -= 128;
    }
  }
  return (*l);
}
void flag_s(struct stroks *fun, struct flags features, char l) {
  if (features.s == 1 && fun->first && l == '\n') {
    if (fun->third) {
      fun->third = -1;
    }
  }
}

void flag_n(struct stroks *fun, struct flags features) {
  if (features.n == 1 && fun->first && features.b != 1) {
    if (fun->third != -1) {
      printf("%6d\t", fun->numbering++);
    }
  }
}

void flag_b(struct stroks *fun, struct flags features, char l) {
  if (features.b == 1 && fun->first && l != '\n') {
    printf("%6d\t", fun->numbering++);
  }
}

void flag_e(struct stroks *fun, struct flags features, char l) {
  if (features.e == 1 && l == '\n') {
    if (fun->third != -1) {
      printf("$");
    }
  }
}
int flag_t(struct flags features, char *l) {
  if (features.t == 1 && *l == '\t') {
    printf("^");
    *l = 'I';
  }
  return (*l);
}
void check_flags(char a, struct flags *features, int *sum_flags) {
  char fault;
  if (a == 'b' && features->b != 1) {
    features->b = 1;
    (*sum_flags)++;
  } else if (a == 'e') {
    features->e = 1;
    features->v = 1;
    (*sum_flags)++;
  } else if (a == 'n' && features->n != 1) {
    features->n = 1;
    (*sum_flags)++;
  } else if (a == 's' && features->s != 1) {
    features->s = 1;
    (*sum_flags)++;
  } else if (a == 't') {
    features->t = 1;
    features->v = 1;
    (*sum_flags)++;
  } else if (a == 'v') {
    features->v = 1;
    (*sum_flags)++;
  } else if (a == 'E') {
    features->e = 1;
    (*sum_flags)++;
  } else if (a == 'T') {
    features->t = 1;
    (*sum_flags)++;
  } else if ((*sum_flags)++ != 100) {
    fault = a;
    printf(
        "cat: illegal option -- %c\nusage: cat [-benstuv]"
        "[file ...]\n",
        fault);
    (*sum_flags) = 100;
  }
}
