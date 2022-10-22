#include <iostream>
using namespace std;
class stack
{
    int top;
    int arr[5];

public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 4)
            return true;
        else
          return  false;
    }

    void push(int val)
    {
        if (isFull())
            cout << "stack overflow" << endl;

        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }

    int count()
    {
        return (top + 1);
    }

    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }

    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "The value changed at location " << pos;
    }

    void display()
    {
        cout << "The all value of stack are " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] <<"  ";
        }
    }
};

int main()
{
    stack s1;
    int option, value, position;
    do
    {
        cout << "choose option or press 0 to exit" << endl;
        cout << "0. exit" << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. isFull" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. count" << endl;
        cout << "6. peek" << endl;
        cout << "7. change" << endl;
        cout << "8. display" << endl;
        cout << "9. clear screen" << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the item to push" << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "The pop element is " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
            break;
        case 4:
            if (s1.isFull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
            break;
        case 5:
            cout << "The number of item in the stack is " << s1.count() << endl;
            break;
        case 6:
            cout << "Enter peek position " << endl;
            cin >> position;
            cout << "The element at " << position <<"position"<< " is " << s1.peek(position) << endl;
            break;
        case 7:
            cout << "Enter position to be changed" << endl;
            cin >> position;
            cout << "Enter value " << endl;
            cin>>value;
            s1.change(position, value);
            break;
        case 8:
            cout << "Elements of the stack are " << endl;
            s1.display();
            cout<<endl;
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter valid option" << endl;
        }
    } while (option != 0);

    return 0;
}