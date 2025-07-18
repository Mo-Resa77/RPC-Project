/* square_client.c */
#include <rpc/rpc.h>
#include <stdio.h>
#include "square.h"

int main(int argc, char *argv[]) {
    CLIENT *clnt;
    int *result;
    char *server;
    struct moresa_string_pair pair;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname string1 string2\n", argv[0]);
        exit(1);
    }

    server = argv[1];    /* Server hostname */
    pair.str1 = argv[2]; /* First string */
    pair.str2 = argv[3]; /* Second string */

    /* Create client handle */
    clnt = clnt_create(server, MORESA_SQUARE_PROG, MORESA_SQUARE_VERS, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(server);
        exit(1);
    }

    /* Call the remote procedure */
    result = moresa_check_substring_1(&pair, clnt);
    if (result == NULL) {
        clnt_perror(clnt, "call failed");
        exit(1);
    }

    /* Print the result */
    printf("Is '%s' a substring of '%s'? %s\n", pair.str1, pair.str2, *result ? "Yes" : "No");

    /* Clean up */
    clnt_destroy(clnt);
    return 0;
}