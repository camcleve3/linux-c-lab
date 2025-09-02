#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char number[20];
};

int main() {
    struct Contact c;
    int choice;

    while (1) {
        printf("1) Add Contact\n2) View Contact\n3) Quit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter name: ");
            fgets(c.name, sizeof(c.name), stdin);

            printf("Enter number: ");
            fgets(c.number, sizeof(c.number), stdin);

            FILE *fp = fopen("contacts.txt", "a");
            fprintf(fp, "%s%s", c.name, c.number);
            fclose(fp);

            printf("Contact saved!\n");
        }
        else if (choice == 2) {
            FILE *fp = fopen("contacts.txt", "r");
            char line[100];
            printf("\n--- Contacts ---\n");
            while (fgets(line, sizeof(line), fp)) {
                printf("%s", line);
            }
            fclose(fp);
            printf("---------------\n");
        }
        else if (choice == 3) {
            break;
        }
    }

    return 0;
}
