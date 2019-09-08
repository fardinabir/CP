#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

// Here, i am declaring the Keywords.
//There are 32 Keywords.
// All are kept in a 2D array.
// If matches are found then we will make flag = 1;
int isKeyword(char buffer[])
{
    char keywords[32][10] =
        {"auto", "break", "case", "char", "const", "continue", "default",
         "do", "double", "else", "enum", "extern", "float", "for", "goto",
         "if", "int", "long", "register", "return", "short", "signed",
         "sizeof", "static", "struct", "switch", "typedef", "union",
         "unsigned", "void", "volatile", "while"};
    int i, flag = 0;

    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main()
{
    char ch, buffer[15], b[30], logical_op[] = "><", math_op[] = "+-*/=", numer[] = ".0123456789", other[] = ",;\(){}[]'':";
    char arr[30];

    // For Direct Input.
    //ifstream fin("File2.txt");

    //For Scanning The File Name & Then Taking The Input
    printf("Enter Your File Name ---> ");
    char filename[100];
    ifstream fin("code.txt");
    // cin.getline(filename, 100);
   // fin.open("File.txt");
    printf("\n");

    printf("<------------------- Output ------------------->\n\n");

    int mark[1000] = {0};
    int i, j = 0, kc = 0, ic = 0, lc = 0, mc = 0, nc = 0, oc = 0, aaa = 0, location =1, f=0;


    //Vector is a one dimensional array.
    vector<string> k;
    vector<string> id;
    vector<char> lo;
    vector<char> ma;
    vector<string> nu;
    vector<char> ot;

    // If we are unable to open the file
    if (!fin.is_open())
    {
        cout << "Error while opening the file\n";
        exit(0);
    }

    //Unless the file has reached it's terminal point, the scanning will go on.
    while (!fin.eof())
    {

        ch = fin.get();

        //logical_op[] = "><"
        //math_op[]="+-*/="
        //numerical[]=".0123456789"
        //other[]=",;\(){}[]'':"
        // Here we have also checked newline, but that's not necessary

        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' ||
            ch == '7' || ch == '8' || ch == '9' || ch == '.' || ch == ' ' || ch == '\n' || ch == ';' || ch == ',' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '(' ||
            ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ':' || ch == '>' || ch == '<')
        {

            if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.')
            {
                b[aaa] = ch;
                aaa++;

                //Self made but not necessary here
                // So skip this portion
                /*for(int g=0;g<=aaa;g++){
                        printf("%c is a number", b[g]);
                    if(g==aaa-1){
                         b[aaa]='\0';
                         aaa=0;
                         printf("\n");
                    }
                }
                */
            }

            if ((ch == ' ' || ch == '\n' || ch == ';' || ch == ',' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
                 ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ':' || ch == '>' || ch == '<') &&
                (aaa != 0))
            {
                b[aaa] = '\0';
                aaa = 0;
                char arr[30];
                strcpy(arr, b);
                printf(" %s is a Number\n", arr);
                aaa = 0;
                ++nc;

                // If we wanna store the Number in an array then we can do the following code.
                //nu.push_back(arr);
            }
        }

        //logical_op[] = "><"
        //math_op[]="+-*/="
        //numerical[]=".0123456789"
        //other[]=",;\(){}[]'':"
        // Here we have also checked newline, but that's not necessary
        if (isalnum(ch))
        {
            buffer[j] = ch;
            j++;
        }
        else if ((ch == ' ' || ch == '\n' || ch == ',' || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']' ||
                  ch == '<' || ch == '>' || ch == '+' || ch == '-' || ch == '*') ||
                 ch == '/' || ch == '=' || ch == '0' || ch == '1' || ch == '2' ||
                 ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1)
            {
                printf(" %s is a Keyword\n", buffer);
                ++kc;

                // If we wanna store the Number in an array we can do the following code.
                //k.push_back(buffer);
            }

            else
            {
                if (buffer[0] >= 97 && buffer[0] <= 122)
                {
                    printf(" %s is an identifier\n", buffer);
                    if (mark[buffer[0] - 'a'] != 1)
                    {
                        // If we wanna store the Number in an array we can do the following code.
                        id.push_back(buffer);
                        mark[buffer[0]-'a']=1;
                        ic++;
                    }
                }
                else if (buffer[0] >= 65 && buffer[0] <= 90)
                {
                    printf(" %s is an identifier\n", buffer);
                    if (mark[buffer[0] - 'A'] != 1)
                    {
                        // If we wanna store the Number in an array we can do the following code.
                        id.push_back(buffer);
                        mark[buffer[0]-'a']=1;
                        ic++;

                    } // Starting bracket is at line 178

                } // Starting bracket is at line 175
                else if ((buffer[0] >= 48 && buffer[0] <= 57) && ( (buffer[1] >= 97 && buffer[1] <= 122)||(buffer[1] >= 65 && buffer[1] <= 90) ))
                {
                    if (mark[buffer[0] - 'a'] != 1)
                    {
                        printf(" %s is not a valid identifier\n", buffer);

                        // If we wanna store the Number in an array we can do the following code.
                        //id.push_back(buffer);
                        //mark[buffer[0]-'a']=1;

                    } //Starting bracket is at line 190

                } // Starting bracket is at line 188

            } // Starting bracket is at line 162

        }  // Starting bracket is at line 148

        for (i = 0; i < 12; ++i)
        {

            if (ch == other[i])
            {
                printf(" %c is a Delimiter\n", ch);
                ++oc;

                // If we wanna store the Number in an array we can do the following code.
                // Here, we do one more task, that is, if a delimiter is found twice it will be shown only once.
                // Since it is not necessary, we are commenting out
                /*
                int aa=ch;
                if(mark[aa]!=1){
                    ot.push_back(ch);
                    mark[aa]=1;

                }*/

            } // Starting bracket is at line 209

        } // Starting bracket is at line 206

        for (i = 0; i < 5; ++i)
        {

            if (ch == math_op[i])
            {

                printf(" %c is a Mathematical Operator\n", ch);
                ++mc;
                /*
                    int aa=ch;
                    if(mark[aa]!=1){
                        ma.push_back(ch);
                        mark[aa]=1;

                }*/

            } // Starting bracket is at line 232

        } // Starting bracket is at line 229

        for (i = 0; i < 2; ++i)
        {
            if (ch == logical_op[i])
            {

                printf(" %c is a Logical Operator\n", ch);
                ++lc;

                /*
                    int aa=ch;
                    if(mark[aa]!=1){
                    lo.push_back(ch);
                    mark[aa]=1;
               }
               */

            } // Starting bracket is at line 251

        } // Starting bracket is at line 249

    } // Starting bracket is at line 83

    fin.close();




    cout<<"\n\n<---------------------------- Symbol Table ----------------------------->\n"<<endl;
    cout<<" ---------------------------------------------------------------------- "<<endl;
    cout<<" |   Lexeme"<<"   |      "<<"Token Type"<<"     |  "<<"Pointer to symbol table entry  |"<<endl;
    cout<<" ---------------------------------------------------------------------- "<<endl;


    for( f=0;   f<ic ;   f++ ){
        cout<<" |     "<<id[f]<<"     |        <id,"<<location<<">"<<"       |                "<<f<<"                |\n";
        cout<<" ---------------------------------------------------------------------- "<<endl;
        location++;

    } // Starting bracket is at line 281








    return 0;
} // Starting bracket is at line 35
