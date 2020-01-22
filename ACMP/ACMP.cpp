#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int translationToInt(string numberInString)
{
    int numberInInt = 0;

    for (int index = 0; index < (int)numberInString.size(); index++)
    {
        numberInInt *= 10;
        numberInInt += (numberInString[index] - '0');
    }

    return numberInInt;
}

string translationToString(int numberInInt)
{
    string numberInString = "";

    while (numberInInt)
    {
        numberInString += ((numberInInt % 10) + '0');
        numberInInt /= 10;
    }

    reverse(numberInString.begin(), numberInString.end());

    return numberInString;
}

vector <int> scan(string longNumberInString)
{
    vector <int> longNumber;

    for (int index = (int)longNumberInString.size(); index > 0; index -= 9)
        if (index < 9) longNumber.push_back(translationToInt(longNumberInString.substr(0, index)));
        else longNumber.push_back(translationToInt(longNumberInString.substr(index - 9, 9)));

    while (longNumber.size() > 1 && !longNumber.back())
        longNumber.pop_back();

    return longNumber;
}

string print(vector <int> longNumber)
{
    string longNumberInString;
    
    if ((int)longNumber.size()) longNumberInString += translationToString(longNumber.back());
    else longNumberInString = "0";

    for (int index = int((int)longNumber.size() - 2); index >= 0; --index)
    {
        string temp = translationToString(longNumber[index]);

        reverse(temp.begin(), temp.end());

        while ((int)temp.size() < 9)
            temp += "0";

        reverse(temp.begin(), temp.end());

        longNumberInString += temp;
    }

    if (longNumberInString.empty()) longNumberInString = "0";

    return longNumberInString;
}

vector <int> sum(vector <int> firstNumber, vector <int> secondNumber)
{
    int carry = 0;

    for (int index = 0; index < max((int)firstNumber.size(), (int)secondNumber.size()) || carry; ++index)
    {
        if ((int)firstNumber.size() == index) firstNumber.push_back(0);
        firstNumber[index] += carry;
        if ((int)secondNumber.size() > index) firstNumber[index] += secondNumber[index];
        carry = firstNumber[index] / 1000000000;
        if (carry) firstNumber[index] -= 1000000000;
    }

    return firstNumber;
}

int main()
{
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");

    string a, b;
    fin >> a >> b;

    vector <int> ans = sum(scan(a), scan(b));
    
    fout << print(ans);

    fin.close();
    fout.close();

    return 0;
}