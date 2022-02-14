#include <iostream>
#include <fstream>
#include <signal.h>
#include "FileStream.hpp"

FileStream::FileStream(std::string filename) : filename(filename) {}

void FileStream::Create(std::string text)  const
{
    std::fstream output_fstream;

    output_fstream.open(filename, std::ios_base::out);
    if (!output_fstream.is_open()) {
        std::cerr << filename << ": Wrong path\n";
    } else {
        output_fstream << text << std::endl;
    }
}

void FileStream::AppendOrCreate(std::string text) const
{
    std::fstream output_fstream;

    output_fstream.open(filename, std::ios_base::app);
    if (!output_fstream.is_open()) {
        std::cerr << filename << ": Wrong path\n";
    } else {
        output_fstream << text << std::endl;
    }
}