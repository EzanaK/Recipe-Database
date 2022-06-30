/*
 * Recipe Database Functions
 */

#include <stdio.h>
#include "Recipe.h"
#include <string.h>
#include <stdlib.h>

void parse() {
    // Prompts user for database, opens recipe file and calls other parsing functions
    int choice;
    printf("Enter database (0, 1, 2):  ");
    fflush(stdout);
    scanf("%d", &choice);
    while (choice < 0 || choice > 2) {
        printf("Invalid input\n");
        printf("Enter database (0, 1, 2):  ");
        fflush(stdout);
        scanf("%d", &choice);
    }
    switch (choice) {
        case 0 :
            recipe_file = fopen("recipes0.data", "r");
            break;
        case 1 :
            recipe_file = fopen("recipes1.data", "r");
            break;
        case 2 :
            recipe_file = fopen("recipes2.data", "r");
            break;
    }
    file_index = 0;
    int recipe_ID = -1;
    char c = getc(recipe_file);
    char temp_line[MAX_DATABASE_SIZE] = {""};
    int i = 0;
    while (c != '\n') {
        raw_recipes[file_index] = c;
        file_index++;
        temp_line[i] = c;
        i++;
        c = getc(recipe_file);
    }
    raw_recipes[file_index] = c;
    file_index++;
    if (strcmp(temp_line, "                             ************************") == 0) {
        recipe_ID++;
    }
    while(1) {
        parse_header(recipe_ID);
        int temp = parse_body(recipe_ID);
        recipe_ID = temp;
        if (recipe_ID == -2) {
            break;
        }
    }
    printf("Parsed %d recipes\n", num_recipes);
}

void parse_header(int recipe_ID) {
    // Parses the header of a recipe
    char c;
    int section;
    c = getc(recipe_file);
    raw_recipes[file_index] = c;
    file_index++;
    recipe_begin[recipe_ID] = file_index;
    for (section = 1; section <= 4; section++) {
        while (c != ':') {
            c = getc(recipe_file);
            raw_recipes[file_index] = c;
            file_index++;
        }
        c = helper_parse_header(recipe_ID, c, section);
    }
}

char helper_parse_header (int recipe_ID, char c, int section) {
    // Helper function that is called within parse_header
    int i = 0;
    int whitespace = 1; // 1 when whitespace, 0 when real data
    c = getc(recipe_file);
    raw_recipes[file_index] = c;
    file_index++;
    switch (section) {
        case 1 :
            while (c != '\n') {
                if (c != ' ') {
                    whitespace = 0;
                }
                if (whitespace == 0) {
                    title[recipe_ID][i] = c;
                    i++;
                }
                c = getc(recipe_file);
                raw_recipes[file_index] = c;
                file_index++;
            }
            break;
        case 2 :
            while (c != '\n') {
                if (c != ' ') {
                    whitespace = 0;
                }
                if (whitespace == 0) {
                    author[recipe_ID][i] = c;
                    i++;
                }
                c = getc(recipe_file);
                raw_recipes[file_index] = c;
                file_index++;
            }
            break;
        case 3 :
            while (c != '\n') {
                if (c != ' ') {
                    char hours[10];
                    while(c != ':') {
                        hours[i] = c;
                        i++;
                        c = getc(recipe_file);
                        raw_recipes[file_index] = c;
                        file_index++;
                    }
                    prep_time_hour[recipe_ID] = atoi(hours);
                    char min[2];
                    for (i = 0; i < 2; i++) {
                        c = getc(recipe_file);
                        raw_recipes[file_index] = c;
                        file_index++;
                        min[i] = c;
                    }
                    prep_time_min[recipe_ID] = atoi(min);
                }
                c = getc(recipe_file);
                raw_recipes[file_index] = c;
                file_index++;
            }
            break;
        case 4 :
            categories_begin[recipe_ID] = file_index;
            int category_num = 0;
            while(1) {
                whitespace = 1;
                while (c != '\n') {
                    if (c != ' ') {
                        whitespace = 0;
                    }
                    if (whitespace == 0) {
                        categories[recipe_ID][category_num][i] = c;
                        i++;
                    }
                    c = getc(recipe_file);
                    raw_recipes[file_index] = c;
                    file_index++;
                }
                category_num++;
                i = 0;
                c = getc(recipe_file);
                raw_recipes[file_index] = c;
                file_index++;
                if (c == '\n') {
                    categories_end[recipe_ID] = file_index - 1;
                    total_categories[recipe_ID] = category_num;
                    break;
                }
            }
            break;
    }
    return c;
}

int parse_body(int recipe_ID) {
    // Parses the body of a recipe
    char c;
    c = getc(recipe_file);
    raw_recipes[file_index] = c;
    file_index++;
    while (c != '\n') {
        c = getc(recipe_file);
        raw_recipes[file_index] = c;
        file_index++;
    }
    ingredients_begin[recipe_ID] = file_index - 1;
    c = getc(recipe_file);
    raw_recipes[file_index] = c;
    file_index++;
    while (1) {
        if (c == ':') {
            c = getc(recipe_file);
            raw_recipes[file_index] = c;
            file_index++;
            if (c == '\n') {
                ingredients_end[recipe_ID] = file_index - 15;
                instructions_begin[recipe_ID] = file_index - 1;
                break;
            }
        }
        c = getc(recipe_file);
        raw_recipes[file_index] = c;
        file_index++;
    }
    while (c != EOF) {
        char temp_line[MAX_RECIPES] = {""};
        int i = 0;
        while (c != '\n') {
            c = getc(recipe_file);
            raw_recipes[file_index] = c;
            file_index++;
            temp_line[i] = c;
            i++;
        }
        if (strcmp(temp_line, "                            ************************\n") == 0) {
            instructions_end[recipe_ID] = file_index - 55;
            recipe_ID++;
            return recipe_ID;
        }
        c = getc(recipe_file);
        raw_recipes[file_index] = c;
        file_index++;
    }
    num_recipes = recipe_ID + 1;
    instructions_end[recipe_ID] = file_index - 2;
    return -2;
}

void print() {
    // Prompts user with printing options and calls corresponding printing function
    int choice;
    printf("1.  Print summary\n"
           "2.  Print summary by prep time\n"
           "3.  Print summary by category\n"
           "4.  Print recipe\n"
           "5.  Exit\n"
           "Enter option:  ");
    fflush(stdout);
    scanf("%d", &choice);
    while (choice < 1 || choice > 5) {
        printf("Invalid input\n");
        printf("1.  Print summary\n"
               "2.  Print summary by prep time\n"
               "3.  Print summary by category\n"
               "4.  Print recipe\n"
               "5.  Exit\n"
               "Enter option:  ");
        fflush(stdout);
        scanf("%d", &choice);
    }
    switch (choice) {
        case 1 :
            print_sum_lines(num_recipes);
            break;
        case 2 :
            print_sum_prep_time();
            break;
        case 3 :
            print_sum_category();
            break;
        case 4 :
            display_recipe();
            break;
        case 5 :
            fclose(recipe_file);
            exit(0);
    }
}

void print_sum_lines(int num_of_recipes) {
    // Prints summary line for all recipes
    int i;
    for (i = 0; i < num_of_recipes; i++) {
        print_sum(i);
    }
}

void print_sum(int recipe_ID) {
    // Prints summary for each recipe  including the recipe ID, name, author, preparation time, and category descriptors
    printf("%3d.  ", recipe_ID);
    int length;
    length = strlen(title[recipe_ID]);
    if (length >= 15) {
        int i;
        for (i = 0; i < 15; i++) {
            printf("%c", title[recipe_ID][i]);
        }
    }
    else {
        printf("%s", title[recipe_ID]);
        int whitespace = 15 - length;
        for (; whitespace > 0; whitespace--) {
            printf(" ");
        }
    }
    printf("  ");
    length = strlen(author[recipe_ID]);
    if (length >= 15) {
        int i;
        for (i = 0; i < 15; i++) {
            printf("%c", author[recipe_ID][i]);
        }
    }
    else {
        printf("%s", author[recipe_ID]);
        int whitespace = 15 - length;
        for (; whitespace > 0; whitespace--) {
            printf(" ");
        }
    }
    printf("  ");
    printf("%1d:%02d  ", prep_time_hour[recipe_ID], prep_time_min[recipe_ID]);
    int remaining_space = 30;
    int category_num = 0;
    while (remaining_space > 0) {
        if (category_num > total_categories[recipe_ID] - 1) {
            break;
        }
        if (category_num == 0) {
            length = strlen(categories[recipe_ID][category_num]);
            if (length <= remaining_space) {
                printf("%s", categories[recipe_ID][category_num]);
                remaining_space = remaining_space - length;
                category_num++;
            }
            else {
                break;
            }
        }
        else {
            length = strlen(categories[recipe_ID][category_num]) + 1;
            if (length <= remaining_space) {
                printf(",%s", categories[recipe_ID][category_num]);
                remaining_space = remaining_space - length;
                category_num++;
            }
            else {
                break;
            }
        }
    }
    printf("\n");
}

void print_sum_prep_time() {
    // Prompts user for prep time and prints summary for all recipes that do not exceed the specified prep time
    int hours, min;
    printf("Enter time (h m):  ");
    fflush(stdout);
    scanf("%d %d", &hours, &min);
    while (hours < 0 || min < 0 || min > 59) {
        printf("Invalid input\n");
        printf("Enter time (h m):  ");
        fflush(stdout);
        scanf("%d %d", &hours, &min);
    }
    int i;
    for (i = 0; i < num_recipes; i++) {
        int recipe_hours, recipe_min;
        recipe_hours = prep_time_hour[i];
        if (recipe_hours < hours) {
            print_sum(i);
        }
        else if (recipe_hours == hours) {
            recipe_min = prep_time_min[i];
            if (recipe_min <= min) {
                print_sum(i);
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }
}

void print_sum_category() {
    // Prompts the user for a category descriptor and prints a summary line for each recipe in the database file that has a matching category descriptor.
    char category[MAX_STR_LEN];
    int valid_category_descriptor = 0;
    int attempts = 1;
    int i, j;
    while (valid_category_descriptor != 1) {
        if (attempts > 1) {
            printf("Invalid input\n");
        }
        printf("Enter category:  ");
        fflush(stdout);
        char temp;
        scanf("%c",&temp);
        scanf("%[^\n]", category);
        for (i = 0; i < num_recipes; i++) {
            for (j = 0; j < MAX_RECIPE_CATEGORIES; j++) {
                if (strcmp(category, categories[i][j]) == 0) {
                    valid_category_descriptor = 1;
                    break;
                }
            }
            if (valid_category_descriptor == 1) {
                break;
            }
        }
        attempts++;
    }
    for (i = 0; i < num_recipes; i++) {
        for (j = 0; j < MAX_RECIPE_CATEGORIES; j++) {
            if (strcmp(category, categories[i][j]) == 0) {
                print_sum(i);
                break;
            }
        }
    }
}

void display_recipe() {
    // Prompts the user for a recipe number and prints the full recipe.
    int recipe_ID;
    printf("Enter recipe number:  ");
    fflush(stdout);
    scanf("%d", &recipe_ID);
    while (recipe_ID < 0 || recipe_ID > (num_recipes - 1)) {
        printf("Invalid input\n");
        printf("Enter recipe number:  ");
        fflush(stdout);
        scanf("%d", &recipe_ID);
    }
    int i;
    for (i = recipe_begin[recipe_ID]; i <= instructions_end[recipe_ID]; i++) {
        printf("%c", raw_recipes[i]);
    }
    if (recipe_ID == (num_recipes - 1)) {
        printf("\n");
    }
}
