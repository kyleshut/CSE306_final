#ifndef EVALUATE
#define EVALUATE
#include <stdbool.h>
struct Recipe{
   char  *title;
   int   servings;
};

struct Recipe **newBook(int N);
struct Recipe *newRecipe(char *title, int servings);

#endif