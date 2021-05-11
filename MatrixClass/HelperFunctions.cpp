#pragma once
#include "vector"
#include "stack"
#include "queue"
#include "iostream"
#include "string"
#include "sstream"

using namespace std;

class HelperFunctions {

public:
    static int factorial(int x) {
        if (x == 0) {
            return 1;
        }
        else if (x == 1) {
            return 1;
        }

        return x * factorial(x - 1);
    }


    static void PrintStack(stack<int> s)
    {
        // If stack is empty
        if (s.empty())
            return;

        // Extract top of the stack
        int x = s.top();

        // Pop the top element
        s.pop();

        // Print the current top
        // of the stack i.e., x
        cout << char(x) << ' ';

        // Proceed to print
    // remaining stack
        PrintStack(s);

        // Push the element back
        s.push(x);
    }
    static void PrintQueue(queue<int> q) {
        while (!q.empty()) {
            cout << ' ' << q.front();
            q.pop();
        }
    }

    //parsing experssion with infix;
    static void parse(string s) {
        string tempString("");
        int a;
        stack<int> myStack;
        queue<int> myQueue;

        for (int i = 0; i < s.size(); i++) {
            stringstream st(tempString);
            if (s[i] == ' ') continue;
            if (s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '+') {

                st >> a;
                myQueue.push(a);
                myStack.push(s[i]);

                tempString = "";

            }
            else if (i == s.size() - 1) {
                tempString += (s[i]);
                st.str(tempString);
                st >> a;

                myQueue.push(a);

                tempString = "";
            }
            else

                tempString += (s[i]);


        }

        PrintQueue(myQueue);
        cout << endl;
        PrintStack(myStack);

    }


};