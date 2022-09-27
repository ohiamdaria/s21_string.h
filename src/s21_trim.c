#include "s21_string.h"

void delete_first_letter(char *str) {
    while (str) {
        *str = *(str + 1);
        str++;
    }
}

void rightpart(char *result, const char*src, const char *trim_chars) {
    s21_size_t format_length = s21_strlen(trim_chars), result_length = s21_strlen(result);
    for (int i = (int) result_length - 1; i >= 0; i--) {
        for (s21_size_t j = 0; j < format_length; j++) {
            if (result[i] == trim_chars[j]) {
                result[i] = '\0';
                break;
            }
            if (j == format_length - 1 && src[i] != trim_chars[format_length]) break;
        }
    }
}

void leftpart(char *result, const char*src, const char *trim_chars) {
    s21_size_t format_length = s21_strlen(trim_chars), str_length = s21_strlen(src);
    for (s21_size_t i = 0; i < str_length; i++) {
        for (s21_size_t j = 0; j < format_length; j++) {
            if (src[i] == trim_chars[j]) {
                delete_first_letter(result);
                break;
            }
            if (j == format_length - 1 && src[i] != trim_chars[format_length]) break;
        }
    }
}


void *s21_trim(const char *src, const char *trim_chars) {
    char *result = s21_NULL;
    if (src) {
        char default_chars[7] = " \t\n\v\r\f\0";
        if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) trim_chars = default_chars;
        result = (char *) calloc(s21_strlen(src) + 10, sizeof(char));
        if (result) {
            s21_strcpy(result, (char *)src);
            leftpart(result, src, trim_chars);
            rightpart(result, src, trim_chars);
        }
    }
    return (void *) result;
}