#include <stdio.h>
#include <stdlib.h>

//list - to list the code
//b - function name to creak a break point
//s - step in function
//next - next line
// continue -  continues till the end of the program

void printToScreen(char *);

int main()
{

  printToScreen("hello world\n");
  
  for(int i = 0; i < 10; i ++)
  {
    for(int j =20; j>0;j--)
    {
      printf("hello\n");
    }
  }
  printf("Test\n");
  
  return 0;

}

void printToScreen(char * toPrint)
{
  printf("%s", toPrint);
}
