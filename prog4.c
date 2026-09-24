# include <stdio.h>

int main(void){

int ch;
signed char checksum = -1;
char string[20];
int char_no = 0;
 
 while ( (ch = getchar()) != EOF){
  string[char_no++] = ch;
      checksum += ch;
      if (ch == '\n'){
	break;
      }
}
 string[char_no] = '\0';
 fputs(string, stdout);
 printf("%d\n", checksum);

 return 0;
}



