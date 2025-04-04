#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 10
#define MAX_INPUT 256

char judges_array[MAX_JUDGES][MAX_INPUT];

void enter_judge_info(int total_judges) {
    for (int i = 0; i < total_judges; i++) {
        printf("Judge %d: ", i + 1);
        fgets(judges_array[i], MAX_INPUT, stdin);
        judges_array[i][strcspn(judges_array[i], "\n")] = 0; // Remove newline
    }
}

void display_judge_info(int total_judges, char *project_name) {
    printf("####################################\n");
    printf("#        Display Judge Data        #\n");
    printf("####################################\n");
    for (int i = 0; i < total_judges; i++) {
        printf("[Judge %d]\n%s\n-----------------------------------\n", i + 1, judges_array[i]);
    }
}

int main() {
    char project_name[MAX_INPUT];
    int total_judges, selected_members;
    
    printf("####################################\n");
    printf("#      Judge List Data Entry      #\n");
    printf("####################################\n");
    
    printf("Participating Project: ");
    fgets(project_name, MAX_INPUT, stdin);
    project_name[strcspn(project_name, "\n")] = 0;
    
    printf("Total Number of Judges: ");
    scanf("%d", &total_judges);
    printf("Number of Selected Members: ");
    scanf("%d", &selected_members);
    getchar(); // Consume newline
    
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Starting to input information for %d judges.\n", total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");
    
    enter_judge_info(total_judges);
    
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Judge information entry is complete.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    
    char choice;
    printf("%s Should we check the judge information? (Y/N): ", project_name);
    scanf(" %c", &choice);
    
    if (choice == 'Y') {
        display_judge_info(total_judges, project_name);
    }
    
    return 0;
}
