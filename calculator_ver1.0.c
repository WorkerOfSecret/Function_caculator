// File Name: caculator_ver1.0.c

#define PI 3.1415926

//ANSI_COLOR
#define RED    "\x1b[31m"
#define BLUE   "\x1b[34m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


int main()
{   
    char n_num[10], o_num[10];
    double ans, full_num;
    char type;
    int i, u;
 
    system("clear");
    printf("" BLUE "\t\t    WHELCOME TO CACULATOR\n");
    printf("\t\t    PLS DO YOUR CACULATION:\n");
    printf("\t\t( USE qq TO EXIT THE PROGRAM )\n\n"RESET);
    printf(">>>  ");  
   
    scanf("%lf",&ans);
 
    
    while(type != 'q')
    {   
        scanf("%c", &type);
        scanf("%s", o_num); 
        getchar();   
     
        if (type == '+' || type == '-' || type == '*' || type == '/' || type == '^' || type == 'q')
        {  
            if (atof(&o_num[0]))
            {
                strcpy(n_num, o_num); 
            }
            else if (o_num[0] == 's' || o_num[0] == 'c' || o_num[0] == 't' || o_num[0] == '!' || o_num[0] == 'l' || o_num[0] == 'q')
            {  
                strcpy(n_num, &o_num[1]);
              
                for(i = 2; i < (strlen(o_num) - 1); i++)
                {   
                    strcat(n_num, &o_num[i]);
                }
            }
            else if (o_num[0] == 'a')
            {
                full_num = ans;
            }
            else
            {
                printf(RED"\nERROR: THERE IS NO SUCH FUNCTION\n");
                printf("PLEASE INPUT ONE MORE TIME\n\n"RESET);
                strcpy(n_num, "no");
                printf(">>>  ");
            }  
         
            if (o_num[0] != 'a')
                full_num = atof(n_num);
         
            if (full_num)
            {
                /* 三角関数 */
                if (!atof(&o_num[0]))
                {   
                    switch(o_num[0])
                    {
                        case 's':
                            full_num = sin(full_num*PI/180);
                            break;
                     
                        case 'c':
                            full_num = cos(full_num*PI/180);
                            break;
                      
                        case 't':
                            full_num = tan(full_num*PI/180);
                            break;
                     
                        case '!':
                            for (i = 1, u = full_num; i < u; i++)
                            {
                                full_num *= i;
                            }
                            break;
                       
                        case 'l':
                            full_num = log(full_num);
                            break;
                    }
                }
             
                /* 四則演算 */
                switch(type)
                {      
                    case '+':
                        ans += full_num;        
                        break;
                 
                    case '-':
                        ans -= full_num;
                        break; 
                 
                    case '*': 
                        ans *= full_num;
                        break;
                 
                    case '/': 
                        ans /= full_num;
                        break; 
                  
                    case '^':
                        ans = powl(ans, full_num);
                        break;
                 
                }   
             
                if(type != 'q')  
                    printf(YELLOW"\t\t = %lf\n\n"RESET, ans);
                full_num = 0;   
                printf(">>>  ");
            }
        }
        else
        {
            printf(RED "\nERROR: THERE IS NO SUCH OPERATOR\n");
            printf("PLEASE INPUT ONE MORE TIME\n\n"RESET);
            printf(">>>  ");
        }
    }
    return 0;
}
