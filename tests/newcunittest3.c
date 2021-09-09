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
    
    int first_array[2][2] = {1,2,3,4};
   
    
    int second_array[2][2] = {1,2,3,4};
   
   
    int *result = multiplyMatrices(&first_array[0][0],2, 2,&second_array[0][0],2,2);
    
    CU_ASSERT_PTR_NULL(result);
    
    
    
    
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest3", init_suite, clean_suite);
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
