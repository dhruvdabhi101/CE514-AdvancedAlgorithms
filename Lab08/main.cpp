#include <bits/stdc++.h>
using namespace std;
class Rabinkarp
{
    string text;
    string pattern;
    int q;
    int p, t;

public:
    void takeInput()
    {
        cout << "Enter text: ";
        cin >> text;
        cout << "Enter q: ";
        cin >> q;
        cout << "Enter pattern: ";
        cin >> pattern;
    }
    void preProcess()
    {
        t = 0;
        p = 0;
        for (int i = 0; i < pattern.length(); i++)
        {
            p = (10 * p + (pattern[i] - '0')) % q;
            t = (10 * t + (text[i] - '0')) % q;
        }
    }
    // 2359023141526739921
    void run()
    {
        int n = text.length();
        int m = pattern.length();
        int h = pow(10, m - 1);
        h = h % q;
        preProcess();
        for (int i = 0; i <= n - m; i++)
        {
            if (p == t and pattern == text.substr(i, m))
            {
                cout << "Pattern occurs at " << i << endl;
            }

            if (i < n - m)
            {
                t = (10 * (t - (text[i] - '0') * h) + (text[i + 1] - '0')) % q;
                if (t < 0)
                {
                    t += q;
                }
            }
        }
    }
};

class FiniteAutomaton
{
    string text;
    string pattern;
    map<pair<int,char>,int> automata;

public:
    void takeInput()
    {
        cout << "Enter text: ";
        cin >> text;
        cout << "Enter pattern: ";
        cin >> pattern;
    }
};
int main()
{
    FiniteAutomaton ob2;
    ob2.takeInput();
    return 0;
}
