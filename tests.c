#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "CUnit.h"
#include "Automated.h"
#include "kitchen.h"


/* Runs a test input that *should* pass and produce an int result
 */
void test01(void) {
   bool actual = true;
    bool expected = true;
    char testStr[] = "moms cooking";
    int testInt = 5;
    struct Recipe **recipeBook = newBook(10);
    char str[] = "moms cooking";
    char *str2 = &str[0];
    recipeBook[0] = newRecipe(str2, 5);
   int i = 0; 
    for( ; *(recipeBook[0]->title)!='\0'; ++recipeBook[0]->title)  {
       //printf("%c", *(recipeBook[0]->title));   
       if(*(recipeBook[0]->title) != testStr[i]){
          actual = false;
       }
       i++;
    }       

   if((recipeBook[0]-> servings) != testInt){
      actual = false;
   }
    //printf("You entered: %d", (recipeBook[0]-> servings));
   free(recipeBook[0]);
   free(recipeBook);
  CU_ASSERT_EQUAL(expected , actual);
}

void test02(void) {
   bool actual = true;
    bool expected = true;
    struct Recipe **recipeBook = newBook(0);
    if(recipeBook != NULL){
       actual = false;
    }
    //printf("You entered: %d", (recipeBook[0]-> servings));
   free(recipeBook);
  CU_ASSERT_EQUAL(expected , actual);
}

void test03(void) {
   bool actual = true;
    bool expected = true;
    for(int i = 0; i < 100000000; i++){
    struct Recipe **recipeBook = newBook(0);
    if(recipeBook != NULL){
       actual = false;
    }
    free(recipeBook);
    }
  CU_ASSERT_EQUAL(expected , actual);
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite Suite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }

   /* add a suite to the registry */
   Suite = CU_add_suite("Suite_of_tests_with_valid_inputs", NULL, NULL);
   if (NULL == Suite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to Suite */
   if (
          (NULL == CU_add_test(Suite, "", test01))
          ||(NULL == CU_add_test(Suite, "", test02))
          ||(NULL == CU_add_test(Suite, "", test03))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using automated interface, with output to 'test-Results.xml' */
   CU_set_output_filename("test");
   CU_automated_run_tests();

   CU_cleanup_registry();
   return CU_get_error();
}