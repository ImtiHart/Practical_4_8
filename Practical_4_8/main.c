#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*Develop a welcome to CPUT Sports Hub form using the C program. request a user to enter
login details and check that the username entered contains "@mycput.ac.za", and the
password entered has at least a string of eight characters, which must include a special
character. Using pointers, ensure you create a separate function to check for the username
and password login requirements.*/
int i, j;

int check(char* s, char* username) {/*Identify if a string is found in a string*/
    int s_len = strlen(s);
    int u_len = strlen(username);

    for (i = 0; i <= u_len - s_len; i++)
        {
        for (j = 0; j < s_len; j++) {
            if (username[i + j] != s[j]) {
                break;
            }
        }

        if (j == s_len) {
            return 1;
        }
    }

    return 0;
}

bool check2(char *code)
{
  int length = strlen(code);/*Identify if code is long enough*/
  if (length < 8)
  {
      return false;
  }
  bool has_digit = false;
  bool has_symbol = false;

  for (int i = 0; i < length; i++) /*Check if passcode meets requirments*/
  {
    if (isdigit(code[i]))
    {
        has_digit = true;
    }

    if (ispunct(code[i]))
    {
        has_symbol = true;
    }
  }
  if (!has_digit)
  {
      return false;
  }
  if (!has_symbol)
  {
      return false;
  }
  return true;
}
int main() {

    char s[] = "@mycput.ac.za";
    char username[50];
    printf("Enter your username: \n");
    scanf("%s", username);
    if (check(s, username)) { /*Display username outcome*/
        printf("'@mycput.ac.za' is located in string\n");
    } else {
        printf("ERROR\n");
    }
    char code[]="Ax5@abcdefg"; /*provide passcode*/
    bool result = check2(code);
    if (result) /*Display passcode outcome*/
    {
        printf("Passcode meets requirments\n");
    }
    else
    {
        printf("ERROR\n");
    }
    return 0;
}


