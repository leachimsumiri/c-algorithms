//
//  main.c
//  Thema6
//
//  Created by Michael Irimus on 06.01.18.
//  Copyright © 2018 Michael Irimus. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*      // Übung in der Stunde


char data [][100] = { "Zeichenkette 1", "Zeichenkette 2", "Zeichenkette 3"};

void find_data(char search_for[]);

int main() {
    printf("hi %i \n", 3);
    char buffer[100];
    scanf("%s", buffer);
    find_data(buffer);
    return 0;
}

void find_data(char search_for[]) { // = char * search_for
    int i;
    for (i = 0; i < 3; i++) {
        if (strstr(data[i], search_for)) { // strstr liefert die Adresse wo search_for in data[i] gefunden wurde
            printf("Gefunden in: %s\n", strstr(data[i], search_for));
        }
        else {
            printf("'%s' wurde in '%s' nicht gefunden\n", search_for, data[i]);
        }
    }
}
*/

char hs[100] = { "Dies ist is ein Text" };

void stringString(char *haystack, char *needle);

int main() {
    printf("Suchen Sie eine Zeichenfolge in folgendem Text: '%s' \n", hs);
    char need[100];
    scanf("%s", need);
    stringString(hs, need);
    return 0;
}

void stringString(char *haystack, char *needle) {
    int match_pos = 0, i, j = 0, match = 0, count = 0, match_start = 0;
    for (i = 0; haystack[i] != '\0'; i++) {                             // haystack[i] würde reichen weil C-Programmierung ....
        for (j = 0; needle[j] != '\0'; j++) {                           // same here
            if (haystack[i] == needle[j]) {
                count++;
                if (j == 0){
                    match_start = i;                                    // merk dir die Anfangsposition jedes matches
                }
                if (j == 0 && count == 1) {                             // merk dir die Anfangsposition des ersten "Gesamt"maches
                    match_pos = i;
                }
                if (j == (strlen(needle) - 1)) {
                    printf("%s\n", &haystack[match_start]);
                    match = 1;
                } else {                                     // wenn der match kleiner ist als die needle, resete den counter wieder. sonst wird die stelle des ersten
                    count=0;                                 // gefundenen Zeichens ausgegeben.
                }
                i++;
            }
            else {
                break;
            }
        }
    }
    if (match) {
        printf("Die Zeichenfolge wurde im Array erstmals an Stelle %d gefunden. \n\n", match_pos);
    } else if (strlen(needle) < 2){
        printf("Ein einziges Zeichen ist keine Zeichenfolge... oder? \n");
    }
    else {
        printf("Die Zeichenfolge ist nicht im Array enthalten. \n");
    }
}
