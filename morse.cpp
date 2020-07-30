#include<iostream>
#include<fstream>
#include<cstring> 
#include<cctype>

using namespace std;

int main()
{
    fstream text("text.txt",ios::in);
    fstream code("code.txt",ios::in);
    fstream rslt("result.txt",ios::out);
    
   
    char ch,alphabets[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char morse_code[36][6]={
                    {".-"},
                    {"-..."},
                    {"-.-."},
                    {"-.."},
                    {"."},
                    {"..-."},
                    {"--."},
                    {"...."},
                    {".."},
                    {".---"},
                    {"-.-"},
                    {".-.."},
                    {"--"},
                    {"-."},
                    {"---"},
                    {".--."},
                    {"--.-"},
                    {".-."},
                    {"..."},
                    {"-"},
                    {"..-"},
                    {"...-"},
                    {".--"},
                    {"-..-"},
                    {"-.--"},
                    {"--.."},
                    {".----"},
                    {"..---"},
                    {"...--"},
                    {"....-"},
                    {"....."},
                    {"-...."},
                    {"--..."},
                    {"---.."},
                    {"----."},
                    {"-----"}
    };

    int x;
    cout<<"\n* Enter 0 for Encoding and 1 for decoding => ";
    cin>>x;

    if(x==0)
    {   
    if(!text || !rslt)
    {
        cout<<"\nError in one of the files.\n";
        return 0;
    } 
      while(text)
      {
          text.get(ch);
          ch=toupper(ch);
          if(text){
              for(int i=0;i<36;i++)
          {
              if(ch==alphabets[i])
              {
                  rslt<<morse_code[i]<<" ";
              }              
          }
          if(ch==char(32))
              {rslt<<" ";}
          if(ch==char(10))
              {rslt<<char(10);}
          }
      }      
       
      text.close();
      cout<<"\nResult stored in result.txt\n";
    }

    int y=0,flag=0,flag2=0;

    if(x==1)
    {

    if(!code || !rslt)
    {
        cout<<"\nError in one of the files.\n";
        return 0;
    }

     while(code)
      {   char text_arr[6];    
         
          while(code.get(ch))
          {
             if(ch==char(32))
             {flag++;

             if(flag==1)
             break;
             
             if(flag==2)
             {flag=0;
              flag2=1;
             continue;}
             }

             if(ch==char(10))
             {
                 text_arr[y]=ch;
             text_arr[++y]=0;  
             break;
             }

             flag=0;
             text_arr[y]=ch;
             text_arr[++y]=0;             
          }
         //cout<<text_arr<<" 1";

          if(code){
              for(int i=0;i<36;i++)
              {if(strcmp(text_arr,morse_code[i])==0)
                 {
                     if(flag2==1)
                  {rslt<<" ";
                flag2=0;}

                    rslt<<alphabets[i];  
                   // cout<<alphabets[i];           
                 }                   
              }
              if(text_arr[0]==char(10))
                   {
                        rslt<<char(10);
                   }
          y=0;
          }
          
          }
         
          code.close();
          cout<<"\nResult stored in result.txt\n";
    }   
    rslt.close();
    return 0;
}