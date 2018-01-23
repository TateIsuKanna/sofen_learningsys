#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "AA.hpp"
void AA::printAA(){
        system("clear");
        printf("            ■                   \n");
        printf("            ■               \n");
        printf("  ■ ■ ■ ■ ■ ■ ■ ■ ■ \n");
        printf("          ■ ■              \n");
        printf("        ■   ■              \n");
        printf("      ■     ■              \n");
        printf("    ■       ■              \n");
        printf(" ■          ■              \n");
        usleep(500000);                          // 500000マイクロ秒(0.5秒)止まる

        system("clear");
        printf("            ■                       \n");
        printf("            ■                          ■     \n");
        printf("  ■ ■ ■ ■ ■ ■ ■ ■ ■       ■        \n");
        printf("          ■ ■                ■    ■     \n");
        printf("        ■   ■                  ■         \n");
        printf("      ■     ■               ■   ■        \n");
        printf("    ■       ■             ■       ■       \n");
        printf(" ■          ■         ■               \n");
        usleep(500000);                          // 500000マイクロ秒(0.5秒)止まる

        system("clear");
        printf("            ■                                               ■ ■     \n");
        printf("            ■                          ■       ■ ■ ■ ■ ■        \n");
        printf("  ■ ■ ■ ■ ■ ■ ■ ■ ■       ■         ■                       \n");
        printf("          ■ ■                ■    ■        ■ ■ ■ ■ ■ ■ ■ ■ ■  \n");
        printf("        ■   ■                  ■                   ■               \n");
        printf("      ■     ■               ■   ■                 ■               \n");
        printf("    ■       ■             ■       ■             ■                 \n");
        printf(" ■          ■         ■                       ■                    \n");
        usleep(500000);                          // 500000マイクロ秒(0.5秒)止まる

        system("clear");
        printf("            ■                                               ■ ■     ■            \n");
        printf("            ■                          ■       ■ ■ ■ ■ ■            ■        \n");
        printf("  ■ ■ ■ ■ ■ ■ ■ ■ ■       ■         ■                               ■    \n");
        printf("          ■ ■                ■    ■        ■ ■ ■ ■ ■ ■ ■ ■ ■        ■ ■   \n");
        printf("        ■   ■                  ■                   ■                ■     ■       \n");
        printf("      ■     ■               ■   ■                 ■                 ■         ■  \n");
        printf("    ■       ■             ■       ■             ■                   ■             \n");
        printf(" ■          ■         ■                       ■                     ■              \n");
        usleep(500000);                          // 500000マイクロ秒(0.5秒)止まる

        system("clear");
        printf("            ■                                               ■ ■     ■                    ■              \n");
        printf("            ■                          ■       ■ ■ ■ ■ ■            ■                    ■             \n");
        printf("  ■ ■ ■ ■ ■ ■ ■ ■ ■       ■         ■                               ■              ■ ■ ■ ■ ■ ■ ■     \n");
        printf("          ■ ■                ■    ■        ■ ■ ■ ■ ■ ■ ■ ■ ■        ■ ■            ■           ■       \n");
        printf("        ■   ■                  ■                   ■                ■     ■                   ■         \n");
        printf("      ■     ■               ■   ■                 ■                 ■         ■             ■           \n");
        printf("    ■       ■             ■       ■             ■                   ■                     ■               \n");
        printf(" ■          ■         ■                       ■                     ■                   ■                \n");
        usleep(500000);                          // 500000マイクロ秒(0.5秒)止まる
        system("clear");                          // 画面消去

        for(int i=0;i<5;i++){
                printf("            ■                                               ■ ■     ■                    ■                ■■    ■■\n");
                printf("            ■                          ■       ■ ■ ■ ■ ■            ■                    ■                ■■    ■■\n");
                printf("  ■ ■ ■ ■ ■ ■ ■ ■ ■       ■         ■                               ■              ■ ■ ■ ■ ■ ■ ■          ■■    ■■\n");
                printf("          ■ ■                ■    ■        ■ ■ ■ ■ ■ ■ ■ ■ ■        ■ ■            ■           ■          ■■    ■■\n");
                printf("        ■   ■                  ■                   ■                ■     ■                   ■           ■■    ■■\n");
                printf("      ■     ■               ■   ■                 ■                 ■         ■             ■             ■■    ■■\n");
                printf("    ■       ■             ■       ■             ■                   ■                     ■                           \n");
                printf(" ■          ■         ■                       ■                     ■                   ■                 ■■    ■■\n");
                usleep(500000);                          // 500000マイクロ秒(0.5秒)止まる
                system("clear");
        }
}
