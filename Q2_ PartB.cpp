#include <iostream>
#include <vector>
using namespace std;

/* part B - problem 2:
    * complexity analysis:
    • best case: O(n) --> target is at the first mid
    • worst case:
        no duplication --> O(log n) --> search space halves each iteration
        with duplication --> O(n) --> when arr[l] == arr[mid] == arr[r] repeatedly 
*/
int rotatedSortedArray(const vector<int>& arr, int target){
    int l = 0;
    int r = arr.size() - 1;
    int comNum = 0; // to sum the number of comparisons 
    while(l <= r){
        int mid = l + (r - l) / 2;
        comNum ++; // 1. if(mid == target)?
        if (arr[mid] == target){
            cout << "total comparisons: " << comNum << endl;
            cout << "at index: ";
            return mid;
        }
        if (arr[l] == arr[mid] && arr[r] == arr[mid]){ // duplication handling 
            l++;
            r--;
            continue;
        }
        else if (arr[l] <= arr[mid]){ // the left side is sorted
            comNum++; // 2. if the target is in the sorted left side?
            if (arr[l] <= target && target < arr[mid]){
                r = mid - 1; // search left
            }
            else{
                l = mid + 1; // search right
            }
        }
        else{ // the right side is sorted 
            comNum ++; // 3. if the target is in the sorted right side?
            if (arr[mid] < target && target <= arr[r]){
                l = mid + 1; // search right 
            }
            else{
                r = mid - 1; // search left
            }
        }
    }
    
    cout << "total comparisons: " << comNum << endl;
    return -1; // if not found!!
}

int main() { 
    // return the number of comparisons and the index of the found target 
    vector<int> v = {5,6,7,1,2,3,4};
    cout << rotatedSortedArray(v, 2) << endl;
    cout << rotatedSortedArray(v, 7) << endl; // search for the peak
    vector<int> d = {2,5,6,1,2,2,2}; // Example with duplication 
    cout << rotatedSortedArray(d, 6) << endl;
    
    return 0;
}