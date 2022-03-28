class PhoneDirectory {
public:
    PhoneDirectory(int maxNumbers) {
        n = maxNumbers;
        available = new int[n];
        isAvailable = new bool[n];
        for (int i=0; i<n; i++) {
            available[i] = i;
            isAvailable[i] = true;
        }
    }
    
    ~PhoneDirectory() {
        delete available;
        delete isAvailable;
    }

    int get() {
        if (!n)
            return -1;
        int number = available[--n];
        isAvailable[number] = false;
        return number;
    }
    
    bool check(int number) {
        return isAvailable[number];
    }
    
    void release(int number) {
        if (!isAvailable[number]) {
            isAvailable[number] = true;
            available[n++] = number;
        }
    }
private:
    int n;
    int *available;
    bool *isAvailable;
};