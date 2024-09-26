#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int MAX_BUFFER_SIZE = 5;

queue<int> buffer; //Sharing buffer
mutex mtx;//Lock for multithreading
condition_variable pro_cv;
condition_variable con_cv;

bool isBufferNotFull() {
	return buffer.size() < MAX_BUFFER_SIZE;
}

bool isBufferNotEmpty() {
	return !buffer.empty();
}

void producer(int id) {
	for (int i = 0; i < 100; ++i) {
		unique_lock<mutex> lock(mtx); //Hold the mutex lock
		pro_cv.wait(lock, isBufferNotFull);
		buffer.push(i);
		std::cout << "Producer " << id << " produced: " << i << std::endl;
		lock.unlock();
		con_cv.notify_one();
	}
}

void consumer(int id) {
	for (int i = 0; i < 100; ++i) {
		unique_lock<mutex> lock(mtx);
		con_cv.wait(lock, isBufferNotEmpty);
		int cur = buffer.front();
		buffer.pop();
		std::cout << "Consumer " << id << " consumed: " << cur << std::endl;
		lock.unlock();
		pro_cv.notify_one();
	}
}

 
int main(int argc, char argv[]) {
	thread pro1(producer, 1);
	thread con1(consumer, 1);
	pro1.join();
	con1.join();
	return 0;
}