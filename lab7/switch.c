#include <stdio.h>
int main() // program zliczania cyfr i innych znakĂłw we wczytywanym napisie
{
  int i, nwhite=0, nother=0; // zmienne do zliczania
  int ndigit[10]={0}; // w tym tablica inicjowana zerami

  int c; // c definiowane jako int bo EOF niekoniecznie jest znakiem
  while( (c = getchar()) != EOF) { // wczytywanie kolejnych znakĂłw aĹź do EOF
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
    || c == '6' || c == '7' || c == '8' || c == '9')
    {
      ndigit[c-'0']++;
    } 
      // printf("%c, %d,  %d\n", c, c-'0', ndigit[c-'0']); - wydruk kontrolny
      // (istniejÄ specjalne konstrukcje uĹatwiajÄce sprawdzanie na bieĹźÄco
      // poprawnoĹci programu (np. assert, static_assert) )
    else if (c == ' ' || c == '\n' || c == '\t')
    {
      nwhite++;
    }
    else
    {
      nother++;
    }
    }
  
  printf("\ndigits:\n");  
  for (i = 0; i < 10; i++) printf("'%d' = %d\n", i, ndigit[i]);
  printf("white space = %d\nother =  %d\n", nwhite, nother);
  return 0;
}
