#include <vector>
#include "functions.h"

using namespace std;
int main() {
    Queue<int> q;
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }
    cout << "Queue elements: ";
    int initial_count = q.size();
    for (int i = 0; i < initial_count; ++i) {
        std::cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
    cout << "Moving front element to rear." << endl;
    q.move_to_rear();

    cout << "Queue elements after move_to_rear: ";
    initial_count = q.size();
    for (int i = 0; i < initial_count; ++i) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;

    vector<int> items = { 1, 2, 3, 4, 3, 5, 3 };
    int target = 3;

    int position = linear_search_last(items, target, items.size() - 1);

    if (position != -1) {
        cout << "Last occurrence of " << target << " found at index: " << position << endl;
    }
    else {
        cout << "Target not found in the vector." << std::endl;
    }
    Queue<int> q2;
    q2.push(3);
    q2.push(1);
    q2.push(4);
    q2.push(1);
    q2.push(5);
    q2.push(9);
    q2.push(2);
    q2.push(6);

    cout << "Queue before sorting: ";
    int sort_count = q2.size();
    for (int i = 0; i < sort_count; ++i) {
        std::cout << q2.front() << " ";
        q2.push(q2.front());
        q2.pop();
    }
    std::cout << endl;

    // sort queue
    q2.insertion_sort();

    // display queue after sorting
    cout << "Queue after sorting: ";
    sort_count = q2.size();
    for (int i = 0; i < sort_count; ++i) {
        std::cout << q2.front() << " ";
        q2.push(q2.front());
        q2.pop();
    }
    cout << endl;

    return 0;
}