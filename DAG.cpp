#include<bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------*/

string postfixString, str;
int ptr = 0, varPtr = 0;
stack<char> currStack;
char assignment[] =
{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R'};
map<string, char> newMap;
map<string, bool> visited;
stack<char> postfixStack;


/*---------------------------------------------------------------------------*/

void getInput()
{
        cout << "\n\n\t\t DAG GENERATION \n\t\t --- ----------";
        cout << "\n\nEnter the Infix Expression: ";
        cin >> str;
}

/*---------------------------------------------------------------------------*/

int getPrecedence(char c)
{
        switch(c)
        {
                case '_':
                        return 4;
                case '/':
                case '*':
                        return 3;

                case '+':
                case '-':
                        return 2;

                case '(':
                        return 1;

                case '=':
                        return 0;
        }
}

/*---------------------------------------------------------------------------*/

void changeInfixToPostfix()
{
        postfixString = "";
        int i = 0;
        for(i = 0; i < str.length(); i++)
        {
                if(str[i] == '+' || str[i] == '-' || str[i] == '=' || str[i] == '*'
|| str[i] == '(' || str[i] == ')' || str[i] == '/')
                {
                        if(str[i] == ')')
                        {
                                while(1)
                                {
                                        char now = postfixStack.top();
                                        postfixStack.pop();
                                        if(now == '(')
                                        {
                                                break;
                                        }
                                        postfixString += now;
                                }
                        }
                        else
                        {
                                while(!postfixStack.empty() && getPrecedence(postfixStack.top())
>= getPrecedence(str[i]))
                                {
                                        char now = postfixStack.top();
                                        postfixStack.pop();                             
                                        postfixString += now;

                                }
                                postfixStack.push(str[i]);
                        }
                }
                else
                {
                        postfixString += str[i];
                }
        }
        while(!postfixStack.empty())
        {
                postfixString += postfixStack.top();
                postfixStack.pop();
        }
        cout << "\n\nThe Postfix Expression for the input is: " <<
postfixString << "\n\n";
}

/*---------------------------------------------------------------------------*/

void calculateThreeAddress()
{


        cin >> postfixString;
        currStack.push(postfixString[0]);
        while(ptr < postfixString.length() && (!currStack.empty()))
        {
                ++ptr;
                char now = currStack.top();
                string operation = "";
                char firstOp, secondOp;
                if(now == '+' || now == '-' || now == '*' || now == '%' || now == '=')
                {
                        currStack.pop();
                        firstOp = currStack.top();
                        currStack.pop();
                        if(firstOp >= 'A' && firstOp <= 'Z')
                        {
                                secondOp = firstOp;
                        }
                        else
                        {
                                secondOp = currStack.top();
                                currStack.pop();
                        }
                        operation += secondOp;
                        operation += now;
                        operation += firstOp;

                        if(visited[operation] == true)
                        {
                                currStack.push(newMap[operation]);
                                currStack.push(postfixString[ptr]);
                                continue;
                        }
                        else              
                        {
                                newMap[operation] = assignment[varPtr];
                                if(now == '=')
                                {
                                        cout << newMap[operation] << " " << now << " " << firstOp << "\n\n";    
                                }
                                else
                                {
                                        cout << assignment[varPtr] << " = " << secondOp << " " << now <<
" " << firstOp << '\n';
                                }
                                varPtr ++;
                                visited[operation] = true;
                                currStack.push(newMap[operation]);
                        }
                }
                currStack.push(postfixString[ptr]);
        }

}

/*---------------------------------------------------------------------------*/

int main()
{
        getInput();
        changeInfixToPostfix();
        calculateThreeAddress();
        return 0;
}
