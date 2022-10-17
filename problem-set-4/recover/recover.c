#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // open input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    //set outfile pointer to NULL
    FILE *output = NULL;

    int buffer_sizer = 512;
    //create an array of 512 elements to store 512 bytes from the memory card
    BYTE buffer[buffer_sizer];

    //count for the amount of jpeg files found
    int count = 0;

    //string to hold a filename
    char filename[8] = {0};

    //read memory card untill the end of file
    while (fread(buffer, sizeof(BYTE)*buffer_sizer, 1, input) == 1)
    {
        //check if jpeg is found
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            //close outptr if jpeg was found before and written into ###.jpg
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(filename, "%03d.jpg", count++);

            //open a new outptr for writing a new found jpeg
            output = fopen(filename, "w");
        }

        //keep writing to jpeg file if new jpeg is not found
        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE)*buffer_sizer, 1, output);
        }
    }


    // close last opened outptr
    if (output != NULL)
    {
        fclose(output);
    }

    //close input file
    fclose(input);

    return 0;

}