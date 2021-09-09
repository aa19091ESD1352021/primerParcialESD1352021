#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../examen.h"

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testReadcsv() {
    const char *p2 = "peliculasFavoritasESD135_2021.csv";
    dataType *result = readcsv(p2);
    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_STRING_EQUAL(*(result+1*7+0),"ph20003");
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testReadcsv", testReadcsv))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
