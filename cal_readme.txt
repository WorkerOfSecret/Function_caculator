This is a simple caculator that can do simple caculate with +, -, /, *, answer, sin, cos, tan, 
factorial and log created in Ubuntu


I have to say it is a little bit different from normal caculator in the way you input the number and others things


First:
    To compile the file use the command: gcc -o caculator_ver1.0 caculator_ver1.0 -lm


Second:
  You can only input :
    Caculator_ver1.0 is a simple program for caculator with +, -, *, /, sin, cos, tan, 
    factorial, log function and caculate with the answer. 
 
  It is a little bit different from normal caculator because of the way it is inputed and 
  few functions.
 
  At the first time you input the caculation:
    You can only input two numbers and one operator ( '+', '-', '*', '/') at the first time you 
    ativate it
   
    For example: 
      "6+10", "10/s45" (put a word 's', 'c', 't', 'a', '!', 'l' in front of the number to 
      activate the sin, cos, tan, answer, factorial, log function)
 

Third:
   After the first time you can only input an operator and a number to keep caculating your 
   caculation
   
   For example: 
      "-c60" ( - cos(60) ), "*l10" ( * log(10) ), "-a ( - the last answer)"
   
   If you want to do a new caculation please input : "*0" or '-a' to make a new one
 

Fourth:
   I putted two debugs inside of the program so if you don't follow the Second and the Third it 
   will output the ERRORS
   
   For example:
     If you input something that isn't an operator between two numbers or in front of the number
      after first input it will give back a message like this: 
        "ERROR: THERE IS NO SUCH OPERATOR PLEASE INPUT ONE MORE TIME" 
      
      and a anothere message if you try messing with the number (For ex: "-adskda121") 
      it will give back another message like this: 
        "ERRORS: THERE IS NO SUCH FUNCTION PLEASE INPUT ONE MORE TIME"


Final:
   I am making a normal caculator like those apps in smart phone or computer so there will be more update
