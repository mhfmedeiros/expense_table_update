
# Expense Table

This project is a C program for recording and managing personal expenses in a CSV file. It allows the user to create a table of expenses categorized by date, type, description, and amount, making it easier to keep track of personal finances.

## Features

- **Expense Entry**: Records each entry with date, category, description, and amount.
- **Predefined Categories**: Includes nine categories for common expenses like Rent, Food, and Education.
- **CSV Storage**: Saves data in a CSV format, allowing compatibility with spreadsheet programs for easy viewing and analysis.

## Prerequisites

To compile and run the program, you will need a C compiler like `gcc`.

## Data Structure

Each expense entry is stored using the following fields:

- `date`: Date of the expense, in the format "mm/dd/yyyy".
- `category`: A number between 1 and 9 indicating the expense category.
- `description`: A short description of the expense, up to 300 characters.
- `amount`: The expense amount (use a comma `,` for decimal separation, if applicable).

## Usage

1. Clone the repository and navigate to the project directory:

   ```bash
   git clone https://github.com/mhfmedeiros/expense_table_update.git
   cd expense_table
