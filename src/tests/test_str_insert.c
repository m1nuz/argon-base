#include <minunit.h>
#undef NDEBUG
#include <base/str_insert.h>

static char *
test_str_insert_middle(void) {
    char *str = malloc(20);
    strcpy(str, "aaacccc");
    const char *s = "bbb";
    char *new_str = str_insert(str, s, 3);
    const char *result = "aaabbbcccc";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    free(str);
    free(new_str);

    return NULL;
}

static char *
test_str_insert_begining(void) {
    char *str = malloc(20);
    strcpy(str, "aaacccc");
    const char *s = "bbb";
    char *new_str = str_insert(str, s, 0);
    const char *result = "bbbaaacccc";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    free(str);
    free(new_str);

    return NULL;
}

static char *
test_str_insert_ending(void) {
    char *str = malloc(20);
    strcpy(str, "aaacccc");
    const char *s = "bbb";
    char *new_str = str_insert(str, s, strlen(str));
    const char *result = "aaaccccbbb";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    free(str);
    free(new_str);

    return NULL;
}

static char *
test_str_insert_fixed_middle(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed(str, s, 3);
    const char *result = "aaabbbcccc";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    return NULL;
}

static char *
test_str_insert_fixed_begining(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed(str, s, 0);
    const char *result = "bbbaaacccc";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    return NULL;
}

static char *
test_str_insert_fixed_ending(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed(str, s, strlen(str));
    const char *result = "aaaccccbbb";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    return NULL;
}

static char *
test_str_insert_fixed_safe_middle(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed_s(str, s, 3, sizeof str);
    const char *result = "aaabbbcccc";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    return NULL;
}

static char *
test_str_insert_fixed_safe_begining(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed_s(str, s, 0, sizeof str);
    const char *result = "bbbaaacccc";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    return NULL;
}

static char *
test_str_insert_fixed_safe_ending(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed_s(str, s, strlen(str), sizeof str);
    const char *result = "aaaccccbbb";

    mu_assert_args(strcmp(new_str, result) == 0, "error, %s %s != %s", __func__, result, new_str);

    return NULL;
}

static char *
test_str_insert_fixed_safe_not_safe(void) {
    char str[20] = "aaacccc";
    const char *s = "bbb";
    char *new_str = str_insert_fixed_s(str, s, strlen(str), 7);

    mu_assert_args(strcmp(new_str, str) == 0, "error, %s %s != %s", __func__, str, new_str);

    return NULL;
}


static void
all_tests(void) {
    mu_suite_start();
    mu_run_test(test_str_insert_begining);
    mu_run_test(test_str_insert_middle);
    mu_run_test(test_str_insert_ending);
    mu_run_test(test_str_insert_fixed_begining);
    mu_run_test(test_str_insert_fixed_middle);
    mu_run_test(test_str_insert_fixed_ending);
    mu_run_test(test_str_insert_fixed_safe_begining);
    mu_run_test(test_str_insert_fixed_safe_middle);
    mu_run_test(test_str_insert_fixed_safe_ending);
    mu_run_test(test_str_insert_fixed_safe_not_safe);
    mu_suite_end();
}

mu_run_main(all_tests)
