
#include <iostream>
using namespace std;
enum enchoseGame { stone = 1, paper = 2, scissor = 3 };
int randomNumberOfComputer(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random;

}
void choisePlayer(int number)
{
    if (number == 1)
    {
        cout << " player choice : stone \n";
    }
    else if (number == 2)
    {
        cout << " player choice : paper \n";
    }
    else
    {
        cout << " player choice : scissor \n";
    }
}
void choiseCoputerRandom(int& randomvalue)
{
    randomvalue = randomNumberOfComputer(1, 3);
    if (randomvalue == 1)
    {
        cout << " computer choise : stone \n";
    }
    else if (randomvalue == 2)
    {
        cout << " computer choise : paper \n";
    }
    else
        cout << " computer choise : scissor \n";
}
void roundWinner(int number, int randomvalue, int& countPlayer, int& countComputer, int& count)
{

    if (number == randomvalue)
    {
        system("color 6F");
        cout << " round winner : [no winner] \n";
        count++;
    }
    else if (number == 1 && randomvalue == 2)
    {
        system("color 4F");
        cout << " round winner : [computer] \a\n";
        countComputer++;
    }
    else if (number == 1 && randomvalue == 3)
    {
        system("color 2F");
        cout << " round winner : [player] \n";
        countPlayer++;
    }
    else if (number == 2 && randomvalue == 1)
    {
        system("color 2F");
        cout << " round winner : [player] \n";
        countPlayer++;
    }
    else if (number == 2 && randomvalue == 3)
    {
        system("color 4F");
        cout << " round winner : [computer] \a\n";
        countComputer++;
    }
    else if (number == 3 && randomvalue == 1)
    {
        system("color 4F");
        cout << " round winner : [computer] \a\n";
        countComputer++;
    }
    else if (number == 3 && randomvalue == 2)
    {
        system("color 2F");
        cout << " round winner : [player] \n";
        countPlayer++;
    }
    else
    {
        system("color 6F");
        cout << " round winner : [no winner] \n";
    }
}
void numberOfRound(int arr[100], int& length, int& number, int randomvalue, int& countPlayer, int& countComputer, int& count)
{
    cout << "how many rounds 1 to 10 ? \n";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << " round [" << i + 1 << "] biggin : \n";
        cout << " your choice : [1]:stone, [2]:paper, [3]:scissor ? ";
        cin >> number;
        cout << "---------------------- round [" << i + 1 << "]----------------\n";
        choisePlayer(number);
        choiseCoputerRandom(randomvalue);
        roundWinner(number, randomvalue, countPlayer, countComputer, count);
        cout << "_____________________________\n";
    }

}
void printResultOffRounds(int length, int countPlayer, int countComputer, int count)
{

    cout << "           ___________________________________________ \n";
    cout << "                       +++  GAME OVER +++              \n";
    cout << "           ___________________________________________ \n";
    cout << "                           [GAME Result]                \n";
    cout << "           Game round        : " << length << endl;
    cout << "           player1 win       : " << countPlayer << endl;
    cout << "           computer win      : " << countComputer << endl;
    cout << "           draw time         : " << count << endl;
    if (countPlayer > countComputer)
    {
        cout << "           final winner      : player \n";
    }
    else if (countPlayer < countComputer)
    {
        cout << "           final winner      : computer \n";

    }
    else
        cout << "           final winner      : no winner\n";
}
bool returnGame(int arr[100], int& length, int& number, int& randomvalue, int& countPlayer, int& countComputer, int& count)
{

    countPlayer = 0, countComputer = 0, count = 0, length = 0;
    char again;
    do {
        cout << " Do you want to play againe y/n ? ";
        cin >> again;
        if (again == 'n' || again == 'N')
            return false;
        system("color 0F");
        system("cls");
        numberOfRound(arr, length, number, randomvalue, countPlayer, countComputer, count);
        printResultOffRounds(length, countPlayer, countComputer, count);


    } while (again == 'y' || again == 'Y');

    return false;
}
int main()
{
    int number = 0, arr[100], length = 0, randomvalue = 0, countPlayer = 0, countComputer = 0, count = 0;

    numberOfRound(arr, length, number, randomvalue, countPlayer, countComputer, count);
    printResultOffRounds(length, countPlayer, countComputer, count);
    returnGame(arr, length, number, randomvalue, countPlayer, countComputer, count);
}



