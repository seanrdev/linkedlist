#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dll/dll.h"
//#include "dll/node.h"

#define LINESZ (256)

/**
 * @param files
 * @param argc
 * @returns non-zero on error
 */
static int deinit_files(FILE *files[], const int argc) {
  int i, e = EXIT_SUCCESS;
  for(i = 0; i < argc; i++) {
    const int f = fclose(files[i]);
    if(__builtin_expect(f != 0, false)) fprintf(stderr, "failed to deinitialize FILE pointer\n");
    e |= f;
  }
  return e;
}

/**
 * @param files
 * @param argc
 * @param argv
 * @returns non-zero on error
 */
static int init_files(FILE *files[], const int argc, const char *const argv[]) {
  int i;
  if(argc == 1) {
    files[0] = stdin;
    return EXIT_SUCCESS;
  }
  for(i = 1; i < argc; i++) {
    files[i-1] = fopen(argv[i], "r");
    if(__builtin_expect(files[i-1] != NULL, true)) continue;
    fprintf(stderr, "failed to initialize FILE pointer for file: %s\n", argv[i]);
    return EXIT_FAILURE | deinit_files(files, i);
  }
  return EXIT_SUCCESS;
}

/**
 * @param line
 * @returns non-zero on error
 */
static int process_line(char *line) {
  //bool        isempty_LinkedList(linkedlist_t *ll);
  //ssize_t        find_LinkedList(linkedlist_t *ll, element_t elem);
  //element_t      *get_LinkedList(linkedlist_t *ll, size_t ndx);
  //ssize_t      insert_LinkedList(linkedlist_t *ll, element_t elem);
  //element_t    remove_LinkedList(linkedlist_t *ll, size_t ndx);
  printf("line: %s\n", line);
  return EXIT_SUCCESS;
}

/**
 * @param file
 * @returns non-zero on error
 */
static int process_file(FILE *file) {
  int e;
  char line[LINESZ];
  while(fgets(line, sizeof(line), file)) {
    e = process_line(line);
    if(__builtin_expect(e == 0, true)) continue;
    fprintf(stderr, "failed to process line: %s\n", line);
    return e;
  }
  e = ferror(file);
  if(__builtin_expect(e != 0, false)) {
    fputs("error reading input", stderr);
    return e;
  }
  assert(feof(file) != 0);
  return EXIT_SUCCESS;
}

/**
 * demonstrates the LinkedList library
 * @param argc number of arguments >= 1
 * @param argv file paths from which to read arguments, stdin otherwise
 * @returns non-zero on error
 */
int main(const int argc, const char *const argv[]) {
  linkedlist_t ll;
  size_t i;
  FILE **files = (FILE **) malloc(argc * sizeof(FILE *));
  FILE  *file;
  if(__builtin_expect(malloc == NULL, false)) {
    fputs("failed to allocate memory for FILE pointer array", stderr);
    return EXIT_FAILURE;
  }
  init_files(files, argc, argv);
  for(i = 0; i < argc; i++) {
    const int e = process_file(files[i]);
    if(__builtin_expect(e == 0, true)) continue;
    fprintf(stderr, "failed to process file: %s\n", argv[i+1]);
    return e;
  }
  deinit_files(files, argc);
  free(files);
  return EXIT_SUCCESS;
}

