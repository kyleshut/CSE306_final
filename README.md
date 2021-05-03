# Lab Practical (LPR) - part 1

## General Instructions

### Timeframe
You may work on this part of the lab practical exam only for two hours and only during your scheduled lab time on Tuesday, April 27, 2021 (based on your HUB registration).

**Please note:** if you do not finish all the coding during part 1 (a.k.a LPR1), don't worry - you can finish up during part 2 (a.k.a. LPR2), though you may not touch your repo between LPR1 and LPR2.  We give some implementation hints (see below).  Remember to show proper use of tools and techniques.

**Please note:** In LPR2 you will receive buggy code so you can use gdb to track down a segfault and valgrind/memcheck to document and fix memory leaks.

### Resources
You may use any prior work you have done for this course (any earlier LEXes, PRE, EXP01, EXP02, POST), any tool documentation, etc.  You may ask TAs (but not other students) questions during the lab practical, though they cannot answer all questions: this is an exam after all.  TAs will be available on Zoom during your regular lab time.  Between part 1 and part 2 you should may ask questions on Piazza, and we will endeavour to answer them as quickly as possible (though keep in mind that we may not keep the same hours you do).

### Repository & ZenHub integration
Be sure to associate a ZenHub workspace/board with your GitHub repo.

## General Problem Description

Use a Test-Driven approach to design and implement a recipe book, with functionality described below.

A **recipe book** holds recipies.

A **recipe** contains ingredients, quantities, and servings.

A **pantry** contains ingredients and quantities.

An **ingredient** contains nutrition information per quantity; this data can be downloaded from [the USDA Methods and Application of Food Composition Laboratory](https://www.ars.usda.gov/northeast-area/beltsville-md-bhnrc/beltsville-human-nutrition-research-center/methods-and-application-of-food-composition-laboratory/mafcl-site-pages/sr11-sr28/) (an [abbreviated .xlsx file](https://www.ars.usda.gov/ARSUserFiles/80400535/DATA/SR/sr28/dnload/sr28abxl.zip) can also be downloaded).  You are NOT expected to download and process this data during the lab practical.  *For the purposes of this exercise assume that only a calorie count per gram of ingredient is stored.  Create your own sample data for use in your tests - it need not be accurate.*

## Specific Requirements

Write functions to create representations as follows:

* `newBook()` creates a new recipe book. The function must return a pointer to the newly created item.

* `newRecipe(name, servings)` creates a new recipe, with the indicated name and number of servings. The function must return a pointer to the newly created item.

* `newIngredient(name, caloriesPerGram)` creates a new ingredient, with the indicated name and the indicated number of calories per gram of ingredient.  The function must return a pointer to the newly created item.

* `newPantry()` creates a new pantry. The function must return a pointer to the newly created item.

Write functions to modify representations as follows:

* `addRecipe(book, recipe)` adds recipe to book.

* `addIngredient(recipe, ingredient, quantity)` adds the indicated quantity of the ingredient to the recipe.

* `storeIngredient(pantry, ingredient, quantity)` adds the indicated quantity of the ingredient to the pantry.

Write functions to answer questions as follows:

* `canMakeAny(pantry,book)` must return a new book (set of recipes) containing recipes from the input book such that each one can be made from the ingredients in the pantry.  It is not necessary that there are enough ingredients in the pantry to make more than one recipe.

* `canMakeAll(pantry,book)` must return a set of books (each book is a set of recipes) containing recipes from the input book such that all recipies in new book can be made from the ingredients in the pantry.  It is a requirement that there are enough ingredients in the pantry to make ALL the recipies in each new book.

* `withinCalorieLimit(pantry,book,limit)` must return a new book (a set of recipes) containing those recipes from the input book which come in at fewer than the indicated calorie limit, per serving.

## Advice

**ADVICE** Your focus should be on gathering evidence that you are able to apply the development and debugging processes we have discussed throughout the semester, and that you can correctly and effectively use the tools covered.  Do NOT feel like you have to complete all the functionality: the exercise is designed to be too big to complete in the time given (so you don't run out of tasks to work on).

**ADVICE** Carve out a subset of the requirements to focus on.  Be efficient.  Once you are comfortable with the evidence you have gathered for a given process/tool, move on.

