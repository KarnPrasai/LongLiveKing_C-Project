#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Player
{
public:
    int money = 0;
    void GoFishing();
    void HookAFish();
    void PlaceTravel();
    void PlaceChecker();
    void Shop();

};

void Player::GoFishing()
{
    atomic<bool> stopAnimation(false);
    std::atomic<bool> fishHooked(false);
    thread animationThread([&]()
        {
            while (!stopAnimation)
            {

                cout << "\rSteady." << flush;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\rSteady.." << flush;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\rSteady..." << flush;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\rSteady   " << flush;

            }
        });

    srand(time(NULL));
    int waitTime = rand() % 3 + 2;
    this_thread::sleep_for(chrono::seconds(waitTime));
    stopAnimation = true;
    animationThread.join();

    string input;
    cout << "\nHook!! (Type \"Hook\") : " << flush;
    cin >> input;
    if (input == "Hook")
    {
        cout << "Fish hooked!\n";
        HookAFish();
    }
    else
    {
        cout << "Oh no!!, The fish was gone.\n";
    }

}

void Player::HookAFish()
{
    cout << "Caught!!\n";
    string action[] = { "Up", "Down", "Left", "Right" };

    int count = 0;

    for (int i = 0; i < 4; ++i)
    {
        int fishact = rand() % 4;
        cout << "Go " << action[fishact] << " : ";
        string playerAction;
        string input;
        cin >> playerAction;


        if (playerAction == action[fishact])
        {
            count++;
            if (count == 4)
            {
                cout << "Gotcha!!\n";

            }
        }
        else
        {
            cout << "No!!, The line was broken by the fish.\n";
        }
    }

}

void Player::PlaceTravel()
{
    string FishingArea[] = { "River","Lake","Beach","Sea","Deep Sea","Island" };
    int playergoing;
    cout << "Which place do you want to go?\n";
    cout << "================================\n";
    for (int i = 0; i < 6; i++)
    {
        cout << "|| " << i + 1 << " " << FishingArea[i] << ". ||\n";
    }
    cout << "================================\n";
    cout << "Input Number of the place :";
    cin >> playergoing;
    cout << "Going to " << FishingArea[playergoing - 1];


}

void Player::PlaceChecker()
{

}

void Player::Shop()
{
    cout << "you can upgrade your stuff here.\n";
    cout << "================================\n";

}

int main()
{
    Player p;
    //p.GoFishing();
    p.PlaceTravel();
}
