#include <string>
#include <iostream>
#include "FileStream.hpp"
#include "tclap/CmdLine.h"

int main(int argc, char** argv)
{
	try { 

        // Define command line object 
        TCLAP::CmdLine cmd("Analogue of the tee command", ' ', "0.1");
        
        // Set up arguments
        TCLAP::UnlabeledValueArg<std::string> filenameArg("filename","Path to a file", true, "file", "string", cmd);
        TCLAP::SwitchArg reverseSwitch("a","append","Appends input to existing file", cmd, false);

        // Parse arguments 
        cmd.parse( argc, argv );
        std::string filename = filenameArg.getValue();
        bool appendFlag = reverseSwitch.getValue();

        // Read user input
        std::string line;
        std::string output;
        while(std::getline(std::cin, line))
            output += line + "\n";

        // Define filestream object
        FileStream filestream(filename);
        
        if ( appendFlag ) {
            filestream.AppendOrCreate(output);
        }
        else {
            filestream.Create(output);
        }
        
        // Print user input
        std::cout << output << std::endl;


    } catch (TCLAP::ArgException &e) { // catch exceptions 
            std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; 
    }
}