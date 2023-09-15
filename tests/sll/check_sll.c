//#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "sll/sll.h"
#include "sll/node.h"

START_TEST(test_alloc_SLinkedList) {
  slinkedlist_t *ll = alloc_SLinkedList();
  free_SLinkedList(ll);
}
END_TEST

START_TEST(test_free_SLinkedList) {
  slinkedlist_t *ll = alloc_SLinkedList();
  free_SLinkedList(ll);
}
END_TEST

START_TEST(test_init_SLinkedList) {
  slinkedlist_t ll;
  init_SLinkedList(&ll);
//  ck_assert_ptr_null(ll.head);
  //ck_assert_ptr_null(ll.tail);
 // ck_assert_int_eq(ll.size, 0);
}
END_TEST

START_TEST(test_deinit_SLinkedList_0) {
  slinkedlist_t ll;
  init_SLinkedList(&ll);
  deinit_SLinkedList(&ll);
  //ck_assert_ptr_null(ll.head);
  //ck_assert_ptr_null(ll.tail);
  //ck_assert_int_eq(ll.size, 0);
}

END_TEST
START_TEST(test_deinit_SLinkedList_1) {
  sll_node_t   node;
  slinkedlist_t ll;
  init_SLLNode(&node, NULL, NULL, -1);
  ll.head     = &node;
  //ll.tail     = &node;
  ll.size = 1;
  deinit_SLinkedList(&ll);
  //ck_assert_ptr_null(ll.head);
  //ck_assert_ptr_null(ll.tail);
  //ck_assert_int_eq(ll.size, 0);
}
END_TEST

START_TEST(test_deinit_SLinkedList_2) {
  sll_node_t       a, b;
  slinkedlist_t ll;
  init_SLLNode(&a, &b,   NULL, -1);
  init_SLLNode(&b, NULL, &a,   -2);
  ll.head     = &a;
  //ll.tail     = &b;
  ll.size = 2;
  deinit_SLinkedList(&ll);
  //ck_assert_ptr_null(ll.head);
  //ck_assert_ptr_null(ll.tail);
  //ck_assert_int_eq(ll.size, 0);
}
END_TEST

START_TEST(test_deinit_SLinkedList_3) {
  sll_node_t       a, b, c;
  slinkedlist_t ll;
  init_SLLNode(&a, &b,   NULL, -1);
  init_SLLNode(&b, &c,   &a,   -2);
  init_SLLNode(&c, NULL, &b,   -3);
  ll.head     = &a;
  //ll.tail     = &c;
  ll.size = 3;
  deinit_SLinkedList(&ll);
  //ck_assert_ptr_null(ll.head);
  //ck_assert_ptr_null(ll.tail);
  //ck_assert_int_eq(ll.size, 0);
}
END_TEST

START_TEST(test_isempty_SLinkedList_0) {
  slinkedlist_t ll;
  init_SLinkedList(&ll);
  //ck_assert(isempty_SLinkedList(&ll));
}
END_TEST

START_TEST(test_isempty_SLinkedList_1) {
  sll_node_t   node;
  slinkedlist_t ll;
  ll.head     = &node;
  //ll.tail     = &node;
  ll.size = 1;
  //ck_assert(!isempty_SLinkedList(&ll));
}
END_TEST

START_TEST(test_find_SLinkedList_0) {
  slinkedlist_t ll;
  int i;
  init_SLinkedList(&ll);
  //ck_assert_int_eq(find_SLinkedList(&ll, 10), -1);
}
END_TEST

START_TEST(test_find_SLinkedList_1T) {
  slinkedlist_t ll;
  sll_node_t   node;
  int i;
  init_SLLNode(&node, NULL, NULL, 10);
  ll.head     = &node;
  //ll.tail     = &node;
  ll.size = 1;
  //ck_assert_int_eq(find_SLinkedList(&ll, 10), 0);
}
END_TEST

START_TEST(test_find_SLinkedList_1F) {
  slinkedlist_t ll;
  sll_node_t   node;
  int i;
  init_SLLNode(&node, NULL, NULL, -10);
  ll.head     = &node;
  //ll.tail     = &node;
  ll.size = 1;
  //ck_assert_int_eq(find_SLinkedList(&ll, 10), 0);
}
END_TEST



START_TEST(test_get_SLinkedList) {
}
END_TEST

START_TEST(test_insert_SLinkedList) {
}
END_TEST

START_TEST(test_remove_SLinkedList) {
}
END_TEST

Suite *dll_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("DLL");

	/* Core test case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_alloc_SLinkedList);
	tcase_add_test(tc_core, test_free_SLinkedList);
	tcase_add_test(tc_core, test_init_SLinkedList);
	tcase_add_test(tc_core, test_deinit_SLinkedList_0);
	tcase_add_test(tc_core, test_deinit_SLinkedList_1);
	tcase_add_test(tc_core, test_deinit_SLinkedList_2);
	tcase_add_test(tc_core, test_deinit_SLinkedList_3);
	tcase_add_test(tc_core, test_isempty_SLinkedList_0);
	tcase_add_test(tc_core, test_isempty_SLinkedList_1);
	tcase_add_test(tc_core, test_find_SLinkedList_0);
	tcase_add_test(tc_core, test_find_SLinkedList_1T);
	tcase_add_test(tc_core, test_find_SLinkedList_1F);
	//tcase_add_test(tc_core, test_find_SLinkedList_2);
	//tcase_add_test(tc_core, test_find_SLinkedList_3);
	tcase_add_test(tc_core, test_get_SLinkedList);
	tcase_add_test(tc_core, test_insert_SLinkedList);
	tcase_add_test(tc_core, test_remove_SLinkedList);

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

