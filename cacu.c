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
#include<unistd.h>

int main()
{   
    char what_ever;
    char n_num[10], o_num[10];
    double ans, f_num;
    char type;
    int i, u;
   
    system("clear");
  
    while(1)
    { 
    printf(BLUE"DO YOU WANT TO CACULATE: "RESET);
    scanf("%c",&what_ever);
    getchar();
    
    if(what_ever == 'n')
        for(u=0;u<=10;u++)
        {
            printf("\nI don't want to do any caculation HAHAHAHA\n\n");
            sleep(1);
        }
    if(what_ever == 'y')
    {
        printf("" BLUE "\t\tWHELCOME TO CACULATOR\n");
        printf("\t\tPLS DO YOUR CACULATION:\n\n"RESET);
        printf(">>>  ");  
     
        scanf("%lf",&ans);
     
       
        while(type != 'q')
        {   
            scanf("%c", &type);
            scanf("%s", o_num); 
            getchar();   
      
            if (type == '+' || type == '-' || type == '*' || type == '/' || type == 'q')
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
                    f_num = ans;
                }
                else
                {
                    printf(RED"\nERROR: THERE IS NO SUCH FUNCTION\n");
                    printf("PLEASE INPUT ONE MORE TIME\n\n"RESET);
                    strcpy(n_num, "no");
                    printf(">>>  ");
                }  
         
                if (o_num[0] != 'a')
                    f_num = atof(n_num);
         
                if (f_num)
                {
                    /* 三角関数 */
                    if (!atof(&o_num[0]))
                    {   
                        switch(o_num[0])
                        {
                            case 's':
                                f_num = sin(f_num*PI/180);
                                break;
                     
                            case 'c':
                                f_num = cos(f_num*PI/180);
                                break;
                      
                            case 't':
                                f_num = tan(f_num*PI/180);
                                break;
                     
                            case '!':
                                for (i = 1, u = f_num; i < u; i++)
                                {
                                    f_num *= i;
                                }
                                break;
                       
                            case 'l':
                                f_num = log(f_num);
                                break;
                        }
                    }
             
                    /* 四則演算 */
                    switch(type)
                    {      
                        case '+':
                        ans += f_num;        
                        break;
                  
                        case '-':
                            ans -= f_num;
                            break; 
                 
                        case '*': 
                            ans *= f_num;
                            break;
                 
                        case '/': 
                            ans /= f_num;
                            break; 
                 
                    }   
             
                    if(type != 'q')  
                        printf(YELLOW"\t\t = %lf\n\n"RESET, ans);
                    f_num = 0;   
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
    }
    if (what_ever == 'b')
        return 0;
    }
}
