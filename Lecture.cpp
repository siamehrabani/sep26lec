#include<iostream>
#include <stdexcept>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

class Class1 {
private:
    int data; // member variable
public:
    //Class1(int value) { // constructor
    //    data = value;
    //}
    Class1(int value) : data(value) {}
        void printData() {  // member function
        cout << "Data: " << data << endl;
    }
};

class Class2 {
private:
    string data; // member variable
public:
    //Class1(int value) { // constructor
    //    data = value;
    //}
    Class2(string value) : data(value) {}
        void printData() {  // member function
        cout << "Data: " << data << endl;
    }
};

// ---------------------------------------------------------
// generic class // its a template definining a generic class
// can work with different types of data

template <typename T>
class Myclass {
    private:
        T data;
    public:
    Myclass(T value) : data(value) {}
    void printData() {
        cout << "Data: " << data << endl;
    }    
};

// ---------------------------------------------------------

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode;
    int stackSize;
public:
    Stack() : topNode(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }


    void push(const T& value) {

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }


    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;    
    }
    bool isEmpty() const {
        return topNode == nullptr;
    }        

    // const member function
    // the first const means the return reference cant be changed
    // the second const means the function does not modify the object

    const T& peek() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty\n");
        }
        return topNode->data;
    }

    int size() const {
        return stackSize;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void print () const {
        Node* current = topNode;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};


int main()
{
//     Class1 o1(3);
//     o1.printData();
//     Class2 o2("allen");
//     o2.printData();
// // ---------------------------------------------------------
//     Myclass<int> ob1(10);
//     ob1.printData();
//     Myclass<double> ob2(3.14);
//     ob2.printData();
//     Myclass<string> ob3("Hello");
//     ob3.printData();
// // ---------------------------------------------------------    

    Stack<int> stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);

    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element: " << stack.peek() << endl;
// stack.peek() = 250;
    cout << "Top element: " << stack.peek() << endl;
    cout << "Is the stack empty? " <<  (stack.isEmpty() ? "Yes" : "No") << endl;
//----------------------------------------------
    cout << "------------------------\n" << endl;
    Stack<double> stack2;
    stack2.push(10.1);
    stack2.push(20.2);
    stack2.push(30.3);
    cout << "Top element: " << stack2.peek() << endl;
//----------------------------------------------
    cout << "------------------------\n" << endl;
    Stack<Student> stack3;
    Student s1 = { "Allen", 19,3.14 };
    stack3.push(s1);
    cout << "Top element: " << stack3.peek().name << endl;
    cout << "Top element: " << stack3.peek().age << endl;
    cout << "Top element: " << stack3.peek().gpa << endl;
    cout << "------------------------\n" << endl;
//----------------------------------------------


    return 0;
}