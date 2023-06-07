class FooBar {
private:
    int n;
    atomic<bool> check;
    // mutex fooMutex;
    // mutex barMutex;
public:
    FooBar(int n) {
        this->n = n;
        // barMutex.lock();
        check = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            // fooMutex.lock();
            while(!check){
                this_thread::yield();
            }
            printFoo();
            check = !check;
            // barMutex.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            // barMutex.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
            while(check){
                this_thread::yield();
            }
            printBar();
            check = !check;
            // fooMutex.unlock();
        }
    }
};