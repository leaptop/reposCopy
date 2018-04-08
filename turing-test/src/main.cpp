#include "stdafx"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tape {
    struct tape *prev;
    struct tape *next;
    char data;
} tape_t;

FILE *file;

int lines;
char **algo;

tape_t *point, *head;

void print_algo() {
    int i;
    for (i=0; i<lines; i++) {
        printf("%s",algo[i]);
    }
}

void print_tape() {
    tape_t *cur = head;
    while (cur != NULL) {
        printf("%c", cur -> data);
        cur = cur -> next;
    }
    printf("\n");
    cur = head;
    while (cur != point) {
        printf(" ");
        cur = cur -> next;
    }
    printf("^\n");
}

void load_algo() {
    char n; 
    fscanf(file, "%d", &lines);
    fscanf(file, "%c", &n);
    algo = (char**) malloc(lines*sizeof(char*));
    for (int i=0; i<lines; i++) {
        algo[i] = malloc(6*sizeof(char));
        fgets(algo[i], sizeof(algo[i]), file);
    }
}

void load_tape() {
    char n;
    int tapelen;
    fscanf(file, "%d", &tapelen);
    fscanf(file, "%c", &n);  //to skip \n after tape length
    if (tapelen >=1) {
        tape_t *cur;
        cur = malloc(sizeof(tape_t));
        head = cur;
        point = cur;
        cur -> prev = NULL;
        fscanf(file, "%c", &cur->data);
        cur -> next = malloc(sizeof(tape_t));
        int i = 1;
        while (i < tapelen && !feof(file)) {
            cur -> next -> prev = cur;
            cur = cur -> next;
            cur -> next = malloc(sizeof(tape_t));
            fscanf(file, "%c", &cur->data);
            cur -> next = malloc(sizeof(tape_t));
            i++;
        }
        cur -> next = NULL;
        fscanf(file, "%c", &n);
    }
}

void exec_algo() {\
    char c;
    int q = 0; //machine state
    int done = 0;
    int i;
    while (!done) {
        system("clear");
        print_tape();
        for (i=0; i<lines; i++) {
            if (algo[i][0]-'0' == q && algo[i][1] == point -> data) {
		printf("%s",algo[i]);
                q = algo[i][2]-'0';
                point -> data = algo[i][3];
                switch (algo[i][4]) {
                    case 'L': 
                        if (point -> prev == NULL) {
                            point -> prev = malloc(sizeof(tape_t));
                            point -> prev -> prev = NULL;
                            point -> prev -> data = ' ';
                            point -> prev -> next = point;
                            head = point -> prev;
                        } 
                        point = point -> prev;
                        break;
                    case 'R':
                        if (point -> next == NULL) {
                            point -> next = malloc(sizeof(tape_t));
                            point -> next -> next = NULL;
                            point -> next -> data = ' ';
                            point -> next -> prev = point;
                        } 
                        point = point -> next;
                        break;
                }
                break;
            }
            if (i == lines-1) done=1;
        }
        scanf("%c",&c);
    }
}

int main(int argc, char **argv) {
    file = fopen(argv[1],"r");
    load_tape();
    load_algo();
    fclose(file);
    exec_algo();
    return 0;
}
