#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For sleep() function

void print_splash_screen(const char* user_name, const char* date) {
    // Print the right-angled triangle on the left side
    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("   ");
        for (int j = 0; j < 53 - i; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Print the splash screen message
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("                                        [Magrathea ver 0.1]                                            \n");
    printf("                   Magrathea, where a shining planet is created in a wasteland with no grass,           \n");
    printf("           a place where unseen potential is discovered and gems are polished by the hands of experts,  \n");
    printf("                                        Welcome to Magrathea.                                         \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[User]: %s                                   [Execution Time]: %s\n", user_name, date);
    printf("=============================================================================================================\n");

    // Print the inverted right-angled triangle on the right side
    for (int i = 7; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 8 - i; j++) {
            printf("*");
        }
        printf("   ");
        for (int j = 0; j < 53 - i; j++) {
            printf(" ");
        }
        printf("*\n");
    }
}

int main() {
    char date[11]; // to hold date in yyyy-mm-dd format
    char user_name[100]; // to hold user name

    // Ask for date and name input
    printf("[Please enter the current date in the \"yyyy-mm-dd\" format]: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';  // Remove the trailing newline character

    printf("[Please enter your name]: ");
    fgets(user_name, sizeof(user_name), stdin);
    user_name[strcspn(user_name, "\n")] = '\0';  // Remove the trailing newline character

    // Confirm successful input
    printf("**The input has been processed successfully.**\n");

    // Sleep for 3 seconds
    sleep(3);

    // Clear the screen (platform-specific, assuming Unix-like system with ANSI escape sequences)
    printf("\033[H\033[J");

    // Display the splash screen with the provided input
    print_splash_screen(user_name, date);

    return 0;
}
