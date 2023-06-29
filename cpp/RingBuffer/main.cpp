#include <iostream>
#include "ringbuf.h"

using namespace std;

int main()
{
    const int size = 9;
    RingBuffer<int> buf(size);
    std::cout << "Initial size of buffer: " << buf.getSize() << std::endl;
    std::cout << '\n';

    buf.push(1);
    buf.push(2);
    buf.push(3);
    buf.push(4);

    std::cout << "We added 4 elements. Now current size is: " << buf.getSize() << std::endl;
    std::cout << '\n';

    bool b = true;
    if (b)
    {
        RingBuffer<int> buf_new = buf;
        std::cout << "We created a NEW object based on the OLD one inside IF" << std::endl;
        std::cout << "The size of NEW object is: " << buf_new.getSize() << std::endl;
        buf_new.pop();
        buf_new.pop();
        std::cout << "Removed 2 elements from NEW object. Current Size of NEW object is: " << buf_new.getSize() << std::endl;
    }
    std::cout << "Exited the IF body." << std::endl;
    std::cout << "The NEW object was auto-removed." << std::endl;
    std::cout << "The size of OLD object is: " << buf.getSize() << std::endl;
    std::cout << "Deep copying was successfully performed!" << std::endl;
    std::cout << '\n';

    std::cout << "Let's continue working with the OLD object." << std::endl;
    buf.push(5);
    buf.push(6);
    buf.push(7);
    buf.push(8);
    buf.push(9);
    std::cout << "Added 5 elements more. Current Size is: " << buf.getSize() << std::endl;
    std::cout << "Buffer is full? Answer: " << buf.isFull() << std::endl;
    std::cout << '\n';

    buf.pop();
    buf.pop();
    std::cout << "Removed 2 elements. Current Size is: " << buf.getSize() << std::endl;
    std::cout << "The last added element is: " << buf.back() << std::endl;
    std::cout << "The oldest element is: " << buf.front() << std::endl;
    std::cout << '\n';

    for (int i=0; i < 7; i++)
        buf.pop();
    std::cout << "We removed remaining elements" << std::endl;
    std::cout << "Buffer is empty now? Answer: " << buf.isEmpty() << std::endl;

    return 0;
}
