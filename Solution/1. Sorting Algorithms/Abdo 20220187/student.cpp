/*
done
1. Implement the student class with its constructor.
2. Overload the operator < such that it compares the names
of two student objects.
3. Read student objects from a file named students.txt, which will have
the number of students followed by their information
4. Implement Insertion Sort, Selection Sort, Bubble Sort, Shell Sort,mergr sort and Quick Sort4.
a. Each algorithm should be a separate function implemented using
templates to allow sorting of different types of data.
5. Sort the array of students’ objects with each of the previous algorithms.
a. Sort the data one time by Name and another time by GPA.
6. Calculate the running time of each algorithm for each array.

still


7. The output will be two files, SortedByGPA.txt and SortedByName.txt. Each file
contains:
a. Algorithm name.
b. Number of comparisons.
c. Running Time.
d. Sorted Student Elements.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
using namespace std;



//class student contain all data foe each student
class student
{
public:
    string id;
    string name;
    double gpa;
    static int sort_by;
    student() : id("NULL"), name("NULL"), gpa(0.0) {}
    student(string ID, string NAME, double GPA) : id(ID), name(NAME), gpa(GPA) {}

    bool operator < (const student& another) {
        if (sort_by == 0)
            return name < another.name;
        else if (sort_by == 1)
            return gpa < another.gpa;
        else
            return id < another.id;
    }
    bool operator > (const student& another) {
        if (sort_by == 0)
            return name > another.name;
        else if (sort_by == 1)
            return gpa > another.gpa;
        else
            return id > another.id;
    }

};


// class stu_list read data from file and put it in a vector then write in a new file
class stu_list {
private:
    vector <student> v;
    int size;
    string sorting_type;
public:
    stu_list() {}
    stu_list(string file_name) {
        ifstream infile(file_name);
        bool file_exists = infile.is_open();
        if (file_exists) {
            string line;
            getline(infile, line);
            size = stoi(line);
            for (int i = 0; i < size; i++)
            {
                getline(infile, line);
                string name = line;
                getline(infile, line);
                string id = line;
                getline(infile, line);
                double gpa = stod(line);
                v.push_back(student(id, name, gpa));
            }
            infile.close();
        }

        else {
            cout << "ERROR,File not Found" << endl;
        }
    }

    void list(vector <student>& list) {
        for (int i = 0; i < size; i++)
        {
            list.push_back(v[i]);
        }
    }

    void OutPut_File(string file_name, string algo, double Dur) {
        ofstream outfile(file_name , ios::app);

        if (outfile.is_open()) {
            outfile << "Algorithm: " << algo << endl;
            outfile << "Runtime: " << Dur << " microseconds" << endl;
            for (auto element : v)

            {
                outfile << element.name << endl;
                outfile << element.id << endl;
                outfile << element.gpa << endl;

            }
        }
        else {
            cout << "Unable to open file";
        }
        outfile << endl << "****************************************************************************" << endl;
    }


    void print()
    {
        for (auto element : v) {
            cout << element.name << endl;
            cout << element.id << endl;
            cout << element.gpa << endl;
        }
    }


};

//sorting functions

//insertion Sort
template<typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


//selectionSort
template<typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}



//bubble Sort
template<typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


//shellSort
template<typename T>
void shellSort(vector<T>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i += 1) {

            T temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}


//Merg sort
template <class T>
void mergeSort(vector<T>& arr, int const begin, int const end)
{
    if (begin >= end)
        return; // Base case:

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}
//merg
template <class T>
void merge(vector<T>& arr, int const left, int const mid, int const right)
{
    int const subArrayOneSize = mid - left + 1;
    int const subArrayTwoSize = right - mid;
    // Create temp arrays
    T* leftArray = new T[subArrayOneSize];
    T* rightArray = new T[subArrayTwoSize];
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOneSize; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwoSize; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOneSize
        && indexOfSubArrayTwo < subArrayTwoSize) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of left[], if there are any
    while (indexOfSubArrayOne < subArrayOneSize) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwoSize) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}


//Quick Sort
template<typename T>
void quickSort(vector<T>& arr, int left, int right) {
    int i = left, j = right;
    T tmp;
    T pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);

}



int student::sort_by = 0;
int main()
{
    stu_list s("student.txt");
    vector <student> va;
    cout << "tes23t";
    s.list(va);
    cin >> student::sort_by;
    auto start_time = chrono::high_resolution_clock::now();
     quickSort(va , 0 , va.size()-1);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    s.OutPut_File("sorted.txt", "qui", duration);


}
