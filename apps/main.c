#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll/dll.h"
#include "dll/node.h"

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
static int process_line(linkedlist_t *ll, char *line) {
  printf("line: %s\n", line);
  char cmd[LINESZ];
  if(strncmp(line, "isempty", sizeof("isempty") - 1) == 0) {
    printf("%b\n", isempty_LinkedList(ll));
    line = line + sizeof("isempty");
    if(__builtin_expect(line[0] == '\0', true)) return EXIT_SUCCESS;
    fprintf(stderr, "unmatched input: %s\n", line);
  }
  if(strncmp(line, "find", sizeof("find") - 1) == 0) {
    element_t elem;
    sscanf(line+sizeof("find"), "%d", &elem); // TODO error check
    printf("%d\n", find_LinkedList(ll, elem)); // TODO ssize_t
    line = line + sizeof("find");
    if(__builtin_expect(line[0] == '\0', true)) return EXIT_SUCCESS;
    fprintf(stderr, "unmatched input: %s\n", line);
  }
  if(strncmp(line, "get", sizeof("get") - 1) == 0) {
    size_t ndx;
    sscanf(line, "%u", &ndx); // TODO error check, size_t
    printf("%d\n", get_LinkedList(ll, ndx));
    line = line + sizeof("get");
    if(__builtin_expect(line[0] == '\0', true)) return EXIT_SUCCESS;
    fprintf(stderr, "unmatched input: %s\n", line);
  }
  if(strncmp(line, "insert", sizeof("insert") - 1) == 0) {
    element_t elem;
    ssize_t   e;
    sscanf(line, "%d", &elem); // TODO error check
    e = insert_LinkedList(ll, elem);
    if(__builtin_expect(e == -1, false)) {
      fprintf(stderr, "failed to insert element: %d\n", elem);
      return e;
    }
    line = line + sizeof("insert");
    if(__builtin_expect(line[0] == '\0', true)) return EXIT_SUCCESS;
    fprintf(stderr, "unmatched input: %s\n", line);
  }
  if(strncmp(line, "remove", sizeof("remove") - 1) == 0) {
    size_t ndx;
    sscanf(line, "%u", &ndx); // TODO error check, size_t
    printf("%d\n", remove_LinkedList(ll, ndx));
    line = line + sizeof("remove");
    if(__builtin_expect(line[0] == '\0', true)) return EXIT_SUCCESS;
    fprintf(stderr, "unmatched input: %s\n", line);
  }
  fprintf(stderr, "unrecognized command: %s\n", line);
  return EXIT_FAILURE;
}

/**
 * @param file
 * @returns non-zero on error
 */
static int process_file(linkedlist_t *ll, FILE *file) {
  int e;
  char line[LINESZ];
  while(fgets(line, sizeof(line), file)) {
    e = process_line(ll, line);
    if(__builtin_expect(e == EXIT_SUCCESS, true)) continue;
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
  int e;
  FILE **files = (FILE **) malloc(argc * sizeof(FILE *));
  FILE  *file;
  if(__builtin_expect(malloc == NULL, false)) {
    fputs("failed to allocate memory for FILE pointer array", stderr);
    return EXIT_FAILURE;
  }
  e = init_files(files, argc, argv);
  if(__builtin_expect(e != EXIT_SUCCESS, false)) {
    fputs("failed to initialize FILE pointer array", stderr);
    free(files);
    return e;
  }
  for(i = 0; i < argc; i++) {
    const int e = process_file(&ll, files[i]);
    if(__builtin_expect(e == EXIT_SUCCESS, true)) continue;
    fprintf(stderr, "failed to process file: %s\n", argv[i+1]);
    deinit_files(files, argc);
    free(files);
    return e;
  }
  e = deinit_files(files, argc);
  if(__builtin_expect(e != EXIT_SUCCESS, false)) {
    fputs("failed to deinitialize FILE pointer array", stderr);
    free(files);
    return e;
  }
  free(files);
  return EXIT_SUCCESS;
}

