#include<bits/stdc++.h>

using namespace std;

string expression;
int expressionLength = 0;
int answer = 0;
int firstNumber = 0;
int secondNumber = 0;

void getInput()
{
	//get input as a*b
	cin >> expression;
	expressionLength = expression.length();
	int numberCount = 0, asteriskCount = 0;
	for(int i = 0; i < expressionLength; i++)
	{
		if(expression[i] >= '0' && expression[i] <= '9')
		{
			++numberCount;
		}
		if(expression[i] == '*')
		{
			++asteriskCount;
		}
	}
	if(asteriskCount + numberCount == expressionLength)
	{
		return;
	}
	cout << "Input not in given format.";
	exit(0);
}

void optimizeCode()
{
	int pos = 0;
	for(int i = 0; i < expressionLength; i++)
	{
		if(expression[i] == '*')
		{
			pos = i;
			break;
		}
		firstNumber = (firstNumber * 10) + (expression[i] - '0');
	}
	for(int i = pos + 1; i < expressionLength; i++)
	{
		secondNumber = (secondNumber * 10) + (expression[i] - '0');
	}
	if(firstNumber > secondNumber)
	{
		swap(firstNumber, secondNumber);
	}
}

void getOutput()
{
	cout << "Let Total be 0." << '\n';
	cout << "Expression = " << expression << " = Loop(" << "Total += " << secondNumber << ", " << firstNumber << " times)";
	for(int i = 0; i < firstNumber; i++)
	{
		answer += secondNumber;
	}
	cout << "\nTotal = " << answer << '\n';
}

int main()
{
	getInput();
	optimizeCode();
	getOutput();
	return 0;
}