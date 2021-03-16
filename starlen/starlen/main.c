//
//  main.c
//  starlen
//
//  Created by Michael Irimus on 17.01.18.
//  Copyright © 2018 Michael Irimus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    for(int y = 1; y <= 5; y++){
        int starlen = y;
        while(starlen){
            printf("*");
            starlen--;
        }
        int crosslen = 11 - 2*y;
        for(int x = 0; x < crosslen; x++){
            printf("+");
        }
        starlen = y;
        while(starlen){
            printf("*");
            starlen--;
        }
        printf("\n");
    }
    return 0;
}
