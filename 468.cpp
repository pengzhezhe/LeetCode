//
// Created by pzz on 2022/5/29.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            return isIPv4(queryIP) ? "IPv4" : "Neither";
        } else {
            return isIPv6(queryIP) ? "IPv6" : "Neither";
        }
    }

    bool isIPv4(string address) {
        int prePos = -1;
        for (int i = 0; i < 4; i++) {
            int pos = (i == 3 ? address.size() : address.find('.', prePos + 1));

            if (pos == string::npos)
                return false;

            if (pos - prePos - 1 < 1 || pos - prePos - 1 > 3)
                return false;

            int num = 0;
            for (int j = prePos + 1; j < pos; j++) {
                if (!isdigit(address[j]))
                    return false;
                num = num * 10 + (address[j] - '0');
            }
            if (num > 255)
                return false;
            if (num > 0 && address[prePos + 1] == '0')
                return false;
            if (num == 0 && pos - prePos - 1 > 1)
                return false;
            prePos = pos;
        }
        return true;
    }

    bool isIPv6(string address) {
        int prePos = -1;
        for (int i = 0; i < 8; i++) {
            int pos = (i == 7 ? address.size() : address.find(':', prePos + 1));

            if (pos == string::npos)
                return false;

            if (pos - prePos - 1 < 1 || pos - prePos - 1 > 4)
                return false;

            for (int j = prePos + 1; j < pos; j++) {
                if (!isdigit(address[j]) && ! (tolower(address[j]) <= 'f' && tolower(address[j]) >= 'a'))
                    return false;
            }
            prePos = pos;
        }
        return true;
    }
};

int main() {
    return 0;
}