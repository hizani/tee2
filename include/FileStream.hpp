#pragma once

#include <string>

// FileStream class provides simplified interface for writing
// text into files
class FileStream {
public:
    FileStream(std::string);
    
    // Appends string to an existing file or writes it to a new 
    // one if a file does not exist
    void AppendOrCreate(std::string) const;
    
    // Creates file and writes string to it
    void Create(std::string) const; 

private:
    std::string filename;
};