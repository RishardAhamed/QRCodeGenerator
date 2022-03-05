#include <stdio.h> // include the standard input output library
#include <string.h> //include the string library
#define SIZE 10000
#define BLACK "\e[40m"  //defining the black color 
#define WHITE "\e[47m"  //defining the white color
#define RESET "\e[0m"   //defining the reset comand
#define SCREENCLEAR "\033[2J" // defining the command to clear the screen
#define MOVECURSOR "\033[u" // defining the command to move the home or the cursor
void BinaryConverter(int BinaryArr[9],unsigned char HashedString[24],int j); //protoype for the function of decimal to binary converter
void String_Hashing (unsigned char main_URL[],unsigned char Hashed_String[]); //protype for the function of converting the input URL to hashed string
void frame(int n,char Color[6]); //prototype for the function to print the basic frame
void LowerCase(char ch[]); //protype for the function to convert uppercase to lowercase

int main (int argcon,char** argval){
char Color[6];                                  //array to store colors
unsigned char inputURL[120]; //array to store the input url
unsigned char HashedStringedSmall[24]; //array to store  the hashstringed 24 version
unsigned char HashedStringedlong[132]; //Array to store the hashstringed 132 charachters
int BinaryArr[9];               //Array to store binary numbers
  if(argcon==1){                                                             
    strcpy(Color,"\e[40m");           //Setting the default color as black if only one condition is used
  }else if (argcon==3){                                                     
  LowerCase(argval[2]);                                                      
  if(strcmp(argval[1],"-c")==0){          //assigning colors according to the user requirements                                   
    if(strcmp(argval[2],"black")==0){     //if argument value 2 is similar to black then copy the string \e[41m to the color array                             
      strcpy(Color,"\e[40m");                                                
    }else if(strcmp(argval[2],"red")==0){   //similarly the remaining color codes are copied to the color array depending on the color
      strcpy(Color,"\e[41m");
    }else if(strcmp(argval[2],"green")==0){
      strcpy(Color,"\e[42m");
    }else if(strcmp(argval[2],"yellow")==0){
      strcpy(Color,"\e[43m");
    }else if(strcmp(argval[2],"blue")==0){
      strcpy(Color,"\e[44m");
    }else if(strcmp(argval[2],"magenta")==0){
      strcpy(Color,"\e[45m");
    }else if(strcmp(argval[2],"cyan")==0){
      strcpy(Color,"\e[46m");                        // if the argument value 2 isnt equal to the given below then an error message is printed
    }else if(strcmp(argval[2],"black")!=0||strcmp(argval[2],"red")!=0||strcmp(argval[2],"green")!=0||strcmp(argval[2],"yellow")!=0||strcmp(argval[2],"blue")!=0||strcmp(argval[2],"magenta")!=0||strcmp(argval[2],"cyan")!=0){                                                                                                                                                                                                                                                                                                                                                                  
      printf("Invalid argument for color.\n");       //printing error messages for invalid argument declaration
      printf("usage :\n");
      printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argval[0]);
      printf("%s -h for the help about the program\n",argval[0]);
      return 0;
    }
  }else{
    printf("Incorrect usage of arguments.\n");
    printf("usage :\n");
      printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argval[0]);
      printf("%s -h for the help about the program\n",argval[0]);
      return 0;
  }
 }else if(argcon==2){                       //printing help command arguments
  if(strcmp(argval[1],"-h")==0){
    printf("usage :\n");
      printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argval[0]);
      printf("%s -h for the help about the program\n",argval[0]);
      return 0;

  }else{
    printf("Incorrect usage of arguments.\n");
    printf("usage :\n");
      printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argval[0]);
      printf("%s -h for the help about the program\n",argval[0]);
      return 0;

  }
 }else if(argcon>3){ // if user inputs more than 3 argument conditions then print the below error message
  printf("Incorrect usage of arguments.\n");
    printf("usage :\n");
      printf("%s -c [black|red|green|yellow|blue|magenta|cyan]\n",argval[0]);
      printf("%s -h for the help about the program\n",argval[0]);
      return 0;
 }

printf(SCREENCLEAR);
printf(MOVECURSOR);

printf("Enter the URL:");    //User inputs
scanf("%s",inputURL);        //entered url string is stored in an array

if(strlen(inputURL)<=3){    //if user input is less than or equal to 3 strings then print an error message
 printf("String is too short. Not supported by available QR versions\n");
}else if(strlen(inputURL)>=120){//if user input is greater than or equal to 120 strings then print an error message
printf("String is too long. Not supported by available QR versions\n");

}else if(strlen(inputURL)<=20) //checking whether the user input url is less than 20 charachters
{
        String_Hashing(inputURL, HashedStringedSmall); //converting the url into hashed string of length 24 using a function call
        frame(24,Color); //printing the 24box frame

        int Remain_URLingPositions[24][2] =  { {7 , 7},{7 ,10},{7 ,13},{7 ,16},{10, 7},{10,10},{10,13},{10,16},{13, 7},{13,10},{13,13},{13,16},
                                    {16, 7},{16,10},{16,13},{16,16}, {1 , 7},{1 ,10}, {4 , 7},{4 ,10},{7 , 1},{7 , 4}, {10, 1},{10, 4}
                                    }; //the exact 2d positions in the box apart from the frame (the workspace)
                                                              
            for(int j = 0 ; j < 24 ; j++){
                BinaryConverter(BinaryArr,HashedStringedSmall,j); //converting the hashed strings to binary numbers by calling the function
                for(int i = 0 ; i < 9 ; i++){
                    if(BinaryArr[i]==1){
                   //printing black boxes on relavant places of binary numbers of 1
                            printf("\x1b[%d;%df",(Remain_URLingPositions[j][0] + i/3) +1,(Remain_URLingPositions[j][1] + i%3)*2+1);
                            printf("%s  ",Color);
                    }
                }
            }
            printf(MOVECURSOR); //move the cusor
            printf(RESET "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");   //reset the color back                  

 }else if(strlen(inputURL)>20){ //if the url charachter length is greater than 20 the print the 132 box frame

  String_Hashing(inputURL, HashedStringedlong); //convert the input url into hashed string of length 132 using the function call
  frame(132,Color); //printing the frame of 132 boxes

      int Remain_URLingPositions[132][2] = {
                                    {7 , 7},{7 ,10},{7 ,13},{7 ,16},{7 , 19},{7 ,22},{7 ,25},{7 ,28},{7 ,31},{7 ,34},
                                    {10, 7},{10,10},{10,13},{10,16},{10, 19},{10,22},{10,25},{10,28},{10,31},{10,34},
                                    {13, 7},{13,10},{13,13},{13,16},{13, 19},{13,22},{13,25},{13,28},{13,31},{13,34},
                                    {16, 7},{16,10},{16,13},{16,16},{16, 19},{16,22},{16,25},{16,28},{16,31},{16,34},
                                    {19, 7},{19,10},{19,13},{19,16},{19, 19},{19,22},{19,25},{19,28},{19,31},{19,34},
                                    {22, 7},{22,10},{22,13},{22,16},{22, 19},{22,22},{22,25},{22,28},{22,31},{22,34},
                                    {25, 7},{25,10},{25,13},{25,16},{25, 19},{25,22},{25,25},{25,28},{25,31},{25,34},
                                    {28, 7},{28,10},{28,13},{28,16},{28, 19},{28,22},{28,25},{28,28},{28,31},{28,34},
                                    {31, 7},{31,10},{31,13},{31,16},{31, 19},{31,22},{31,25},{31,28},{31,31},{31,34},
                                    {34, 7},{34,10},{34,13},{34,16},{34, 19},{34,22},{34,25},{34,28},{34,31},{34,34},
                                    {1 , 7},{1 ,10},{1 ,13},{1 ,16},{1 ,19},{1 ,22},{1 ,25},{1 ,28},
                                    {4 , 7},{4 ,10},{4 ,13},{4 ,16},{4 ,19},{4 ,22},{4 ,25},{4 ,28},
                                    {7 , 1},{7 , 4},
                                    {10, 1},{10, 4},
                                    {13, 1},{13, 4},
                                    {16, 1},{16, 4},
                                    {19, 1},{19, 4},
                                    {22, 1},{22, 4},
                                    {25, 1},{25, 4},
                                    {28, 1},{28, 4},
                                    }; //2d positions of the 132 box workspace

     for(int j = 0 ; j < 132 ; j++){ 
      BinaryConverter(BinaryArr,HashedStringedlong,j); //converting the 132 length hashed string into binary numbers by calling the function

                
                for(int i = 0 ; i < 9 ; i++){
                    if( BinaryArr[i]==1){  //printing black boxes on relavant places of binary numbers of 1
                         printf("\x1b[%d;%df",(Remain_URLingPositions[j][0] + i/3) +1,(Remain_URLingPositions[j][1] + i%3)*2+1);
                         printf("%s  ",Color);
                    }
                }
            }
            printf(MOVECURSOR);
            printf(RESET "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");  
 }
return 0;
}
/* Defining functions */
void frame(int n,char Color[6]){ //function to print the frame of 24 boxes if n=24 and frame of 132 if n=132
//initialising the exact 2d positions of the frame and position squares of the 24box frame
  int BoxFrame[72][2] = {{1, 1},{1, 2},{1, 3},{1, 4},{1, 5},{1, 6},{2, 1},{2, 6},{3, 1},{3, 3},{3, 4},{3, 6},{4, 1},{4, 3},{4, 4},{4, 6},{5, 1},{5,6},{6, 1},{6, 2},{6,3},{6, 4},{6, 5}, {6, 6},  
{1,13},{1,14},{1,15},{1,16},{1,17},{1,18},{2,13},{2,18},{3,13},{3,15},{3,16},{3,18},{4,13},{4,15},{4,16}, {4,18},{5,13},{5,18},{6,13},{6,14},{6,15},{6,16},{6,17},{6,18},  
{13,1},{13,2},{13,3},{13,4},{13,5},{13,6},{14,1},{14,6},{15,1},{15,3},{15,4}, {15,6},{16,1},{16,3},{16,4},{16,6},{17,1},{17,6},{18,1},{18,2},{18,3},{18,4},{18,5},{18,6}};
          if(n==24){
          printf(SCREENCLEAR);
          printf(MOVECURSOR);
           
            for(int i = 0 ; i < 20 ; i++){
                printf(WHITE "                                        \n");
            }
            for(int i = 0 ; i < 72 ; i++){ //print black boxes on the locations initialised in the 2d array
                printf("\x1b[%d;%df",(BoxFrame[i][0]) +1,(BoxFrame[i][1])*2+1);
                printf("%s  ",Color);
              }
            }else if(n==132){

          printf(SCREENCLEAR);
          printf(MOVECURSOR);
           
            for(int i = 0 ; i < 38 ; i++){
                printf(WHITE "                                                                            \n");
            }// printing the 132 box frame by using loops to the 2d array defined to 24box frame
            for(int i = 0 ; i < 24 ; i++){ //to print the first positions box
                printf("\x1b[%d;%df",(BoxFrame[i][0]) +1,(BoxFrame[i][1])*2+1);
                printf("%s  ",Color);          
            }
            for(int i = 24 ; i <48  ; i++){ //to print the second position box in the right
                printf("\x1b[%d;%df",(BoxFrame[i][0]) +1,(BoxFrame[i][1]+18)*2+1);
                printf("%s  ",Color);          
            }
            for(int i = 48 ; i <72  ; i++){ //to print the 3rd position box 
                printf("\x1b[%d;%df",(BoxFrame[i][0]+18) +1,(BoxFrame[i][1])*2+1);
                printf("%s  ",Color);          
            }
            }          
}
void String_Hashing (unsigned char main_URL[],unsigned char Hashed_String[]){ //function to convert url to hashed string
  int size;
  if(strlen(main_URL)<=20){ //Condition to hashstring the url below 20 charachters
    size=24;
  }else{   //Condition to hashstring the url above 20 charachters
    size=132;
  }
  unsigned char Initial[size];
  int i, m=1, n=0, j; //String hashing algorithm
  Initial[0]= 50+ strlen(main_URL);  //first letter of the algorithm is defined
  for(i=1; i<=((size-1)/strlen(main_URL))+1; i++){ 
    for(j=0; j<strlen(main_URL); j++){
      Initial[m]=main_URL[j]+i-1; //printing the next set(url itself) of strings according to the algorithm
      m++;
      if(m==size){
        break;
      }
    }
  }for(i=0; i<size;i++){
      Hashed_String[i]=Initial[i];
      if(i>strlen(main_URL)){
        Hashed_String[i]=Initial[size-1-n]; //the remaining set of strings are added to the string hash array after appending and reversing
        n++;
      }
    }
}
void LowerCase(char ch[]){ //function to lower case the charachters
    for (int i=0;ch[i]!='\0';i++){
   if( ch[i]>='A'&& ch[i]<='Z'){
       ch[i]=ch[i]+32;
   } 
  }
}
void BinaryConverter(int BinaryArr[9],unsigned char HashedString[132],int j){     //function to convert the hashed string to binary numbers      
        int i=8;     //counter is intially set to 8
      while(i>=0)    //until the counter is greater than or equal to 0 the loop happens
    {
        BinaryArr[i] = HashedString[j] % 2; //mod of each index of a hashedstring is found and stored in binaryarr 
        HashedString[j] = HashedString[j] / 2; //hashedstrng is divided by 2
        i--; //i=i-1
    }
}