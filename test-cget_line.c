int main() {
    while (1) {
        char *input = my_getline();

        if (input == NULL) {
            printf("Exiting shell...\n");
            break;
        }

        printf("Input: %s\n", input);
        free(input);
    }

    return 0;
}