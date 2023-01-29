#include<bits/stdc++.h>
using namespace std;
class FloatArray {
protected:
	int size;
	float* arr;
	int count = 0;
public:
	FloatArray(int size) {
		this ->size = size;
		arr = new float[size];
	}
	virtual void add(float x) {
		if (count < size) {
			arr[count] = x;
			count++;
		}

	}
	friend ofstream& operator<<(ofstream& outputFile, const FloatArray& array) {
		for (int i = 0; i < array.size; i++) {
			outputFile << array.arr[i]<<" ";
		}
		return outputFile;
	}
	friend  ifstream& operator>>(ifstream& inputFile, FloatArray& array) {
		for (int i = 0; i < array.size; i++) {
			inputFile >> array.arr[i] ;
		}
		return inputFile;
	}
	//~FloatArray() {
	//	delete[]arr;
//	}

};
class SortedArray :public FloatArray {
private:
	int size1;

public:
	SortedArray(int size1):FloatArray(size1) {
		this->size1 = size1;
	}
	void add(float x) {
		if (count < size) {
			int p=0;
			for (int i = 0; i < count; i++) {
				//cout << count << endl;
				if (x < arr[i]) {
					p = i;
					break;
				}
				else {
					p = i + 1;
				}
			}
			for (int i = count + 1; i >= p; i--) {
				arr[i] = arr[i - 1];
				
			}
			arr[p] = x;
			count++;
		}
		

	}
	void print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}

};
class FrontArray:public FloatArray {
private:
	int size;
public:
	FrontArray(int size) :FloatArray( size) {
		this ->size = size;
	}
	void add(float x) {
		if (count < size) {
			for (int i = count + 1; i >= 0; i--) {
				arr[i] = arr[i - 1];

			}
			arr[0] = x;
			count++;
		
		}
	}
	void print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}
};
class PositiveArray :public SortedArray {
private:
	int size;
public:
	PositiveArray(int size) :SortedArray(size){
		this->size = size;
	}
	void add(float x) {
		if (x > 0) {
			if (count < size) {
				int p = 0;
				for (int i = 0; i < count; i++) {
					//cout << count << endl;
					if (x < arr[i]) {
						p = i;
						break;
					}
					else {
						p = i + 1;
					}
				}
				for (int i = count + 1; i >= p; i--) {
					arr[i] = arr[i - 1];

				}
				arr[p] = x;
				count++;
			}

		}
	}
	void print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}


};

class NegativeArray :public SortedArray {
private:
	int size;
public:
	NegativeArray(int size) :SortedArray(size) {
		this->size = size;
	}
	void add(float x) {
		if (x < 0) {
			if (count < size) {
				int p = 0;
				for (int i = 0; i < count; i++) {
					//cout << count << endl;
					if (x < arr[i]) {
						p = i;
						break;
					}
					else {
						p = i + 1;
					}
				}
				for (int i = count + 1; i >= p; i--) {
					arr[i] = arr[i - 1];

				}
				arr[p] = x;
				count++;
			}

		}
	}
	void print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}


};

int main(){
    FloatArray* ptr;
	ifstream inputFile("in.txt");
	ofstream outputFile("out.txt");
	int n = 1;
	//while (n--) {
		string name;
		inputFile >> name;
		if (name == "Sorted") {
			int num;
			inputFile >> num;
			int count = num;
			ptr = new SortedArray(num);
			while (num--) {
				char space;
				inputFile >> space;
				int elem;
				inputFile >> elem;
				ptr->add(elem);
			}
			outputFile << name<<"|"<<count<<" ";
			outputFile << *ptr;
			
		//}






	}













	


	return 0;
}