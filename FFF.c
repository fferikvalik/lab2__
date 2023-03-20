//
// Created by Valentin Gouriev on 20.03.23.
//
#include "FFF.h"
int input(int min, int max){
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}

void task1(FILE* f, char* argv){
    char c[127];
    freopen(argv, "wt+", f);
    printf("Введите строку :\n");
    if(fgets(c, 127, stdin) != NULL){
        fputs(c,f);
    }
    printf("Your filled file : %s\n", c);
    fclose(f);
}
int count_words(char *str) {
    int word_count = 0;
    int in_word = 0;
    while (*str) {
        if (isalpha(*str)) {
            if (!in_word) {
                in_word = 1;
                word_count++;
            }
        }
        else { in_word = 0; }
        str++;
    }
    return word_count;
}
void task2(FILE* f,char* argv){
    char str[BUFSIZ];
    freopen(argv,"rt+",f);
    fflush(stdin);
    rewind(f);
    fgets(str, BUFSIZ,f);
    fclose(f);
    int word_count = count_words(str);
    printf("Number of words: %d\n\nCurrent file: %s\n", word_count, str);
}

void task3(FILE* f,char* argv){
    freopen(argv,"rt+",f);
    fflush(stdin);
    rewind(f);
    fseek(f,0,SEEK_SET);
    char str[BUFSIZ], buff[BUFSIZ];
    fgets(str, BUFSIZ, f);
    fclose(f);
    fflush(stdin);
    int len = strlen(str), x=0, max_len = 0, start_index = 0;
    for (int i = 0; i < len; i++) {
        int current_len = 0;
        while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
            current_len++;
            i++;
        }
        if (current_len > max_len) {
            max_len = current_len;
            start_index = i - max_len;
        }
    }

    printf("Самое длинное перевёрнутое слово: ");
    for (int j=start_index, i = start_index + max_len - 1; i >= start_index; j++, i--) {
        buff[j]=str[i];
        printf("%c", buff[j]);
        x++;
    }
    for (int i = start_index; i < x+start_index; ++i) {
        str[i]=buff[i];
    }
    printf("\nИндекс начала самого длинного слова: %d\n", start_index);
    freopen(argv, "wt+",f);
    fputs(str,f);
    printf("\nRedacted file : \n%s",str);
}
