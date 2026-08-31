#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num, temp, digit;
    stack<int> s;

    cout << "Enter a number: ";
    cin >> num;

    temp = num;

    while (temp > 0) {
        digit = temp % 10;
        s.push(digit);
        temp /= 10;
    }

    temp = num;
    bool isPalindrome = true;

    while (temp > 0) {
        digit = temp % 10;

        if (digit != s.top()) {
            isPalindrome = false;
            break;
        }

        s.pop();
        temp /= 10;
    }

    if (isPalindrome)
        cout << num << " is a Palindrome." << endl;
    else
        cout << num << " is not a Palindrome." << endl;

    return 0;
}