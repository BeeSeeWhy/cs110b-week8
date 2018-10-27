#include <iostream>
using namespace std;

void _strcpy(char *dest, const char *src);
void _strcpy2(char *dest, const char *src);
int _strlen(const char* str);
int _strcmp(const char* str1, const char* str2);
char* _strstr(const char *str1, const char *str2);
void _strcat(char* str1, const char* str2);
void _strncpy(char* dest, const char* src, int n);
int _strncmp(const char* str1, const char* str2, int n);
void _strncat(char* str1, const char*, int n);

int main() {

    const char* mysource = "demon king";
    const int SIZE = 100;
    const int NUM_OF_CHARACTERS = 5;
    char mydestination[SIZE];
    char mynewdestination[SIZE];

    //string copy
    _strcpy (mydestination, mysource);
    cout << "_strcpy: " << mydestination << endl;

    //string copy
    _strcpy2 (mydestination, mysource);
    cout << "_strcpy2: " << mydestination << endl;

    //string length
    int l = _strlen (mydestination);
    cout << "_strlen: " << l << endl;

    const char *s1 = "tricksters";
    const char *s2 = "trickster";

    //string compare
    cout << "S1 & S2 compare as follows: " << _strcmp (s1, s2) <<endl;

    //string concatenate
    char s3[SIZE] = "super ";
    _strcat (s3, s2);

    cout << "_strcat: " << s3 << endl;

    /*char *test_s1 = (char*) s1;
    cout << "_strcat test: " << _strcat (test_s1, s2) << endl;*/

    //sub string within string
    char *strstr_result = _strstr (s1, s2);
    if (strstr_result == NULL)
        cout << "_strstr: substring not found in string" << endl;
    else
        cout << "_strstr: " << strstr_result << endl;

    //test for _strstr NULL case
    /*const char *s5 = "trickster";
    const char *s6 = "tricksters";
    char *strstr_result2 = _strstr (s5, s6);
    if (strstr_result2 == NULL)
        cout << "_strstr: substring not found in string" << endl;
    else
        cout << "_strstr: " << _strstr (s5, s6) << endl;*/

    //string copy only nth elements
    _strncpy (mynewdestination, mysource, NUM_OF_CHARACTERS);
    cout << "_strcpy only 5 characters: " << mynewdestination << endl;

    //string compare only nth elements
    cout << "S1 & S2 first 5 characters compare as follows: ";
    cout << _strncmp (s1, s2, NUM_OF_CHARACTERS) << endl;

    //string concatenate only nth elements
    char another_string[SIZE] = "tricksters";
    char *s4 = another_string;
    _strncat (s4, s2, NUM_OF_CHARACTERS);

    cout << "_strncat only five characters: " << another_string << endl;

    return 0;
}

// example of string copy operation
void  _strcpy (char *destination, const char *source) {

    int i = 0;
    while (source[i]) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

//more elegant implementation of string copy
void _strcpy2 (char *destination, const char *source) {

   //check if source is not null and destination is not null
   while (*destination++ = *source++);
}

//example implementation of string length.
int _strlen (const char* str) {

    int len = 0;
    while (*str++) len++;

    return len;
}

//example implementation of string compare
int _strcmp (const char* s1, const char* s2) {

 while (*s1 && (*s1 == *s2)) {
     s1++;
     s2++;
 }

 return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

//Fill in this method so that calling _strcat can append s2 contents to s1
void _strcat (char* s1, const char* s2) {
  int i;
  int len = _strlen (s1);
  int len2 = _strlen (s2);

  for (i = 0; i < len2 + 1; i++) {
    s1[i + len] = s2[i];
  }
  s1[i + len] = '\0';
}

//check if string s2 is inside or embedded within string s1
char* _strstr (const char *s1, const char *s2) {
  while (*s1) {
 		    char *begin = (char*) s1;
 		    char *pattern = (char*) s2;

 		    // If first character of sub string match, check for whole string
 		    while (*s1 && *pattern && *s1 == *pattern) {
 			      s1++;
 			      pattern++;
 		    }
 		    // If complete sub string match, return starting address
 		    if (!*pattern)
 		    	  return begin;

        // If s1 string is out of characters and pattern not there
        if (!*s1)
            return NULL;
 		    s1 = begin + 1;	// Increment main string
 	  }
 	  return NULL;
}

// _strcpy for specified number of characters n.
void _strncpy (char *s1, const char* s2, int n) {
  int i = 0;
  while (s2[i] && (i < n)) {
      s1[i] = s2[i];
      i++;
  }
  s1[i] = '\0';
}

// _strcmp for specified number of characters n.
int _strncmp( const char* s1, const char* s2, int n) {
  int i = 0;
  while (*s1 && (*s1 == *s2) && i < n) {
       s1++;
       s2++;
       i++;
   }
   return *(const unsigned char*)s1 - *(const unsigned char*)s2;

  //another method for the same function
  /*char news1[100];
  char news2[100];
  _strncpy(news1, s1, n);
  _strncpy(news2, s2, n);

  return ( _strcmp(news1, news2) );*/
}

// _strcat for specified number of characters n.
void _strncat (char* s1, const char *s2, int n) {
  int i = 0;
  int len = _strlen (s1);
  int len2 = _strlen (s2);
  while (s2[i] != '\0' && i < n) {
    s1[i + len] = s2[i];
    i++;
  }
  s1[i + len] = '\0';
}
