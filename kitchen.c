#include <stdio.h>
#include <stdlib.h>
#include "kitchen.h"
#include <stdbool.h>

struct Recipe **newBook(int N) {
   struct Recipe **ret = NULL;
   if(N > 0){
    ret = malloc(N * sizeof(struct Recipe));
   }
    return ret;
}

struct Recipe *newRecipe(char *title, int servings) {
   struct Recipe *ret;
   ret = (struct Recipe*)malloc(sizeof(struct Recipe));
   ret -> title = title;
   ret -> servings = servings;
    return ret;
}

void addRecipe(struct Recipe **recipeBook, struct Recipe *recipe, int page){
recipeBook[page] = recipe;
}
