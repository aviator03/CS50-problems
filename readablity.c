#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_words(string text);
int count_sentences(string text);
int count_letters(string text);
int cli(int words, int letters, int sentences);

// main
int main(void)
{
    string text = get_string("Text: ");
    int sentences = count_sentences(text);
    int letters = count_letters(text);
    int words = count_words(text);
    int grade = cli(words, letters, sentences);
    if (grade < 1)
    {
        printf("Grade below 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    // printf("letters: %i\twords: %i\tsentences: %i\n", letters, words, sentences);
}

// leters
int count_letters(string text)
{
    int text_len = strlen(text);
    int letters = 0;
    for (int i = 0; i < text_len; i++)
    {
        char text_char = (int) text[i];
        if (isalnum(text_char)/*text_char != 32 && text_char != 33 && text_char != 46 && text_char != 63*/)
        {
            letters++;
        }
    }
    return letters;
}

// words
int count_words(string text)
{
    int text_len = strlen(text);
    int spaces = 0;
    for (int i = 0; i < text_len; i++)
    {
        char text_char = (int) text[i];
        if (isblank(text_char))
        {
            spaces++;
        }
    }
    int words = spaces + 1;
    return words;
}

//  sentences
int count_sentences(string text)
{
    int text_len = strlen(text);
    int sentences = 0;
    for (int i = 0; i < text_len; i++)
    {
        char text_char = (int) text[i];
        if (text_char == 33 || text_char == 46 || text_char == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

// coleman-liau index
int cli(int words, int letters, int sentences)
{
    float col_L = (float)(letters / words) * 100.00;
    float col_S = (float)(sentences / words) * 100.00;
    float cli = (0.0588 * col_L) - (0.296 * col_S) - 15.8;
    int grade = round(cli);
    return grade;
}
