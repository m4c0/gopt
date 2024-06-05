#pragma leco tool
#include <stdio.h>

import gopt;

void usage(const char *argv0) {
  fprintf(stderr, "Usage: %s [-b] [-f file] -- name\n", argv0);
  throw 0;
}

int main(int argc, char **argv) try {
  int bflag = 0;
  const char *fflag = "";

  auto opts = gopt_parse(argc, argv, "bf:", [&](auto ch, auto value) {
    switch (ch) {
    case 'b':
      bflag = 1;
      break;
    case 'f':
      fflag = value;
      break;
    default:
      usage(argv[0]);
      break;
    }
  });

  if (opts.argc != 1)
    usage(argv[0]);

  const char *name = opts.argv[0];

  printf("bflag = %d\nfflag = [%s]\nname = [%s]\n", bflag, fflag, name);
} catch (...) {
  return 1;
}
