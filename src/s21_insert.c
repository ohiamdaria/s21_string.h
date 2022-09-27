#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
    char *res = s21_NULL;

    if (src && start_index <= s21_strlen(src) && str) {
        s21_size_t common_len = 0;
        common_len = s21_strlen(src) + s21_strlen(str) + 1;
        res = (char*)calloc(common_len, sizeof(char));
        if (res) {
            s21_size_t i = 0;
            while (i < start_index) {
                res[i++] = *src;
                src++;
            }
            while (*str) {
                res[i++] = *str;
                str++;
            }
            while (*src) {
                res[i++] = *src;
                src++;
            }
            res[i] = '\0';
        }
    } else if (start_index == 0 && (!str)) {
        res = s21_NULL;
    } else if (src && start_index <= s21_strlen(src)) {
        s21_size_t common_len = s21_strlen(src);
        res = (char*)calloc(common_len, sizeof(char));
        s21_strcpy(res, src);
    }
    return (void*)res;
}