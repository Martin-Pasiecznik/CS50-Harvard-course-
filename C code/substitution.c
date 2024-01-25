// create a program that enables you to encrypt messages using a substitution cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string cypher();
bool check_key();
int main(int argc, char *argv[])
{
    if (argc != 2) // checks for a command in line argumente
    {
        printf("Provide exactly one command-line argument.\n");
        return 1;
    }
    string key = get_string("Key: \n");
    bool key_is_correct = check_key(key); // ask for a key from the user.
    if (!key_is_correct)
    {
        printf("Key is incorrect, must have 26 caracters \n");
        return 1;
    } // if the key is not 26 character, return 1(error).
    string text = get_string("Plaintext: ");
    string cypher_text = cypher(key, text);
    printf("Cypher text: %s ", cypher_text);
    return 0;
}

bool check_key(char *key)
{
    bool correct_key;

    int len = strlen(key);
    if (len != 26)
        correct_key = false;
    else
        correct_key = true;
    bool control=true;
    int i=0;
    while(control || i<len){
        if(isdigit(key[i]) || ispunct(key[i]) || isspace(key[i]) ){
            control=false;
            correct_key=false;
        }
        i++;
    }
    return correct_key;
}

string cypher(char *key, char *text)
{
    wchar_t alphabet[] = {L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i', L'j', L'k', L'l', L'm', L'n',
                          L'ñ', L'o', L'p', L'q', L'r', L's', L't', L'u', L'v', L'w', L'x', L'y', L'z'};
    wchar_t alphabet_upper_case[] = {L'A', L'B', L'C', L'D', L'E', L'F', L'G', L'H', L'I', L'J', L'K', L'L', L'M', L'N',
                                    L'Ñ', L'O', L'P', L'Q', L'R', L'S', L'T', L'U', L'V', L'W', L'X', L'Y', L'Z'};
    /////lowercase the key
    for(int k=0; key[k] != '\0'; k++){
        key[k] =tolower(key[k]);
    }
    ///// cyphers the text
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
        {
            if (!isspace(text[i]) && !ispunct(text[i]))
            { // modify only lettters, no special caracters.
                while (text[i] != alphabet_upper_case[j])
                {
                    j++;
                }
                char upper_case_key = toupper(key[j]); // transforms the character into upper case.
                text[i] = upper_case_key;
                j = 0;
            }
        }
        else
        {
            if (!isspace(text[i]) && !ispunct(text[i]))
            { // modify only lettters, no special caracters.
                while (text[i] != alphabet[j])
                {
                    j++;
                }
                text[i] = key[j];
                j = 0;
            }
        }
    }
    return text;
    ///// cyphers the text
}
