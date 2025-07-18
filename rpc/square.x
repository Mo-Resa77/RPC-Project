/* square.x */
struct moresa_string_pair {
    string str1<>;
    string str2<>;
};

program MORESA_SQUARE_PROG {
    version MORESA_SQUARE_VERS {
        int MORESA_CHECK_SUBSTRING(moresa_string_pair) = 1; /* Unique procedure name */
    } = 1; /* Version number */
} = 0x20000002; /* Unique program number (changed from 0x20000001) */