#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CANDIDATES 6
#define CURRENT_YEAR 2025

// Function to calculate age from birth year
int calculate_age(int year) {
    return CURRENT_YEAR - year;
}

int main() {
    char group_name[50];
    char candidate01[6][100], candidate02[6][100], candidate03[6][100],
         candidate04[6][100], candidate05[6][100], candidate06[6][100];
    char *member_info[NUM_CANDIDATES][11] = {
        candidate01, candidate02, candidate03, candidate04, candidate05, candidate06
    };
    
    printf("Enter audition group name: ");
    fgets(group_name, sizeof(group_name), stdin);
    group_name[strcspn(group_name, "\n")] = 0; // Remove newline character
    
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("\n####################################\n");
        printf("[%s] Audition Candidate Data Entry\n", group_name);
        printf("####################################\n");
        printf("Entering information for candidate %d.\n", i + 1);
        
        printf("1. Name: "); fgets(member_info[i][0], 100, stdin);
        printf("2. Date of Birth (YYYY/MM/DD format): "); fgets(member_info[i][1], 100, stdin);
        printf("3. Gender (F for Female, M for Male): "); fgets(member_info[i][2], 100, stdin);
        printf("4. Email: "); fgets(member_info[i][3], 100, stdin);
        printf("5. Nationality: "); fgets(member_info[i][4], 100, stdin);
        printf("6. BMI: "); fgets(member_info[i][5], 100, stdin);
        printf("7. Primary Skill: "); fgets(member_info[i][6], 100, stdin);
        printf("8. Secondary Skill: "); fgets(member_info[i][7], 100, stdin);
        printf("9. Korean Proficiency Level (TOPIK): "); fgets(member_info[i][8], 100, stdin);
        printf("10. MBTI: "); fgets(member_info[i][9], 100, stdin);
        printf("11. Introduction: "); fgets(member_info[i][10], 100, stdin);
    }
    
    printf("\n####################################\n");
    printf("[%s] Audition Candidate Data Review\n", group_name);
    printf("####################################\n");
    printf("=============================================================================================\n");
    printf("Name          | DOB       | Age | Gender | Email                 | Nationality | BMI  | Primary Skill | Secondary Skill | TOPIK | MBTI |\n");
    printf("=============================================================================================\n");
    
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        int birth_year;
        sscanf(member_info[i][1], "%4d", &birth_year);
        int age = calculate_age(birth_year);
        
        printf("%-13s | %-8.8s | %-3d | %-6s | %-22s | %-11s | %-4s | %-13s | %-16s | %-5s | %-4s |\n",
               member_info[i][0], member_info[i][1], age, member_info[i][2],
               member_info[i][3], member_info[i][4], member_info[i][5], member_info[i][6],
               member_info[i][7], member_info[i][8], member_info[i][9]);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s\n", member_info[i][10]);
        printf("---------------------------------------------------------------------------------------------\n");
    }
    
    return 0;
}
