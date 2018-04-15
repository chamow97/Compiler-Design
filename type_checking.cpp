#include<bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------*/

map<string, string> typeOfVar;
map<string, bool> visited;
int ptr = 0, iVal = 0, fVal = 0, totVal = 0, cVal = 0, dVal = 0, sVal
= 0;
string inputExpression;

/*---------------------------------------------------------------------------*/

void getDataTypes()
{
        string now = "";
        ifstream f1("program.txt", ios::in);
        while(!f1.eof())
        {
                f1 >> now;
                if(now == "int" || now == "float" || now == "double" || now ==
"string" || now == "char")
                {
                        string curr = "";
                        while(f1 >> curr)
                        {
                                if(curr[curr.length() - 1] == ')')
                                {
                                        break;
                                }
                                string currVar = "";
                                for(int i = 0; i < curr.length() - 1; i++)
                                {
                                        currVar += curr[i];
                                }
                                if(visited[currVar])
                                {
                                        cout << "\n\n\t Multiple Declarations for the same variable";
                                        return ;
                                }
                                typeOfVar[currVar] = now;
                                visited[currVar] = true;
                                if(curr[curr.length()-1] == ';')
                                {
                                        break;
                                }
                                //cout << currVar << ' ' << now << '\n';
                        }
                }
        }
        f1.close();
}

/*---------------------------------------------------------------------------*/

void checkInput()
{
    cout << "\n\n\t\t TYPE CHECKING \n\t\t ---- --------";
    cout << "\n\n\t Enter an expression to check for its type: ";
    cin >> inputExpression;
    string currVal = "";
    ptr = 0;
    while(ptr < inputExpression.length())
    {
            if(inputExpression[ptr] == '=' || inputExpression[ptr] == '-' ||
inputExpression[ptr] == '+' || inputExpression[ptr] == '*' ||
inputExpression[ptr] == '/')
            {
                    if(!visited[currVal])
                    {
                            cout << '\n' << currVal << " is not found in the program!";
                            exit(0);
                    }
                    string nowType = typeOfVar[currVal];
                    if(nowType == "int")
                    {
                            iVal++;
                    }
                    if(nowType == "char")
                    {
                            cVal++;
                    }
                    if(nowType == "float")
                    {
                            fVal++;
                    }
                    if(nowType == "double")
                    {
                            dVal++;
                    }
                    if(nowType == "string")
                    {
                            sVal++;
                    }
                    ++totVal;
                    cout << "\n\t" << currVal << " is of " << typeOfVar[currVal] << "type. \n\n";
                    currVal = "";
            }
            else
            {
                    currVal += inputExpression[ptr];
            }
            ptr++;
    }
    string nowType = typeOfVar[currVal];
    if(nowType == "int")
    {
            iVal++;
    }
    if(nowType == "char")
    {
            cVal++;
    }
    if(nowType == "float")
    {
            fVal++;
    }
    if(nowType == "double")
    {
            dVal++;
    }
    if(nowType == "string")
    {
            sVal++;
    }
    ++totVal;
    cout << "\n\t" << currVal << " is of " << typeOfVar[currVal] << " type. \n\n";
}

/*---------------------------------------------------------------------------*/

void giveResults()
{
        if(iVal == totVal)
        {
                cout << "\n\t Both the sides are of INT type";
        }
        else if(cVal == totVal)
        {
                cout << "\n\t Both the sides are of CHAR type";
        }
        else if(dVal == totVal)
        {
                cout << "\n\t Both the sides are of DOUBLE type";
        }
        else if(fVal == totVal)
        {
                cout << "\n\t Both the sides are of FLOAT type";
        }
        else if(sVal == totVal)
        {
                cout << "\n\t Both the sides are of STRING type";
        }
        else
        {
                cout << "\n\t TYPE MISMATCH!!";
        }
}

/*---------------------------------------------------------------------------*/

int main()
{
        getDataTypes();
        checkInput();
        giveResults();
        return 0;
}
