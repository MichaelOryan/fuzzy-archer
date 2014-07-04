#include <stdio.h>

int acc[15];
int a, i;
int r1 = 0, r2 = 0, r3= 0, r4 = 0, r5 = 0, r6 = 0;

main()
{
      updateRange();
      displayRange();
      return 0;
}

void updateRange()

{
      for (i = 0; i < 15; i++)
      {
            printf("Enter an accident count <negative to end>:\n");
            scanf(" %d", &acc[i]);
            a= acc[i];
      return;
}

void displayRange()
 {
      do
      {
            if ((a >= 0) && (a <= 99))
            {r1= r1 + 1;}

            else if ((a >= 100) && (a <= 199))
            {r2 = r2 + 1;}

            else if ((a >= 200) && (a <= 299))
            {r3 = r3 + 1;}

            else if ((a >= 300) && (a <= 399))
            {r4 = r4 + 1;}

            else if ((a >= 400) && (a <= 499))
            {r5 = r5 + 1;}

            else if (a >= 500)
            {r6 = r6 + 1;}

            else if (a <= -1)
            {
                  printf("\n Range Frequency");
                  printf("\n 0-99             %d", r1);
                  printf("\n 100-199          %d", r2);
                  printf("\n 200-299          %d", r3);
                  printf("\n 300-399          %d", r4);
                  printf("\n 400-499          %d", r5);
                  printf("\n 500 or above     %d", r6);

            }
      } while (a <= -1);
      system ("pause");
      return;
}
