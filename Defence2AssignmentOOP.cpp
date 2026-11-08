#include <iostream>
#include <string>
using namespace std;

class Coin {
    int value = 0;
    bool taken = false;
public:
    Coin(int value_) {
        value = value_;
    }
    int take() {
        if (taken == false) {
            taken = true;
            return value;
        }
        return 0;
    }
};

class Player {
    string name = "";
    int score = 0;
public:
    Player(string name_) {
        name = name_;
    }
    void collect(Coin& coin) {
        int value = coin.take();
        if (value > 0) {
            score += value;
            std::cout << name << " collected " << value << ", score=" << score << "\n";
        }
        else {
            std::cout << name << ": coin already taken\n";
        }
        
        
    }
    int getScore() {
        return score;
    }
};


int main() {
    Player mario("Mario");
    Coin gold(10);
    Coin silver(5);

    mario.collect(gold);
    mario.collect(silver);
    mario.collect(gold);

    cout << "Final score: " << mario.getScore() << "\n";
    return 0;
}