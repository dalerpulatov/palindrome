#include <bits/stdc++.h>
using namespace std;

string solution(string n) {
    long long x = stoll(n);
    int len = n.size();

    vector<long long> candidates;

    long long p = stoll(n.substr(0, (len + 1) / 2));

    auto makePalindrome = [&](long long prefix) {
        string s = to_string(prefix);
        string r = s;

        if (len % 2 == 1)
            s.pop_back();

        reverse(s.begin(), s.end());
        r += s;

        return stoll(r);
    };

    candidates.push_back(makePalindrome(p));
    candidates.push_back(makePalindrome(p - 1));
    candidates.push_back(makePalindrome(p + 1));

    candidates.push_back((long long)pow(10, len - 1) - 1);
    candidates.push_back((long long)pow(10, len) + 1);

    long long best = LLONG_MAX;
    long long bestDiff = LLONG_MAX;

    for (long long c : candidates) {
        if (c == x || c < 0)
            continue;

        long long diff = llabs(c - x);

        if (diff < bestDiff || (diff == bestDiff && c < best)) {
            bestDiff = diff;
            best = c;
        }
    }

    return to_string(best);
}

int main() {
    string n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Closest palindrome: " << solution(n) << endl;

    return 0;
}