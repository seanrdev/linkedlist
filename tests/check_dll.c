//#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "dll/dll.h"
#include "dll/node.h"

START_TEST(test_alloc_LinkedList) {
  linkedlist_t *ll = alloc_LinkedList();
  free_LinkedList(ll);
}
END_TEST

START_TEST(test_free_LinkedList) {
  linkedlist_t *ll = alloc_LinkedList();
  free_LinkedList(ll);
}
END_TEST

START_TEST(test_init_LinkedList) {
  linkedlist_t ll;
  init_LinkedList(&ll);
  ck_assert_ptr_null(ll.head);
  ck_assert_ptr_null(ll.tail);
  ck_assert_int_eq(ll.elements, 0);
}
END_TEST

START_TEST(test_deinit_LinkedList_0) {
  linkedlist_t ll;
  init_LinkedList(&ll);
  deinit_LinkedList(&ll);
  ck_assert_ptr_null(ll.head);
  ck_assert_ptr_null(ll.tail);
  ck_assert_int_eq(ll.elements, 0);
}

END_TEST
START_TEST(test_deinit_LinkedList_1) {
  node_t       node;
  linkedlist_t ll;
  init_Node(&node, NULL, NULL, -1);
  ll.head     = &node;
  ll.tail     = &node;
  ll.elements = 1;
  deinit_LinkedList(&ll);
  ck_assert_ptr_null(ll.head);
  ck_assert_ptr_null(ll.tail);
  ck_assert_int_eq(ll.elements, 0);
}
END_TEST

START_TEST(test_deinit_LinkedList_2) {
  node_t       a, b;
  linkedlist_t ll;
  init_Node(&a, &b,   NULL, -1);
  init_Node(&b, NULL, &a,   -2);
  ll.head     = &a;
  ll.tail     = &b;
  ll.elements = 2;
  deinit_LinkedList(&ll);
  ck_assert_ptr_null(ll.head);
  ck_assert_ptr_null(ll.tail);
  ck_assert_int_eq(ll.elements, 0);
}
END_TEST

START_TEST(test_deinit_LinkedList_3) {
  node_t       a, b, c;
  linkedlist_t ll;
  init_Node(&a, &b,   NULL, -1);
  init_Node(&b, &c,   &a,   -2);
  init_Node(&c, NULL, &b,   -3);
  ll.head     = &a;
  ll.tail     = &c;
  ll.elements = 3;
  deinit_LinkedList(&ll);
  ck_assert_ptr_null(ll.head);
  ck_assert_ptr_null(ll.tail);
  ck_assert_int_eq(ll.elements, 0);
}
END_TEST

START_TEST(test_isempty_LinkedList_0) {
  linkedlist_t ll;
  init_LinkedList(&ll);
  ck_assert_true(isempty_LinkedList(&ll));
}
END_TEST

START_TEST(test_isempty_LinkedList_1) {
  node_t       node;
  linkedlist_t ll;
  ll.head     = &node;
  ll.tail     = &node;
  ll.elements = 1;
  ck_assert_false(isempty_LinkedList(&ll));
}
END_TEST

START_TEST(test_find_LinkedList_0) {
  linkedlist_t ll;
  int i;
  init_LinkedList(&ll);
  ck_assert_int_eq(find_LinkedList(&ll, 10), -1);
}
END_TEST

START_TEST(test_find_LinkedList_1T) {
  linkedlist_t ll;
  node_t       node;
  int i;
  init_Node(&node, NULL, NULL, 10);
  ll.head     = &node;
  ll.prev     = &node;
  ll.elements = 1;
  ck_assert_int_eq(find_LinkedList(&ll, 10), 0);
}
END_TEST

START_TEST(test_find_LinkedList_1F) {
  linkedlist_t ll;
  node_t       node;
  int i;
  init_Node(&node, NULL, NULL, -10);
  ll.head     = &node;
  ll.prev     = &node;
  ll.elements = 1;
  ck_assert_int_eq(find_LinkedList(&ll, 10), 0);
}
END_TEST



START_TEST(test_get_LinkedList) {
}
END_TEST

START_TEST(test_insert_LinkedList) {
}
END_TEST

START_TEST(test_remove_LinkedList) {
}
END_TEST

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

	tcase_add_test(tc_core, test_alloc_LinkedList);
	tcase_add_test(tc_core, test_free_LinkedList);
	tcase_add_test(tc_core, test_init_LinkedList);
	tcase_add_test(tc_core, test_deinit_LinkedList_0);
	tcase_add_test(tc_core, test_deinit_LinkedList_1);
	tcase_add_test(tc_core, test_deinit_LinkedList_2);
	tcase_add_test(tc_core, test_deinit_LinkedList_3);
	tcase_add_test(tc_core, test_isempty_LinkedList_0);
	tcase_add_test(tc_core, test_isempty_LinkedList_1);
	tcase_add_test(tc_core, test_find_LinkedList_0);
	tcase_add_test(tc_core, test_find_LinkedList_1T);
	tcase_add_test(tc_core, test_find_LinkedList_1F);
	tcase_add_test(tc_core, test_find_LinkedList_2);
	tcase_add_test(tc_core, test_find_LinkedList_3);
	tcase_add_test(tc_core, test_get_LinkedList);
	tcase_add_test(tc_core, test_insert_LinkedList);
	tcase_add_test(tc_core, test_remove_LinkedList);
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

