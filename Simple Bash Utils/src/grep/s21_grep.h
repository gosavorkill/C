#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
typedef struct Options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} flags;
void parsFlag(int argc, char *argv[], flags *Options, char *think);
int readFile(char *template, char *filename, flags *Options);
void grep(flags *Options, char *template, char *fileName, int fileCount);
void failPrint();
#endif
