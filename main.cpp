#include <iostream>
#include "AutoFile.h"
#define ADDR_MAX_VOLUME 128
static int gpu_addrs[ADDR_MAX_VOLUME]={-1};

int main() {
    AutoFile file("example.txt");
    file.write("q1w2\nass\n");
    // Пример чтения первых 3 строк из файла
    std::string lines = file.readLines(3);
    std::cout << "Прочитанные строки из файла:\n" << lines;
    for (int i = 0; i<ADDR_MAX_VOLUME; i++)
        printf("|%d|\n", gpu_addrs[i]);
    return 0;
}