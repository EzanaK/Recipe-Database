/*
 * Recipe.h
 *
 Header file for Project 2
 *
 */

/* Constant sizes */
#define MAX_DATABASE_SIZE 5242880
#define MAX_RECIPES 10000
#define MAX_RECIPE_CATEGORIES 8
#define MAX_STR_LEN 100

/* Global variables */
char raw_recipes[MAX_DATABASE_SIZE];
char title[MAX_RECIPES][MAX_STR_LEN];
char author[MAX_RECIPES][MAX_STR_LEN];
int prep_time_hour[MAX_RECIPES];
int prep_time_min[MAX_RECIPES];
char categories[MAX_RECIPES][MAX_RECIPE_CATEGORIES][MAX_STR_LEN];
int total_categories[MAX_RECIPES];
int categories_begin[MAX_RECIPES];
int categories_end[MAX_RECIPES];
int recipe_begin[MAX_RECIPES];
int ingredients_begin[MAX_RECIPES];
int ingredients_end[MAX_RECIPES];
int instructions_begin[MAX_RECIPES];
int instructions_end[MAX_RECIPES];
FILE *recipe_file;
int file_index;
int num_recipes;

/* Functions */
void parse();
void parse_header(int recipe_ID);
char helper_parse_header (int recipe_ID, char c, int section);
int parse_body(int recipe_ID);
void print();
void print_sum_lines(int num_of_recipes);
void print_sum(int recipe_ID);
void print_sum_prep_time();
void print_sum_category();
void display_recipe();