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

void testTranspose() {
    int array[3][2] = {1, 2, 3, 4, 5, 6}; // 1 3 5
                                          // 2 4 6
    int filas = 3;
    int columnas = 2;
    int *result = transpose(array, filas, columnas);
    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT(*(result+0*3+1) == 3);
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testTranspose", testTranspose))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
