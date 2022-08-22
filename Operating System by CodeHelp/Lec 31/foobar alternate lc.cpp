class FooBar {
private:
    int n;
    std::mutex m;
    condition_variable cv;
    bool turn;

public:
    FooBar(int n) {
        this->n = n;
        turn =0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            while(turn){
                cv.wait(lock);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
            std::unique_lock<std::mutex> lock(m);
            while(!turn){
                cv.wait(lock);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 0;
            cv.notify_all();
        }
    }
};