#include <bits/stdc++.h>
#include <string.h>
using namespace std;
class arrays
{
    string arr[100];
    int element;
    public:
    arrays(){
        element=-1;
    }
    int getElement(){
        return element;
    }
    void insert(string data)
    {
        element++;
        arr[element] = data;
    }
    void insertp(string data, int position)
    {
        element++;
        int i = element;
        while (i != position)
        {
            arr[i] = arr[i - 1];
            i--;
        }
        arr[position] = data;
    }
    int linSearch(string val)
    {
        int i = 0;
        for (i = 0; i <= element; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void sort()
    {
        for (int i = 0; i <= element; i++)
        {
            for (int j = 1; j <= element - i; j++)
            {
                if ( arr[j - 1].length() > arr[j].length()||arr[j - 1] > arr[j])
                {
                    string x = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = x;
                }
            }
        }
    }
    int binarySearch(string item)
    {
        int start = 0;
        int end = element;
        int mid = (start + end) / 2;
        while (start <= end && (arr[mid] != item || arr[mid].length() != item.length()))
        {
            if (arr[mid] < item)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        if (arr[mid] == item)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }

    void printArray()
    {
        for (int i = 0; i <= element; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
void operation(char op)
{
   
}
int main()
{
      arrays ar;
    string st;
    char op;
    cout << "To insert multiple element to array type \"1\" :\nTo insert element at begin type \"2\":\nTo insert elemnt to end typ\"3\":\n";
    cout<<"To insert element at any position at the array type\"4\":\nTo print the array type \"5\":\nTo sort the element type \"6\":\n";
    cout<<"For linear Search type \"7\":\nFor binary search type \"8\":\n";
    while(cin.peek()!='E'){
    cin >> op;
   
    int pos;
    switch (op)
    {
    case '1':
        cout << "Insert element to the array until press \"Enter\":\n";
        cin >> st;
        ar.insert(st);
        while (cin.peek() != '\n')
        {
            cin >> st;
            ar.insert(st);
        }
        break;
    case '2':
        cout << "Type data :\n";
        cin >> st;
        ar.insertp(st, 0);
        break;
    case '3':
        cout << "Type data :\n";
        cin >> st;
        ar.insert(st);
        break;
    case '4':
        cout << "Enter data then space then Position\n";
        cin >> st >> pos;
        ar.insertp(st, pos - 1);
        break;
    case '5':
        ar.printArray();
        break;
    case '6':
        ar.sort();
        break;
    case '7':
        cin >> st;
       cout<< ar.linSearch(st)<<endl;
        break;
    case '8':
        cin >> st;
       cout<< ar.binarySearch(st)<<endl;
        break;

    default:
        break;
    }
    cout<<"again\n";
     
    }
}