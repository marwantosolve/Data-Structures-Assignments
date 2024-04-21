//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//
//class student
//{
//public:
//    string id;
//    string name;
//    double gpa;
//    student() : id("NULL"), name("NULL"), gpa(0.0) {}
//    student(string ID, string NAME, double GPA) : id(ID), name(NAME), gpa(GPA) {}
//
//    bool operator < (const student& another) {
//        return name < another.name;
//    }
//    bool operator > (const student& another) {
//        return name > another.name;
//    }
//
//
//};
//
//
//
//template<typename T>
//void insertionSort(vector<T>& arr) {
//    int n = arr.size();
//    for (int i = 1; i < n; i++) {
//        T key = arr[i];
//        int j = i - 1;
//        while (j >= 0 && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//}
//template<typename T>
//void selectionSort(vector<T>& arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; i++) {
//        int minIndex = i;
//        for (int j = i + 1; j < n; j++) {
//            if (arr[j] < arr[minIndex]) {
//                minIndex = j;
//            }
//        }
//        if (minIndex != i) {
//            swap(arr[i], arr[minIndex]);
//        }
//    }
//}
//template<typename T>
//void bubbleSort(vector<T>& arr) {
//    int n = arr.size();
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);
//            }
//        }
//    }
//}
//template<typename T>
//void shellSort(vector<T>& arr) {
//    int n = arr.size();
//
//    for (int gap = n / 2; gap > 0; gap /= 2) {
//
//        for (int i = gap; i < n; i += 1) {
//
//            T temp = arr[i];
//
//            int j;
//            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//
//            arr[j] = temp;
//        }
//    }
//}
//
//
//
//class stu_list {
//private:
//    vector <student> v;
//    int size;
//public:
//    stu_list(string file_name) {
//        ifstream infile(file_name);
//        bool file_exists = infile.is_open();
//        if (file_exists) {
//            string line;
//            getline(infile, line);
//            size = stoi(line);
//            for (int i = 0; i < size; i++)
//            {
//                getline(infile, line);
//                string name = line;
//                getline(infile, line);
//                string id = line;
//                getline(infile, line);
//                double gpa = stod(line);
//                v.push_back(student(id, name, gpa));
//            }
//            infile.close();
//        }
//        else {
//            cout << "ERROR,File not Found" << endl;
//        }
//    }
//    void print()
//    {
//        for (auto element : v) {
//            cout << element.name << endl;
//            cout << element.id << endl;
//            cout << element.gpa << endl;
//        }
//    }
//
//    // Function to sort the student vector by name using Insertion Sort
//    void sortByName() {
//
//        int choice;
//
//
//        cout << "Menu:\n";
//        cout << "1. Insertion Sort\n";
//        cout << "2. Selection Sort\n";
//        cout << "3. Bubble Sort \n";
//        cout << "4. Shell Sort \n";
//        cout << "5. Merge Sort \n";
//        cout << "6. Quick Sort \n";
//
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                insertionSort(v);
//                break;
//            case 2:
//                selectionSort(v);
//                break;
//            case 3:
//                bubbleSort(v);
//                break;
//            case 4:
//                shellSort(v);
//                break;
//            case 5:
//
//                break;
//            case 6:
//
//                break;
//            default:
//                cout << "Invalid choice.\n";
//        }
//
//    }
//};
//
//int main() {
//    stu_list students("student.txt");
//
//    students.sortByName();
//
//    cout << "After sorting:" << endl;
//    students.print();
//
//    return 0;
//}
