#include <stdio.h>
#include <string.h>

void view_file(const char *name) {
    FILE *f = fopen(name, "r");
    if (!f) return;
    char c;
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);
}

void replace_word(const char *name, const char *oldw, const char *neww) {
    FILE *f = fopen(name, "r");
    FILE *t = fopen("temp.txt", "w");
    if (!f || !t) return;

    char word[256];
    while (fscanf(f, "%255s", word) == 1) {
        if (strcmp(word, oldw) == 0)
            fprintf(t, "%s ", neww);
        else
            fprintf(t, "%s ", word);
    }

    fclose(f);
    fclose(t);

    remove(name);
    rename("temp.txt", name);
}

int main(void) {
    char filename[256];
    char oldw[256], neww[256];
    int choice;

    scanf("%255s", filename);

    do {
        scanf("%d", &choice);
        if (choice == 1) {
            view_file(filename);
        }
        if (choice == 2) {
            scanf("%255s %255s", oldw, neww);
            replace_word(filename, oldw, neww);
        }
    } while (choice != 0);

    return 0;
}
