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
    uint8_t header[HEADER_SIZE];

    /* Reads from 'input' to 'header' */
    fread(header, 1, HEADER_SIZE, input);

    /* Writes from 'header' to 'output' */
    fwrite(header, 1, HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;

    /* Loops as long as 'fread' is able to read one 'int16_t' value from the 'input' file;
    Then, 'fread' stores the value it reads into 'buffer' */
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        /* Multiplies the value that was read from 'input' */
        buffer *= factor;
        /* Writes the modified value from 'buffer' to 'output';
        It's done one 'int16_t' value at a time */
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}
