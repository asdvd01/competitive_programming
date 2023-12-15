#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

typedef long long ll;
using namespace std;
using namespace std::chrono;

vector<ll> add(const vector<ll>& a, const vector<ll>& b, ll base) {
    auto start = high_resolution_clock::now();
    vector<ll> sum;
    ll carry = 0;
    int i = 0;

    while (i < a.size() || i < b.size() || carry) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        sum.push_back(carry % base);
        carry /= base;
        ++i;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<", Time to sum = "<< duration.count()<<endl;
    return sum;
}

vector<ll> multiply(const vector<ll>& a, const vector<ll>& b, ll base) {
    auto start = high_resolution_clock::now();
    vector<ll> product(a.size() + b.size(), 0);

    for (int i = 0; i < a.size(); ++i) {
        ll carry = 0;
        for (int j = 0; j < b.size() || carry; ++j) {
            ll digit = product[i + j] + a[i] * (j < b.size() ? b[j] : 0) + carry;
            product[i + j] = digit % base;
            carry = digit / base;
        }
    }

    while (product.size() > 1 && product.back() == 0) {
        product.pop_back();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<", Time to multiply = "<< duration.count()<<endl;
    return product;
}

void printDigit(const vector<ll>& digits, ll base) {
  int w = log10(base);
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (i == digits.size() - 1) {
            cout << digits[i];
        } else {
            cout << setfill('0') << setw(w) << digits[i];
        }
    }
    cout << endl;
}

vector<ll> stringToBaseN(const string& str, ll base) {
    int pow = log10(base);
    vector<ll> digits;
    ll currentDigit = 0;
    int i = 0;
    ll remainingDigits = str.length();

    for (char c : str) {
        ll digit = c - '0';
        currentDigit = currentDigit * 10 + digit;
        remainingDigits--;

        if (remainingDigits % pow == 0 || i == str.length() - 1) {
            digits.push_back(currentDigit);
            currentDigit = 0;
        }
        i++;
    }

    reverse(digits.begin(), digits.end());
    return digits;
}

string generateRandomNumber(int n) {
    srand(time(0)); // use current time as seed for random generator
    string randomNumber;

    for (int i = 0; i < n; ++i) {
        randomNumber += '0' + std::rand() % 10; // generate a random digit
    }

    return randomNumber;
}

int main() {
    string numa, numb;
    int numDigits[7] = {100 , 200 , 500 , 1000 , 2000 , 5000 , 10000};
    for(int i=0 ; i< 7; i++){
        numa = generateRandomNumber(numDigits[i]);
        numb = generateRandomNumber(numDigits[i]);
        //cout<<"numa="<<numa<<endl;
        //cout<<"numb="<<numb<<endl;
        int bases[4]= {10, 100, 1000, 10000};
        for(int j=0 ; j< 4; j++){
            vector<ll> a = stringToBaseN(numa,bases[j]);
            vector<ll> b = stringToBaseN(numb,bases[j]);

            //vector<ll> sum = add(a, b, bases[j]);
            cout<<"Number of digits mutliplied = "<<numDigits[i]<<", Base used for calculation = "<<bases[j]<<" ";
            vector<ll> product = multiply(a, b, bases[j]);
            //cout<<"sum=";
            //printDigit(sum, bases[j]);
            //cout<<"product=";
            //printDigit(product, bases[j]);
        }
    }
    return 0;
}
