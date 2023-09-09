//#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "dll/node.h"

START_TEST(test_alloc_Node) {
  node_t *node = alloc_Node();
  free_Node(node);
}
END_TEST

START_TEST(test_free_Node) {
  node_t *node = alloc_Node();
  free_Node(node);
}
END_TEST

START_TEST(test_init_Node) {
  node_t node;
  init_Node(&node, &node, &node, -1);
  ck_assert_ptr_eq(node.next, &node);
  ck_assert_ptr_eq(node.prev, &node);
  ck_assert_int_eq(node.element, -1);
}
END_TEST

START_TEST(test_deinit_Node) {
  node_t node;
  node.next    = &node;
  node.prev    = &node;
  node.element = -1;
  deinit_Node(&node);
  ck_assert_ptr_null(node.next);
  ck_assert_ptr_null(node.prev);
  ck_assert_int_eq(node.element, 0);
}
END_TEST

START_TEST(test_setnext_Node) {
  node_t a, b;
  setnext_Node(&a, &b);
  ck_assert_ptr_eq(a.next, &b);
  ck_assert_ptr_eq(b.prev, &a);
}
END_TEST

START_TEST(test_setprev_Node) {
  node_t a, b;
  setprev_Node(&a, &b);
  ck_assert_ptr_eq(a.prev, &b);
  ck_assert_ptr_eq(b.next, &a);
}
END_TEST

Suite *node_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("DLL");

	/* Core test case */
	tc_core = tcase_create("Core");

	//tcase_add_test(tc_core, test_initialize);
	tcase_add_test(tc_core, test_alloc_Node);
	tcase_add_test(tc_core, test_free_Node);

	tcase_add_test(tc_core, test_init_Node);
	tcase_add_test(tc_core, test_deinit_Node);

	tcase_add_test(tc_core, test_setnext_Node);
	tcase_add_test(tc_core, test_setprev_Node);

	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = node_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0)
	? EXIT_SUCCESS : EXIT_FAILURE;
}

