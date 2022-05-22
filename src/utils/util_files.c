#include "util_files.h"


char* getFileAsString(char* filepath)
{
    FILE* readFile = fopen(filepath, "r");

    //Ensure the file could be opened
    if(!readFile)
    {
        PRINT_ERROR("Could not open file");
        return NULL;
    }
    
    //Count the number of bytes in a file
    fseek(readFile, 0, SEEK_END);
    int numBytes = ftell(readFile);
    fseek(readFile, 0, SEEK_SET);

    if(numBytes == 0)
    {
        PRINT_ERROR("No information stored in file");
        fclose(readFile);
        return NULL;
    }

    char* result = (char*)malloc(numBytes * sizeof(char) + 1);

    fread(result, 1, numBytes, readFile);

    result[numBytes] = '\0';

    fclose(readFile);

    return result;
}