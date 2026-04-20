#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("/home/nucaloise/reseau/fichier.bin", "rb");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    size_t octets_lus;
    size_t total = 0;

    while ((octets_lus = fread(buffer, 1, sizeof(buffer), f)) > 0) {
        total += octets_lus;
        printf("bloc lu : %zu octets\n", octets_lus);
    }

    if (ferror(f)) {
        perror("fread");
        fclose(f);
        return EXIT_FAILURE;
    }

    printf("total : %zu octets\n", total);
    fclose(f);
    return EXIT_SUCCESS;
}