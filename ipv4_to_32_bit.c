#include <stdio.h>

int main(void) {
    // Declare variables to hold the individual octets of the IP address
    unsigned long a = 0, b = 0, c = 0, d = 0, ip = 0;

    // Read the four octets of the IP address from user input
    scanf("%lu", &a); 
    scanf("%lu", &b); 
    scanf("%lu", &c); 
    scanf("%lu", &d);

    // Check if all octets are within the valid range for IP addresses (0-255)
    if (a >= 0 && a <= 256 && b >= 0 && b <= 256 && c >= 0 && c <= 256 && d >= 0 && d <= 256) {
        // Calculate the 32-bit representation of the IP address
        ip = ((a * 256 * 256 * 256) + (b * 256 * 256) + (c * 256) + d);
        
        // Print the human-readable format of the IP address
        printf("Human-readable IP address is: %lu.%lu.%lu.%lu\n", a, b, c, d);
        
        // Print the IP address as a 32-bit number
        printf("IP address as a 32-bit number: %lu\n", ip);
        
        return 0; // Successful execution
    } else {
        // Inform the user that the provided IP address is incorrect
        puts("Incorrect IP Address.");
        return 1; // Indicate failure
    }
}
