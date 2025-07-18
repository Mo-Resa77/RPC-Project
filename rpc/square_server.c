/* square_server.c */
#include <rpc/rpc.h>
#include <string.h>
#include "square.h"

int *moresa_check_substring_1_svc(struct moresa_string_pair *pair, struct svc_req *rqstp) {
    static int result; /* Static for RPC */

    /* Extract strings from the struct */
    char *s1 = pair->str1;
    char *s2 = pair->str2;

    /* Check if s1 is a substring of s2 */
    if (strstr(s2, s1) != NULL) {
        result = 1; /* True */
    } else {
        result = 0; /* False */
    }

    return &result;
}