#include "AutoFile.h"

AutoFile::AutoFile(const std::string& filename) {
    // Открытие файла при создании объекта
    file.open(filename, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла " << filename << std::endl;
    }
}

AutoFile::~AutoFile() {
    // Закрытие файла при уничтожении объекта
    if (file.is_open()) {
        file.close();
    }
}

void AutoFile::write(const std::string& data) {
    if (file.is_open()) {
        file << data;
    } else {
        std::cerr << "Файл не открыт для записи" << std::endl;
    }
}

std::string AutoFile::read() {
    std::string data;
    if (file.is_open()) {
        file.seekg(0, std::ios::beg);  // Установка указателя файла в начало
        std::getline(file, data);      // Чтение строки из файла
    } else {
        std::cerr << "Файл не открыт для чтения" << std::endl;
    }
    return data;
}

std::string AutoFile::readLines(int count) {
    std::string lines;
    std::string line;
    int linesRead = 0;

    if (file.is_open()) {
        file.clear();  // Сброс флагов ошибок
        file.seekg(0, std::ios::beg);  // Установка указателя файла в начало

        while (std::getline(file, line) && linesRead < count) {
            lines += line + "\n";  // Добавление прочитанной строки в общий результат
            linesRead++;
        }
    } else {
        std::cerr << "Файл не открыт для чтения" << std::endl;
    }

    return lines;
}