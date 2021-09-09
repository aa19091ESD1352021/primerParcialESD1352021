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

void testMultiplyMatrices() {
    
    int first_row = 3;
    int first_column = 3;
    int first_array[3][3] = {9,1,1,1,2,1,1,18,1};
    int second_row = 3;
    int second_column = 2;
    int second_array[3][2] = {1,1,1,1,1,1};
    
    int *result = multiplyMatrices(&first_array[0][0], first_row, first_column, &second_array[0][0], second_row, second_column);
    
    CU_ASSERT_PTR_NOT_NULL(result);
    
    CU_ASSERT(*(result+0*2+0) == 11);
    
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest5", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testMultiplyMatrices", testMultiplyMatrices))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
