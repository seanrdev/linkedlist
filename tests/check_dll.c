//#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "dll/dll.h"
#include "dll/node.h"

/*
linkedlist_t *alloc_LinkedList();
void           init_LinkedList(linkedlist_t *ll);
void         deinit_LinkedList(linkedlist_t *ll);
void           free_LinkedList(linkedlist_t *ll);
bool        isempty_LinkedList(linkedlist_t *ll);
ssize_t        find_LinkedList(linkedlist_t *ll, element_t elem);
element_t      *get_LinkedList(linkedlist_t *ll, size_t ndx);
ssize_t      insert_LinkedList(linkedlist_t *ll, element_t elem);
element_t    remove_LinkedList(linkedlist_t *ll, size_t ndx);
*/

START_TEST(test_add) {
  //int e = add(NULL, NULL);
  ck_assert_int_eq(0, 0);
  // TODO
}
END_TEST
START_TEST(test_getNode) {
	//int e = getNode(NULL);
	ck_assert_int_eq(0, 0);
	// TODO
}
END_TEST

Suite *dll_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("DLL");

	/* Core test case */
	tc_core = tcase_create("Core");

	//tcase_add_test(tc_core, test_initialize);
	tcase_add_test(tc_core, test_add);
	tcase_add_test(tc_core, test_getNode);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = dll_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0)
	? EXIT_SUCCESS : EXIT_FAILURE;
}

