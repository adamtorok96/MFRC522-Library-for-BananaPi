#include <exception>
#include "MFRC522.h"

int main() {
    printf("main()\n");

    try {
        MFRC522 mfrc;
    } catch (std::exception & e) {
        printf("Exception: %s\n", e.what());
    }

    printf("Exit\n");

    return 0;
}