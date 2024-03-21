struct gopt {
  int argc;
  char ** argv;
  const char * format;
};

int gopt_parse(struct gopt * opts, const char ** argvalue) {
  return -1;
}

#include <stdio.h>

int usage(const char * argv0) {
  fprintf(stderr, "Usage: %s [-b] [-f file] name\n", argv0);
  return 1;
}

int main(int argc, char ** argv) {
  struct gopt opts;
  opts.argc = argc;
  opts.argv = argv;
  opts.format = "bf:";

  const char *value;

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

  printf("bflag = %d\nfflag = [%s]\nname = [%s]\n", bflag, fflag, opts.argv[0]);
  return 0;
}
