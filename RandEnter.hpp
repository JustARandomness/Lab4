#include <iostream>
#include <cstring>

int RandEnterInt() {
    int sign = rand() % 3;
    if (sign > 1) {
        return rand() % 100 + 1;
    }
    else {
        return (rand() % 100 + 1) * (-1);
    }
}

double RandEnterDouble() {
    int sign = rand() % 3;
    if (sign > 1) {
        return double(rand() % 2000) / 1000.0 + rand() % 10;
    }
    else {
        return (double(rand() % 2000) / 1000.0 + rand() % 10) * (-1);
    }

}
