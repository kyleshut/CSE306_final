#ifndef EVALUATE
#define EVALUATE
#include <stdbool.h>
struct Recipe{
   char  *title;
   int   servings;
};

struct Ingredient{
   char  *name;
   int   caloriesPerGram;
};

struct Recipe **newBook(int N);
struct Recipe *newRecipe(char *title, int servings);
void addRecipe(struct Recipe **recipeBook, struct Recipe *recipe, int page);
struct Ingredient *newIngredient(char* name, int caloriesPerGram);

#endif