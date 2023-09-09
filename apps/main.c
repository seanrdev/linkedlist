#include <stdio.h>
#include <stdlib.h>
#include "dll/dll.h"
#include "dll/node.h"

/**
 * @param files
 * @param argc
 * @returns non-zero on error
 */
static int deinit_files(FILE *files[], const int argc) {
  int i, e = 0;
  for(i = 0; i < argc; i++) e |= fclose(files[i]);
  return e;
}

/**
 * @param files
 * @param argi
 * @param argv
 * @returns non-zero on error
 */
static int init_file(FILE *files[], const int argi, const char *const argv[]) {
  int j, e = 0;
  files[argi-1] = fopen(argv[argi], "r");
  if(__builtin_expect(files[argi-1] != NULL, true)) return 0;
  return EXIT_FAILURE | deinit_files(files, argi);
}

/**
 * @param files
 * @param argc
 * @param argv
 * @returns non-zero on error
 */
static int init_files(FILE *files[], const int argc, const char *const argv[]) {
  int i, e;
  if(argc == 1) {
    files[0] = stdin;
    return 0;
  }
  for(i = 1; i < argc; i++) {
    e = init_file(files, i, argv);
    if(__builtin_expect(e != 0, false)) {
      fprintf(stderr, "failed to initialize FILE pointer for file: %s\n", argv[i]);
      return e;
    }
  }
  return 0;
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
    file = files[i];
    //readlines(file);
  }

  //bool        isempty_LinkedList(linkedlist_t *ll);
  //ssize_t        find_LinkedList(linkedlist_t *ll, element_t elem);
  //element_t      *get_LinkedList(linkedlist_t *ll, size_t ndx);
  //ssize_t      insert_LinkedList(linkedlist_t *ll, element_t elem);
  //element_t    remove_LinkedList(linkedlist_t *ll, size_t ndx);
  deinit_files(files, argc);
  free(files);
  return EXIT_SUCCESS;
}

