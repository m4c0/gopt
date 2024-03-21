#define GOPT_IMPLEMENTATION
#include "gopt.h"

#include <stdio.h>

int usage(const char * argv0) {
  fprintf(stderr, "Usage: %s [-b] [-f file] name\n", argv0);
  return 1;
}

int main(int argc, char ** argv) {
  struct gopt opts;
  GOPT(opts, argc, argv, "bf:");

  char *value;

  int bflag = 0;
  const char *fflag = "";

  char ch;
  while ((ch = gopt_parse(&opts, &value)) != 0) {
    switch (ch) {
      case 'b':
        bflag = 1;
        break;
      case 'f':
        fflag = value;
        break;
      default:
        return usage(argv[0]);
    }
  }

  if (opts.argc != 1)
    return usage(argv[0]);

  const char *name = opts.argv[0];

  printf("bflag = %d\nfflag = [%s]\nname = [%s]\n", bflag, fflag, name);
  return 0;
}
