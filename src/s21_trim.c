#include "s21_string.h"

void delete_first_lex(char *str) {
    s21_size_t count = 0;
    while (str[count]) {
        str[count] = str[count + 1];
        count++;
    }
}

void rightpart(char *result, const char*src, const char *trim_chars) {
    s21_size_t formatlen = s21_strlen(trim_chars), reslen = s21_strlen(result);
    int doBreak = 0, i = (int) reslen - 1;
    while(i >= 0 && !doBreak) {
        for (s21_size_t j = 0; j < formatlen; j++) {
            if (result[i] == trim_chars[j]) {
                result[i] = '\0';
                break;
            }
            if (j == formatlen - 1 && src[i] != trim_chars[formatlen]) doBreak = 1;
        }
        i--;
    }
}

void leftpart(char *result, const char*src, const char *trim_chars) {
    s21_size_t formatlen = s21_strlen(trim_chars), strlen = s21_strlen(src), i = 0;
    int doBreak = 0;
    while(!doBreak && i < strlen) {
        for (s21_size_t j = 0; j < formatlen; j++) {
            if (src[i] == trim_chars[j]) {
                delete_first_lex(result);
                break;
            }
            if (j == formatlen - 1 && src[i] != trim_chars[formatlen]) doBreak = 1;
        }
        i++;
    }
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *result = s21_NULL;
    if (src) {
        if (!trim_chars || !s21_strlen(trim_chars)) trim_chars = " \t\n\v\r\f\0";
        result = (char *) calloc(s21_strlen(src) + 13, sizeof(char));
        if (result) {
            s21_strcpy(result, (char *)src);
            leftpart(result, src, trim_chars);
            rightpart(result, src, trim_chars);
        }
    }
    return (void *)result;
}

