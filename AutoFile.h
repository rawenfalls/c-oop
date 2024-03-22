#ifndef AUTOFILE_H
#define AUTOFILE_H

#include <iostream>
#include <fstream>
#include <string>

class AutoFile {
private:
    std::fstream file;

public:
    AutoFile(const std::string& filename);

    ~AutoFile();

    void write(const std::string& data);

    std::string read();

    std::string readLines(int count);
};

#endif // AUTOFILE_H