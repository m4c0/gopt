// gopt.h
// single-file C wrapper for retrieving the modification time of a file by
// Eduardo Costa
//
// LICENSE - see end of file
//
// to create implementation, add
// #define GOPT_IMPLEMENTATION
// in one C/CPP file that includes this file
//

#ifdef __cplusplus
extern "C" {
#endif

/// Input structure for the option parser.
///
/// Suggested initialisation:
///
/// struct gopt opts;
/// GOPT(opts, argc, argv, "format");
struct gopt {
  /// Number of arguments left in argv
  int argc;
  /// Argument list
  char **argv;
  /// Format describing arguments. Uses a syntax similar to getopt:
  /// one letter for the argument, optionally followed by a colon if it requires
  /// a value.
  /// Example: "bf:" supports a command-line like "-b -f <value>"
  const char *format;
};
#define GOPT(opts, c, v, f)                                                    \
  {                                                                            \
    opts.argc = (c)-1;                                                         \
    opts.argv = (v) + 1;                                                       \
    opts.format = f;                                                           \
  }

/// Parses the next available argument.
///
/// See gopt structure documentation for example on how to initialise "opts".
///
/// "argvalue" is a pointer which will contain the argument value (if required
/// by its format).
///
/// Returns:
/// 0 - if we reach the last argument or "--"
/// -1 - if we reach an invalid argument
/// a character if we reach a valid argument. Its value will be in "argvalue"
int gopt_parse(struct gopt *opts, char **argvalue);

#ifdef __cplusplus
}
#endif

#ifdef GOPT_IMPLEMENTATION
int gopt_parse(struct gopt *opts, char **argvalue) {
  if (opts->argc == 0)
    return 0;

  char *a = opts->argv[0];
  if (a[0] == 0)
    return -1;
  if (a[0] != '-')
    return -1;

  if (a[1] == 0)
    return -1;
  if (a[1] == '-' && a[2] == 0) {
    opts->argc--;
    opts->argv++;
    return 0;
  }

  return -1;
}
#endif // GOPT_IMPLEMENTATION

// MIT License
//
// Copyright (c) 2024 Eduardo Costa
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
