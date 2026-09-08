#include <iostream>
using namespace std;

#define MAX 5

class Queue{
      private:
        string arr[MAX];
        int front;
        int rear;

     public:
        Queue()
        {
        front =-1;
        rear= -1;
        }
        void EnQueue(string name)
        {
        if (rear == MAX-1)
        {
            cout<< "Queue is Full! Cannot Insert " << name << endl;
            return;
        }
        if (front =-1)
            front = 0;

            rear++;
            arr[rear] = name;
            cout << name << " was inserted into the queue" << endl;
    }

    void DeQueue()
    {
        if (front == -1 || rear < front)
        {
            cout << "Queue is Empty! Insert an Element" << endl;
            return;
        }
        cout << arr[front] << "was deleted from the queue." << endl;
        front++;

        if(front > rear)
        {
            front = rear =-1;
        }
    }

    void Display()
    {
        if (front == -1)
        {
           cout << "Queue is Empty!! Enter an Element." << endl;
           return;
        }
        cout << "Queue Elements:------------------------------------------------------" << endl;
        for(int i= front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
    }
};

int main()
{
    Queue Q;
    int choice;
    string name;

    do
    {
      cout << "\n========TICKET BOOKING COUNTER========\n";
      cout << " 1.ADD CUSTOMER \n 2.DELETE CUSTOMER \n 3.SHOW CUSTOMER ORDER \n 4.Exit \n";
      cout << "Enter from the following Choice: 1-4: \n";
      cin >> choice;

    switch (choice)
    {
    case 1: //enqueue
        cin.ignore();
        cout << "Enter Name of the Customer to add.\n";
        getline(cin, name);
        Q.EnQueue(name);
        break;
    case 2: //dequeue
        Q.DeQueue();
        break;
    case 3: //disp
        Q.Display();
        break;
    case 4:
        cout << "Exiting Program..........\n";
        break;
    default:
        cout << "Invalid Choice!\n";
      }
    } while (choice != 5);
      return 0;
}
