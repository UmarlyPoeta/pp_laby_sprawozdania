
// odwracanie napisów

for(i = 0, j = strlen(s)-1; i < j; i++, j--) {
  c = s[i];
  s[i] = s[j];
  s[j] = c;
}


// dołączanie jednego napisu na końcu innego

i = j = 0;

while (s[i] != '\0') i++; // przesunięcie na koniec s

while ( (s[i++] = t[j++]) != '\0') { } // dopisanie t


// usuwanie znaków pustych (whitespaces) z końca napisu

for (n = strlen(s)-1; n >= 0; n--){

  if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') break;

}
s[n+1] = '\0'; // nowa długość napisu wynosi n+1
