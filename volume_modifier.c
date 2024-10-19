#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1; // Exit if the arguments are incorrect
    }

    // Open the input audio file in read mode
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1; // Exit if the input file cannot be opened
    }

    // Open the output audio file in write mode
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input); // Close input file before exiting
        return 1; // Exit if the output file cannot be opened
    }

    // Convert the scaling factor from string to float
    float factor = atof(argv[3]);

    // Read the .wav header from the input file
    uint8_t header[HEADER_SIZE];
    fread(header, 1, HEADER_SIZE, input); // Read header bytes

    // Write the header to the output file
    fwrite(header, 1, HEADER_SIZE, output);

    // Variable to store audio samples
    int16_t buffer;

    // Loop to read and process each audio sample
    // Continues until no more samples can be read from the input file
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Adjust the volume by multiplying the sample with the scaling factor
        buffer *= factor;

        // Write the modified sample to the output file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close both input and output files to release resources
    fclose(input);
    fclose(output);

    return 0; // Indicate successful completion
}
