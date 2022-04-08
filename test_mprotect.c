#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int *p;
    p = (int *) malloc(4096 * 2);
    if (p == 0) {
        printf(1, "malloc failed\n");
        exit();
    }
    *p = 0x12345678;
    printf(1, "Protect some pages\n");
    mprotect(p, 2);
    printf(1, "Try to write to protected pages\n");
    *p = 0x12345679;
    printf(1, "Should not see this\n");
    exit();
}
