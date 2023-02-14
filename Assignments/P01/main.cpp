/*****************************************************************************
 *
 *  Author:           Sudhir Ray
 *  Email:            raysudhir30@gmail.com
 *  Label:            P01
 *  Title:            Vector Class
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *       This program implements a class that allows a singly-linked list to be
 *used similarly to a vector. The linked list can add and remove nodes with data
 *values, search existing nodes' values for a specific value, and it can be
 *sorted.  It also has print functionality to display the linked list similarly to an array.
 *
 *  Usage:
 *       N/A
 *
 *  Files:
 *       main.cpp    : driver program
 *       input.dat   : input file with values to test output
 *       text.out    : output file with results
 *****************************************************************************/

#include <fstream>
#include <iostream>
using namespace std;

#define INF 1000000000 // infinity
struct Node
{ // node for our linked list
    int data;
    Node *next;

    // constructor
    Node(int num)
    {
        data = num;
        next = nullptr;
    }
};

/**
 * Class Vector
 *
 * Description:
 *            The class has tools to create a linked list. The values in linked
 * list can be added from another vector, from an array. The class also has
 * various methods like push and pop to add and remove items from the list as
 * needed. The final output is written onto a output file named test.out.
 *
 *
 * Public Methods:
 *                Vector()
 *                Vector(int *A, int size)
 *                Vector(string FileName)
 *                Vector(const Vector &other)
 *                void init()
 *      void      inorderPush(int x)
 *      void      sortList()
 *      void      pushFront(int x)
 *      void      pushFront(const Vector &other)
 *      void      pushRear(int x)
 *      void      pushRear(const Vector &other)
 *      bool      pushAt(int i, int x)
 *      int       popFront()
 *      int       popRear()
 *      int       popAt(int loc)
 *      int       find(int val)
 *      void      print(ostream &outfile)
 *      void      print()
 *
 *
 * Private Methods:
 *      void      _inorderPush(int x)
 *
 *
 * Usage:
 *      v1.pushFront(18);        pushes 18 in vector v1
 *      v2.inorderPush(27);      pushes 27 in ordered vector v2
 *
 *
 */
class Vector
{
private:
    Node *head; // base pointer of list
    Node *tail; // to hold the address of the end of linked list
    int size;   // holds the temporary size of the list
    static ofstream fout;
    string fileName;
    bool sorted;

    void _inorderPush(int x)
    {
        Node *tempPtr = new Node(x); // allocate new node
        Node *prev = head;           // get previous and next pointers
        Node *curr = head;

        while (curr->data > x)
        { // loop to find proper location
            prev = curr;
            curr = curr->next;
        }

        tempPtr->next = prev->next; // add new node in its proper position
        prev->next = tempPtr;

        size++; // add to size :)
    }

public:
    /**
     * Public : Vector
     *
     * Description:
     *      default constructor of the vector class
     *      creates and empty linked list
     * Params:
     *      none
     *
     * Returns:
     *      -none
     */
    Vector() { head = tail = nullptr; }

    /**
     * Public : Vector
     *
     * Description:
     *     overloaded constructor of vector to initialize using array
     *
     * Params:
     *      int* :array of integers
     *      int :size of the array
     * Returns:
     *      -none
     */
    Vector(int *A, int size)
    {
        init();

        for (int i = 0; i < size; i++)
        {
            pushRear(A[i]);
        }
    }

    /**
     * Public : Vector
     *
     * Description:
     *      overloaded constructor of vector to initialize using data from an
     * input file. Reads data from the input file and adds it to the list
     *
     * Params:
     *      string : name of the data file
     * Returns:
     *      none
     */
    Vector(string FileName)
    {
        init();

        ifstream fin;
        int x = 0;

        fin.open(FileName);
        while (!fin.eof())
        {
            fin >> x;
            pushRear(x);
        }
    }

    /**
     * Public : Vector
     *
     * Description:
     *      overloaded constructor of vector to initialize using another vector.
     *
     * Params:
     *      Vector : address of the other vector to be copied.
     *
     * Returns:
     *      none
     */
    Vector(const Vector &other)
    {
        init();

        Node *temp = other.head;

        while (temp)
        {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    /**
     *   Initialize the data members so we don't
     *   have duplicate lines in each constructor.
     *
     */
    void init()
    {
        head = tail = NULL;
        fileName = "";
        size = 0;
        sorted = false;
    }

    /**
     * Public : inorderPush
     *
     * Description:
     *             The method pushes a given value in the list in correct order.
     *             The method checks if the list is sorted if not it sorts it and
     *              then inserts the value in correct place.
     * Params:
     *      int     : value to be inserted in the list
     *
     * Returns:
     *      none
     */

    void inorderPush(int x)
    {
        if (!sorted)
        {
            sortList();
        }

        if (!head)
        {
            pushFront(x); // call push front for empty list
        }
        else if (x < head->data)
        {
            pushFront(x); // call push front if x is less than head
        }
        else if (x > tail->data)
        {
            pushRear(x); // call push rear if x > tail
        }
        else
        {
            _inorderPush(x); // call private version of push in order
        }
    }

    /**
     * Public : sortList
     *
     * Description:
     *             The method sorts the list in proper order.
     * Params:
     *       none
     *
     * Returns:
     *      none
     */

    void sortList()
    {
        Node *newFront = head;
        while (newFront->next)
        {
            Node *smallest = newFront;
            Node *current = newFront;
            int minimum = INF;
            while (current)
            {
                if (current->data < minimum)
                {
                    smallest = current;
                    minimum = current->data;
                }
                current = current->next;
            }
            smallest->data = newFront->data;
            newFront->data = minimum;
            newFront = newFront->next;
        }
        sorted = true;
    }

    /**
     * Public : pushFront
     *
     * Description:
     *      Pushes a number x at the front of the list
     *
     * Params:
     *      int : number to be put in the list
     *
     * Returns:
     *      void
     */
    void pushFront(int x)
    {
        Node *tempPtr = new Node(x);

        // empty list make head and tail
        // point to new value
        if (!head)
        {
            head = tail = tempPtr;
            // otherwise adjust head pointer
        }
        else
        {
            tempPtr->next = head;
            head = tempPtr;
        }
        size++;
    }

    /**
     * Public : pushFront
     *
     * Description:
     *      this function will place a pre-existing linked list at the front of
     * another linked list. Params:
     *      - Vector :  list to be pushed at thr front of the another list
     * Returns:
     *      -void
     */
    void pushFront(const Vector &other)
    {
        Node *otherPtr = other.head;         // get copy of other lists head
        int *tempData = new int[other.size]; // allocate memory to hold values

        // load other list into array
        int i = 0;
        while (otherPtr)
        {
            tempData[i] = otherPtr->data;
            otherPtr = otherPtr->next;
            ++i;
        }

        // process list in reverse in order to keep them
        // in their original order.
        for (int i = other.size - 1; i >= 0; i--)
        {
            pushFront(tempData[i]);
        }
    }

    /**
     * Public : pushRear
     *
     * Description:
     *      Pushes a number x at the back of the list
     *
     * Params:
     *      int : number to be put in the list
     *
     * Returns:
     *      void
     */
    void pushRear(int x)
    {
        Node *tempPtr = new Node(x);

        if (!head)
        {
            head = tail = tempPtr;
        }
        else
        {
            tail->next = tempPtr;
            tail = tempPtr;
        }
        size++; // add to size of list
    }

    /**
     * Public : pushRear
     *
     * Description:
     *      this function will place a pre-existing linked list at the back of
     * another linked list. Params:
     *      - Vector :  list to be pushed at thr front of the another list
     * Returns:
     *      -void
     */

    void pushRear(const Vector &other)
    {
        Node *otherPtr = other.head; // get copy of other lists head

        while (otherPtr)
        { // traverse and add
            pushRear(otherPtr->data);
            otherPtr = otherPtr->next;
        }
    }

    /**
     * Public : pushAt
     *
     * Description:
     *            The method pushes a value at given index.
     *
     * Params:
     *      int     : index of the list
     *      int     : value to be inserted in the list
     *
     * Returns:
     *      bool    : returns true if inserted else false.
     */

    bool pushAt(int i, int num)
    {
        if (i >= size)
        {
            return false;
        }

        Node *tempPtr = new Node(num); // allocate new node
        Node *prev = head;             // get previous and next pointers
        Node *curr = head;

        while (i > 0)
        { // loop to find proper location
            prev = curr;
            curr = curr->next;
            i--;
        }

        tempPtr->next = prev->next; // add new node in its proper position
        prev->next = tempPtr;

        size++; // add to size :)
        return true;
    }

    /**
     * Public : popFront
     *
     * Description:
     *            The method removes a value from the front of the list.
     *
     * Params:
     *       none
     *
     * Returns:
     *      int     : returns the removed data
     */

    int popFront()
    {
        if (head == nullptr)
        { // If the list is empty, return -1
            return -1;
        }
        int removedData = head->data;
        head = head->next;
        return removedData; // Otherwise return the popped node's data.
    }

    /**
     * Public : popRear
     *
     * Description:
     *            The method removes a value from the rear of the list.
     *
     * Params:
     *      none
     *
     * Returns:
     *      int    : returns the removed data otherwise returns -1
     */

    int popRear()
    {
        int hold;

        if (head)
        {

            Node *traverse = head;
            Node *prev = NULL;
            while (traverse->next != NULL)
            {
                prev = traverse;
                traverse = traverse->next;
            }

            hold = traverse->data;
            delete traverse;
            traverse = NULL;
            prev->next = NULL;
            size -= 1;

            return hold;
        }

        else
        {

            return -1;
        }
    }

    /**
     * Public : popAt
     *
     * Description:
     *            The method removes a value from specified location of the list.
     *
     * Params:
     *      int    : index or location of the node to be removed.
     *
     * Returns:
     *      int    : returns the removed data otherwise returns -1
     */

    int popAt(int loc)
    {
        int val = 0;

        if (loc == 0)
            return popFront();

        else if (head == NULL)
        {
            cout << "no items";
            return 0;
        }

        else
        {
            Node *traverse = head;
            for (int i = 0; i < (loc - 1); i++)
            {

                traverse = traverse->next;
            }

            if (traverse->next == NULL)
                return popRear();

            else
            {

                Node *temp = traverse->next;
                traverse->next = traverse->next->next;
                val = temp->data;

                delete temp;
                size -= 1;
                return val;
            }
        }
    }
    /**
     * Public : find
     *
     * Description:
     *            The method finds the location of the value entered by the user.
     *
     * Params:
     *      int    : value to be searched
     *
     * Returns:
     *      int    : returns the location of the value to be removed.
     */

    int find(int val)
    {
        // If list is empty, return -1
        if (head == nullptr)
        {
            return -1;
        }
        Node *travel = head;
        int index = 0;
        while (travel)
        {
            if (travel->data == val)
            {
                // If the value matches the current node's data, return the node index
                return index;
            }
            else
            {
                travel = travel->next;
                index++;
            }
        }
        // If value was not found in the linked list, return -1
        return -1;
    }

    void print(ostream &outfile)
    {
        Node *traverse = head;
        outfile << "[";
        cout << "[";
        while (traverse != NULL)
        {
            outfile << traverse->data << " ";
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
        outfile << "]" << endl;
        cout << "]" << endl;
    }
};

int main()
{
    ofstream outfile;
    outfile.open("test.out");
    outfile << "Sudhir Ray\n02/09/2023\nSpring 2143\n"
            << endl;
    outfile.close();
    outfile.open("test.out", fstream::app);

    int x = 0;

    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print(outfile);
    // [25, 20, 18, 18, 20, 25]

    int A[] = {11, 25, 33, 47, 51};
    Vector v2(A, 5);
    v2.print(outfile);
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    v2.inorderPush(27);
    v2.pushRear(63);
    v2.print(outfile);
    // [9, 11, 25, 27 33, 47, 51, 63]

    v1.pushRear(v2);
    v1.print(outfile);
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print(outfile);
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
    cout << x << endl;
    outfile << x << endl;
    // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print(outfile);
    // [18, 20, 25, 9, 11, 25, 27, 33]
    cout << x << endl;
    outfile << x << endl;
    // 47

    x = v2.popAt(3);
    v2.print(outfile);
    // [9, 11, 25, 33, 47, 51, 63]
    cout << x << endl;
    outfile << x << endl;
    // 27

    x = v2.find(51);
    cout << x << endl;
    outfile << x << endl;
    // 5

    x = v2.find(99);
    cout << x << endl;
    outfile << x << endl;
    // -1

    Vector v3(v1);
    v3.print(outfile);
    // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);
    v3.print(outfile);
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    Vector v4("input.dat");
    v4.pushRear(v3);
    v4.print(outfile);
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18,
    // 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47,
    // 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
}

