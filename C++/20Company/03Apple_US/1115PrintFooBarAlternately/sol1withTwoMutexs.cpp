class FooBar {
private:
    int n;
    mutex fooMutex;
    mutex barMutex;
public:
    FooBar(int n) {
        this->n = n;
        barMutex.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            fooMutex.lock();
        	printFoo();
            barMutex.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            barMutex.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooMutex.unlock();
        }
    }
};