/*
done
1. Implement the student class with its constructor.
2. Overload the operator < such that it compares the names
of two student objects.
3. Read student objects from a file named students.txt, which will have
the number of students followed by their information

still

4. Implement Insertion Sort, Selection Sort, Bubble Sort, Shell Sort,
Merge Sort, Quick Sort and Count Sort algorithms.
a. Each algorithm should be a separate function implemented using
templates to allow sorting of different types of data.
5. Sort the array of students’ objects with each of the previous algorithms.
a. Sort the data one time by Name and another time by GPA.

6. Calculate the running time of each algorithm for each array.
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
using namespace std;


class student
{
public:
    string id;
    string name;
    double gpa;
    student() : id("NULL"), name("NULL"), gpa(0.0) {}
    student(string ID, string NAME, double GPA) : id(ID), name(NAME), gpa(GPA) {}
    bool operator < (const student& another) {
        return name < another.name;
    }


};

class stu_list {
private:
    vector <student> v;
    int size;
public:
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
    void print()
    {
        for (auto element : v) {
            cout << element.name << endl;
            cout << element.id << endl;
            cout << element.gpa << endl;
        }
    }
};

int main()
{
    stu_list s("student.txt");
    s.print();
}


