#include <iostream>
#include <vector>
#include <string>


template <typename T>
class Queue {
private:
    std::vector<T> items;
    size_t index = 0;

public:
    void push(const T& item) {
        items.push_back(item);
        std::cout << "Added: " << item << " to queue\n";
    }

    T pop() {
        T removedItem = items[index];
        index++;

        if (index > items.size() / 2) {
            items.erase(items.begin(), items.begin() + index);
            index = 0;
        }
        return removedItem;
    }

    T front() const {
        if (empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return items[index];
    }

    bool empty() const {
        return index >= items.size();
    }
};


int main()
{
    Queue<int> intQueue;

    intQueue.push(5);
    intQueue.push(8);
    intQueue.push(1);
    intQueue.push(7);

    std::cout << intQueue.pop() << " deleted from queue" << std::endl;
    std::cout << intQueue.pop() << " deleted from queue" << std::endl;
    std::cout << intQueue.pop() << " deleted from queue" << std::endl;

    return 0;
}
