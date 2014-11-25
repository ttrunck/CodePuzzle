#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class card{
    char suit;
    int value;

    friend istream& operator>>(istream& is, card& c);

 public:
    bool operator<(const card& c) const {
        return value < c.value;
    }

    bool operator==(const card& c) const {
        return value == c.value;
    }
};

istream& operator>>(istream& is, card& c) {
    char tmp;
    is >> tmp;
    switch (tmp) {
        case '1':
            c.value = 10;
            is >> tmp;
            break;
        case 'J':
            c.value = 11;
            break;
        case 'Q':
            c.value = 12;
            break;
        case 'K':
            c.value = 13;
            break;
        case 'A':
            c.value = 14;
            break;
        default:
            c.value = tmp - '0';
    }
    is >> tmp;
    c.suit = tmp;
    return is;
}

int main() {
    array<queue<card>, 2> deck;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        card c;
        cin >> c;
        deck[0].push(c);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        card c;
        cin >> c;
        deck[1].push(c);
    }

    int nb_manche = 0;
    while (!deck[0].empty() && !deck[1].empty()) {
        ++nb_manche;

        array<vector<card>, 2> bataille;
        for (int i = 0; i < 2; ++i) {
            bataille[i].push_back(deck[i].front());
            deck[i].pop();
        }
        while (bataille[0].back() == bataille[1].back()) {
            for (int j = 0; j < 4; ++j)
                for (int i = 0; i < 2; ++i) {
                    if (deck[i].empty()) {
                        cout << "PAT\n";
                        return 0;
                    }
                    bataille[i].push_back(deck[i].front());
                    deck[i].pop();
                }
        }
        int winner = (bataille[0].back() < bataille[1].back())?1:0;

        for (int i = 0; i < 2; ++i)
            for (const auto& c : bataille[i])
                deck[winner].push(c);
    }

    cout << (!deck[0].empty()?'1':'2') << ' ' << nb_manche << '\n';
}
