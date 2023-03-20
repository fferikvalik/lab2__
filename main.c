#include <stdio.h>
#include "FFF.h"

int main(int argc, char **argv) {
    if(argv[1] == NULL){
        printf("\n\x1b[33;40mФайл не найден\x1b[0;0m\n");
        printf("ARGC = %d",argc);
        return 0;
    }
    int t=0;
    FILE* f=fopen(argv[1],"wt+");
    //FILE* f=fopen("/Users/admin/Desktop/OAiP/S2LABA2++/text.txt","wt+");
    while(t != 2) {
        int choose;
        printf("\nAvailable tasks:\n1.Print text file.\x1b[32m(Completed)\x1b[0m");
        printf("\n2.Count number of words in text file.\x1b[32m(Completed)\x1b[0m");
        printf("\n3.Revers longest word.\x1b[32m(Completed)\x1b[0m\n");
        printf("Choose task: ");
        choose = input(1, 3);
        if (choose == 1) {
            task1(f, argv[1]);
        } else if (choose == 2) {
            task2(f,argv[1]);
        } else if (choose == 3) {
            task3(f,argv[1]);
        }
        printf("\nDo you want to choose one more task?\n1.Yes\n2.No\n");
        t = input(1,2);
    }
    fclose(f);
    return 0;
}