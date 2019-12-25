
#include "ShuntingYard.h"

bool ShuntingYard::isNumber(string &str) {
    int i = 0;
    bool isNum = false;
 //In case the number is negative, its made of '-' and then the actual number.
    if (str[0] == '-') {
        for (i = 1; i < str.size(); i++) {
            if (isdigit(str[i])) {
                isNum = true;
            } else {
                return false;
            }
        }
    }
        // positive number.
    else {
        for (i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                isNum = true;
            } else {
                return false;
            }
        }
    }
    return isNum;
}


bool ShuntingYard::isOperator(string &str) {
    return (str == PLUS || str == MINUS || str == MULT || str == DIV ||
            str == EQUAL || str == DIFFERENT || str == GREATER ||
            str == GREATER_EQUALL ||
            str == SMALLER || str == SMALLER_EQUALL ||
            str == POW);
}


int ShuntingYard::findPriority(string &str) {
    if (str == POW) {
        return 3;
    }
    if (str == MULT || str == DIV) {
        return 2;
    }
    if (str == PLUS || str == MINUS || str == GREATER || str == SMALLER ||
        str == GREATER_EQUALL || str == SMALLER_EQUALL || str == EQUAL ||
        str == DIFFERENT) {
        return 1;
    } else {
        return 0;
    }
}


stack<string> ShuntingYard::postfix(string src) {
    vector<string> objects;
    vector<string> list;
    stack<string> st;
    stack<string> postfixToReturn;
    string temp;
    istringstream stream(src);
    while (stream >> temp) {
        objects.push_back(temp);
    }
    int i;
    for (i = 0; i < objects.size(); i++) {
        if (this->isNumber(objects[i])) {
            list.push_back(objects[i]);
        } else if (objects[i] == LEFT_BRACKET) {
            st.push(objects[i]);
        } else if (objects[i] == RIGHT_BRACKET) {
            while (!st.empty() && st.top() != LEFT_BRACKET) {
                list.push_back(st.top());
                st.pop();
            }
            st.pop();
        } else if (isOperator(objects[i])) {
            while (!st.empty() &&
                findPriority(st.top()) >= findPriority(objects[i])) {
                list.push_back(st.top());
                st.pop();
            }
            st.push(objects[i]);
        } else if (objects[i].length() > 0) {
            list.push_back(objects[i]);
        }
    }
    while (!st.empty()) {
        list.push_back(st.top());
        st.pop();
    }
    int j;
    for (j = 0; j < list.size(); j++) {
        postfixToReturn.push(list[j]);
    }
    return postfixToReturn;
}
