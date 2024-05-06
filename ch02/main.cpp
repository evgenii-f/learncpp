#include "io.h"

int main() {
    int x { readNumber() };
    int y { readNumber() };

    int answer { computeAnswer(x, y) };

    writeAnswer(answer);
}