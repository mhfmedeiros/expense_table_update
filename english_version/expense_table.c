#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines a constant MAX with value 300
#define MAX 300

// Creates a data structure to store the attributes of each entry and defines a new type "Data"
typedef struct
{
    char date[13];
    int category;
    char description[MAX];
    char amount[MAX];
} Data;

/* This program receives 2 command-line arguments: ./expense_table <file_name>.
   The file needs to be a .csv with semicolon ';' as delimiter, preferably with header titles.
   The program will prompt the user for the number of data entries they wish to add and then 
   will record each entry in the specified .csv file, line by line, before exiting. */
int main(int argc, char *argv[])
{
    // Checks if the user entered the correct number of arguments and exits with an error message if not
    if (argc != 2)
    {
        printf("ERROR!\n");
        printf("Usage: ./expense_table <file_name>\n");
        return 1;
    }

    // Opens the file to append data and assigns its address to a pointer of type FILE
    FILE *table = fopen(argv[1], "a");

    // Checks if the file opened successfully and exits with an error message if not
    if (table == NULL)
    {
        printf("ERROR!\n");
        printf("Memory issue!\n");
        return 2;
    }

    // Creates an array of strings with each available expense category for registration
    char *categories[9] = {"Rent", "Essential Services", "Food", "Transportation", "Education", "Leisure", "Trips", "Medicines", "Healthcare"};
    
    // Declares two variables, x and y, to store the number of data entries and the \n character, respectively
    int x;
    char y;
    printf("\n\t\t\t\t\tWelcome!\n\nHow many entries do you want to insert into the table? (type a positive number and press ENTER): ");
    scanf("%i", &x);
    scanf("%c", &y);

    // Checks if the user entered a valid number of entries and exits with an error message if not
    if (x <= 0)
    {
        printf("ERROR!\nType a positive number!\n");
        fclose(table);
        return 3;
    }

    // Records the x entries provided by the user in the specified file
    for (int i = 0; i < x; i++)
    {
        // Allocates memory for each entry provided by the user
        Data *data = malloc(sizeof(Data));

        // Checks if memory was allocated correctly and exits with an error message if not
        if (data == NULL)
        {
            printf("ERROR!\nMemory allocation issue!\n");
            fclose(table);
            return 4;
        }

        // Receives the expense date in a specific format, requiring the user to enter it exactly as shown
        printf("\nEnter the date of your expense (use this format: mm/dd/yyyy) and press ENTER: ");
        fgets(data->date, 13, stdin);

        // Removes the \n at the end of the string to prevent printing issues
        data->date[strlen(data->date) - 1] = '\0';

        // Checks if the date was entered correctly and exits with an error message if not
        if (strlen(data->date) != 10)
        {
            printf("ERROR!\nEnter the date correctly!\n");
            free(data);
            fclose(table);
            return 5;
        }

        // Receives the expense category the user wants to register
        printf("\nEnter the corresponding number for your expense category and press ENTER:\n\n"
                "1 - Rent\n"
                "2 - Essential Services\n"
                "3 - Food\n"
                "4 - Transportation\n"
                "5 - Education\n"
                "6 - Leisure\n"
                "7 - Trips\n"
                "8 - Medicines\n"
                "9 - Healthcare\n\n");
        printf("Enter: ");
        scanf("%i", &data->category);
        
        // Reads the \n character again
        scanf("%c", &y);

        // Checks if a valid number was entered for the expense category and exits with an error message if not
        if (data->category < 1 || data->category > 9)
        {
            printf("ERROR!\nEnter a number between 1 and 9!\n");
            free(data);
            fclose(table);
            return 5;
        }

        // Receives a brief description of the expense
        printf("\nEnter a short description of your expense (maximum 300 characters) and press ENTER: ");
        fgets(data->description, MAX, stdin);

        // Removes the \n at the end of the string to prevent printing issues
        data->description[strlen(data->description) - 1] = '\0';

        // Checks if the description was entered correctly and exits with an error message if not
        if (strlen(data->description) == 0)
        {
            printf("ERROR!\nEnter the description correctly\n");
            free(data);
            fclose(table);
            return 5;
        }
        else if (strlen(data->description) == MAX - 2)
        {
            printf("ERROR!\nEnter fewer characters\n");
            free(data);
            fclose(table);
            return 6;
        }

        // Receives the expense amount
        printf("\nEnter the amount spent (a positive number, with a comma ',' separating the integer and decimal parts, if applicable) and press ENTER: ");
        fgets(data->amount, MAX, stdin);

        // Removes the \n at the end of the string to prevent printing issues
        data->amount[strlen(data->amount) - 1] = '\0';

        // Checks if the amount was entered correctly and exits with an error message if not
        if (strlen(data->amount) == 0)
        {
            printf("ERROR!\nEnter the amount correctly!\n");
            free(data);
            fclose(table);       
            return 5;
        }
        else if (strlen(data->amount) == MAX - 2)
        {
            printf("ERROR!\nEnter fewer characters\n");
            free(data);
            fclose(table);
            return 6;
        }

        // Inserts the data entry into the specified file
        fprintf(table, "%s;%s;%s;%s\n", data->date, categories[data->category - 1], data->description, data->amount);

        // Frees the allocated memory
        free(data);
    }

    // Closes the file and returns 0
    fclose(table);
    return 0;
}