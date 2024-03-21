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

struct gopt {
  int argc;
  char **argv;
  const char *format;
};
int gopt_parse(struct gopt *opts, const char **argvalue);

#ifdef __cplusplus
}
#endif

#ifdef GOPT_IMPLEMENTATION
int gopt_parse(struct gopt *opts, const char **argvalue) { return -1; }
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
