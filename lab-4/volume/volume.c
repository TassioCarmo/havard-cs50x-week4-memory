// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    // TODO: Copy header from input file to output file

    // Creates a place in the memory to read the header of the size 44
    uint8_t header[HEADER_SIZE];

    //size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    /* ptr, which is the address (of the first byte) of memory into which to read the data,
    *  size, which is the size (in bytes) of the type of data to read,
    *  nmemb, which is the number of those types to read at once, and
    *  stream, which is the pointer to a FILE returned by fopen.
    */

    //Reads headersize bytes reads into the header
    fread(header, sizeof(header), 1, input);
    //writes the content of the header into the output file
    fwrite(header, sizeof(header), 1, output);


    // TODO: Read samples from input file and write updated data to output file
    //16-bit integer
    int16_t buffer;

    //read from the input file into the buffer passing the address of the buffer, reading a sample of 16bits(2bytes)
    //Repeatily reading a sample until reaches the end of the file returning 0 when it ends
    while (fread(&buffer, sizeof(buffer), 1, input))
    {
        //change volume by multipling the buffer value by the input
        buffer *= factor;
        fwrite(&buffer, sizeof(buffer), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}

