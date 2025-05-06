//Author: An Luong
//Project 13

#include <stdio.h>
#include <stdbool.h>

#define MAX_GUESSES 6
#define WORD_LENGTH 5

int load_word(char *word);
bool is_valid_guess(char *guess);
void display_guesses(char guesses[MAX_GUESSES][WORD_LENGTH + 1], int guess_count);
void display_hint(char *guess, char *mystery_word);
bool check_win(char *guess, char *mystery_word);
void convert_lower_case(char *str);
int string_length(char *str);
bool is_alpha(char c);
int string_compare(char *str1, char *str2);
int string_index_of(char *str, char c);
void initialize_guesses(char guesses[MAX_GUESSES][WORD_LENGTH + 1]);

int main(){
    char mystery_word[WORD_LENGTH + 1];
    char guesses[MAX_GUESSES][WORD_LENGTH + 1];
    int guess_count = 0;

    initialize_guesses(guesses);
    load_word(mystery_word);

    while (guess_count < MAX_GUESSES)
    {
        char guess[WORD_LENGTH + 1];

        printf("Enter your guess (5 letter-word): ");
        fgets(guess, WORD_LENGTH + 1, stdin);

        // Remove newline if it exists
        if (guess[string_length(guess) - 1] == '\n') {
            guess[string_length(guess) - 1] = '\0';
        }

        if (!is_valid_guess(guess))
        {
            printf("Invalid guess! Try again.\n");
            continue;
        }

        convert_lower_case(guess);

        for (int i = 0; i < WORD_LENGTH; i++)
        {
            guesses[guess_count][i] = guess[i];
        }
        guesses[guess_count][WORD_LENGTH] = '\0';
        guess_count++;

        display_guesses(guesses, guess_count);

        if (check_win(guess, mystery_word))
        {
            printf("The correct word: %s\n", mystery_word);
            printf("You won in %d guesses.\n", guess_count);
            printf("Amazing!");
            break;
        }

        display_hint(guess, mystery_word);
    }

    if (guess_count == MAX_GUESSES)
    {
        printf("Sorry, you've used all your guesses. Try again next game\n");
    }

    return 0;
}

void display_guesses(char guesses[MAX_GUESSES][WORD_LENGTH + 1], int guess_count)
{
	printf("\nPrevious guesses: \n");
	for (int i = 0; i < guess_count; i++)
	{
		printf("%s\n", guesses[i]);
	}
	printf("\n");
}

int load_word(char *word)
{
    FILE *file = fopen("mystery.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    fscanf(file, "%s", word);
    fclose(file);
    return 0;
}

bool is_valid_guess(char *guess)
{
    if (string_length(guess) != WORD_LENGTH)
    {
        return false;
    }
    for (int i = 0; i < WORD_LENGTH; i++)
    {
        if (!is_alpha(guess[i]))
        {
            return false;
        }
    }
    return true;
}

void display_hint(char *guess, char *mystery_word)
{
    printf("Hint: \n");
    for (int i = 0; i < WORD_LENGTH; i++)
    {
        if (guess[i] == mystery_word[i])
        {
            printf("%c ", guess[i] - 'a' + 'A');
        }
        else if (string_index_of(mystery_word, guess[i]) != -1)
        {
            printf("^ ");
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

bool check_win(char *guess, char *mystery_word)
{
    return string_compare(guess, mystery_word) == 0;
}

void convert_lower_case(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 'a' - 'A';
        }
    }
}

int string_length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

bool is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int string_compare(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int string_index_of(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

void initialize_guesses(char guesses[MAX_GUESSES][WORD_LENGTH + 1])
{
    for (int i = 0; i < MAX_GUESSES; i++)
    {
        for (int j = 0; j < WORD_LENGTH + 1; j++)
        {
            guesses[i][j] = '\0';
        }
    }
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
