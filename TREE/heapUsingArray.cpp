#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

class MinHeap
{
public:
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // current number of elements in min heap

    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    void linearSearch(int val)
    {
        for (int i = 0; i < heap_size; i++)
        {
            if (harr[i] == val)
            {
                cout << "value found" << endl;
                return;
            }
        }
        cout << "value not found" << endl;
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << "\n";
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int left(int i) // return the left child of node i
    {
        return (2 * i + 1);
    }
    int right(int i) // return the right child of node i
    {
        return (2 * i + 2);
    }

    int getMin()
    {
        return harr[0];
    }

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "Heap overflow : Could insert key \n";
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while ((i != 0) && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
        cout << k << " inserted!" << endl;
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if ((l < heap_size) && (harr[l] < harr[i]))
            smallest = l;
        if ((r < heap_size) && (harr[r] < harr[smallest]))
            smallest = r;
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }
        // store the minimum value, and remove it from heap
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        return root;
    }

    // function for deleting elements from heap
    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main()
{
    int s;
    cout << "Enter the capacity of heap : ";
    cin >> s;
    MinHeap obj(s);

    int option, val;
    do
    {
        cout << "Choose option" << endl;
        cout << "1. Insert key/node" << endl;
        cout << "2. Search key/node" << endl;
        cout << "3. Delete key/node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height min" << endl;
        cout << "7. print/traversal heap values" << endl;
        cout << "8. Clear screan" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Insert operation -" << endl;
            cout << "Enter the value to insert in heap : ";
            cin >> val;
            obj.insertKey(val);
            cout << "\n";
            break;
        case 2:
            cout << "Search operation -" << endl;
            cout << "Enter the value to search in heap : ";
            cin >> val;
            obj.linearSearch(val);
            cout << "\n";
            break;

        case 3:
            cout << "Delete operation";
            cout << "Enter Index of Heap Array to Delete :";
            cin >> val;
            obj.deleteKey(val);
            break;

        case 4:
            cout << "Get Min Value : ";
            cout << obj.getMin() << endl;
            cout << "\n";
            break;

        case 5:
            cout << " Extract Min value : ";
            cout << obj.extractMin() << endl;
            cout << endl;
            break;

        case 6:
            cout << "Heap Tree Height : ";
            cout << obj.height() << endl;
            break;

        case 7:
            cout << "Print Heap Array : ";
            obj.printArray();
            cout << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter proper option " << endl;
        }
    } while (option != 0);
}