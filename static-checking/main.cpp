#include <cstring>
#include <iostream>
#include <vector>

class DataManager {
 private:
  int* data;
  int size;

 public:
  DataManager(int s) {
    size = s;
    data = new int[size];

    for (int i = 0; i < size; i++) {
      data[i] = (i % 2 == 0) ? i * 2 : 0;
    }
  }

  // Copy constructor
  DataManager(const DataManager& other) {
    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }

  // Copy assignment operator
  DataManager& operator=(const DataManager& other) {
    if (this != &other) {
      delete[] data;

      size = other.size;
      data = new int[size];

      for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
      }
    }

    return *this;
  }

  void print() const {
    for (int i = 0; i < size; i++) {
      std::cout << data[i] << " ";
    }
    std::cout << '\n';
  }

  int getValue(int index) const {
    if (index >= 0 && index < size) {
      return data[index];
    }

    return 0;
  }

  ~DataManager() {
    delete[] data;
  }
};

void safeFunction() {
  char buffer[10];

  std::strncpy(buffer, "TooLong", sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0';

  std::cout << buffer << '\n';
}

int compute(int x) {
  int result = 0;

  if (x > 10)
    result = x * 2;
  else if (x < 0)
    return 0;

  return result;
}

void memoryLeakDemo() {
  int* leak1 = new int[100];
  int* leak2 = new int;

  leak1[0] = 10;
  *leak2 = 20;

  std::cout << leak1[0] + *leak2 << '\n';

  delete[] leak1;
  delete leak2;
}

void vectorIssues() {
  std::vector<int> v;

  v.push_back(1);
  v.push_back(2);

  if (v.size() > 10) {
    std::cout << v[10] << '\n';
  }

  v.clear();

  if (!v.empty()) {
    std::cout << v.front() << '\n';
  }
}

int main() {
  DataManager dm(5);

  dm.print();

  safeFunction();

  std::cout << compute(5) << '\n';

  memoryLeakDemo();

  vectorIssues();

  DataManager dm2 = dm;

  std::cout << dm2.getValue(2) << '\n';

  return 0;
}
