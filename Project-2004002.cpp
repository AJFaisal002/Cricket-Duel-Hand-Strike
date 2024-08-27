#include <bits/stdc++.h>
using namespace std;

class Hand_Cricket {
    int run = 0, score, sum = 0, last_run;
    static int out;
public:
    void set_run(int run) {
        this->run = run;
    }
    int total_run() {
        return sum += run;
    }
    bool operator<(Hand_Cricket obj) {
        return (score < obj.score);
    }
    virtual void result() {
        cout << "Bad Luck!!!! Console Wins!!!" << endl;
    }
    friend void draw_result();
    friend void out_info(int last_run);
};

class user_result : public Hand_Cricket {
public:
    void result() {
        cout << "Congrats!!!! You won the match!!!" << endl;
    }
};

void draw_result() {
    cout << "Match Draw!!! Well Tried." << endl;
}

void out_info(int last_run) {
    if (Hand_Cricket::out == 1) {
        cout << "You're Out" << endl;
        cout << "Your Total run is: " << last_run << endl;
        cout << "Now It's your turn to ball." << endl;
        cout << endl;
    } else {
        cout << "Console Out" << endl;
        cout << "Console's total run: " << last_run << endl;
    }
    Hand_Cricket::out++;
}

int Hand_Cricket::out = 1;

void Rules_of_the_game() {
    cout << "Welcome to Hand Cricket game." << endl;
    cout << "The rules are very simple." << endl;
    cout << "You will have to bat first." << endl;
    cout << "Enter any number from 1 to 6. It will count as your score." << endl;
    cout << "If the number you entered is equal to the console entered number, you will be out." << endl;
    cout << "Then you have to bowl." << endl;
    cout << "The rules are same. But opposite to first one." << endl;
    cout << "You have to enter 1 to 6, if the console entered same as yours, console will be out." << endl;
    cout << "The highest scorer will win the match." << endl;
    cout << "\nWarning!!! If you enter number greater than 6 you will be declared out\n" << endl;
    cout << "Let's start!!!\n\n" << endl;
}

int main() {
    Rules_of_the_game();

    Hand_Cricket hc1, hc2;
    user_result us_r;

    srand(time(0));
    int first_player_run = 0, AI_player_run = 0;

    // Player's batting
    while (true) {
        int run;
        cout << "Enter your number/run: ";
        cin >> run;
        int Random_number = (rand() % 6) + 1; // Random number between 1 and 6

        if (run < 1 || run > 6) {
            cout << "Invalid input! Number must be between 1 and 6. You are out." << endl;
            run = Random_number;
        }

        if (run != Random_number) {
            hc1.set_run(run);
            first_player_run = hc1.total_run();
        } else {
            out_info(first_player_run);
            break; // End batting, start bowling
        }
    }

    // Console's batting
    while (true) {
        int ball;
        cout << "Enter your number/ball: ";
        cin >> ball;
        int Random_number2 = (rand() % 6) + 1; // Random number between 1 and 6

        if (ball < 1 || ball > 6) {
            cout << "Invalid input! Number must be between 1 and 6. Console is out." << endl;
            ball = Random_number2;
        }

        if (ball != Random_number2) {
            hc2.set_run(Random_number2);
            AI_player_run = hc2.total_run();
        } else {
            out_info(AI_player_run);
            break; // End bowling
        }

        // Check if console's run is greater than player's run
        if (AI_player_run > first_player_run) {
            hc1.result(); // Console wins
            return 0; // Exit the program
        }
    }

    // Determine result if neither has won by the end
    if (first_player_run == AI_player_run) {
        draw_result();
    } else {
        int result = first_player_run < AI_player_run;
        (result == 1) ? hc1.result() : us_r.result();
    }

    return 0;
}
