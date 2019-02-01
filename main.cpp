// The function must accept a templated array
// and a start and end index

/*	Example:
	str::array<int,10> myArray{1,9,7,6,3,8,5,2,4,10};
	cout << recursiveMinimum(myArray, 0, myArray.size());
*/
#include <iostream>
#include <array>
using namespace std;

// Tracing function calls
template<typename T, size_t S>
T recursiveMinimum(array<T,S> arr, size_t start, size_t end) {
	
	cout << "Array: ";
	for(size_t i{start}; i < end; i++) cout << arr[i] << " ";
	cout << "\n";
	cout << "Start: " << start << "\n";
	cout << "End: " << end << "\n";
	
	if(start == end - 1) return arr[start];
	
	T leftMin  = arr[start];
	T rightMin = recursiveMinimum(arr, start+1, end);
	
	return (leftMin < rightMin) ? leftMin : rightMin;
}

int main() {
	array<int,10> myArray{1,9,7,6,3,8,5,2,4,10};
	cout << recursiveMinimum(myArray, 0, myArray.size());
	
	array<char,5> anotherArray{'i', 'u', 'o', 'e', 'a'};
	cout << recursiveMinimum(anotherArray, 0, anotherArray.size());
}