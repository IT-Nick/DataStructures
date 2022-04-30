#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class Vector {
public:
    explicit Vector(size_t size) {
        data = new T[size];
        end_ = data + size;
    }

    ~Vector() {
        delete[] data;
    }

    T& operator[] (size_t index) {
        return data[index];
    }

    const T* begin() const { return data; }
    const T* end() const { return end_; }

    T* begin() { return data; }
    T* end() { return end_; }
private:
    T* data;
    T* end_;
};

template<typename T>
void Print(const Vector<T>& d) {
    for(const auto& x : d) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    Vector<int> v(5);
    for (int i = 0; i < 5; ++i) {
        v[i] = 5 - i;
    }
    Print(v);
    sort(v.begin(), v.end());
    Print(v);
    return 0;
}
