#include <stdio.h>
#include <stdlib.h>
#include "kitchen.h"
#include <stdbool.h>

struct Recipe **newBook(int N) {
   struct Recipe **ret;
   if(N > 0){
    ret = malloc(N * sizeof(struct Recipe));
   }else{
    ret = malloc(0);
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
