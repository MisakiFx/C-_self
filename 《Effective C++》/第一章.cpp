#include <iostream>
using namespace std;
class GamePlayer
{
public:
    static const int NumTurns = 5;
    int scores[NumTurns];
};
//const int GamePlayer::NumTurns; 
int main()
{
    cout << GamePlayer::NumTurns << endl;
}