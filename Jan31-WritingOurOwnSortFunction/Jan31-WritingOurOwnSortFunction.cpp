

#include <iostream>
#include<vector>

#include<algorithm>

#include"C:/Users/Work/Downloads/Timing.h"


using std::vector; 
using std::cout; 
using std::endl; 


vector<int> generateNRandomInts(int N)
{
    vector<int> nums; 
    for (int i = 0; i < N; i++)
    {
        nums.push_back(rand() % N);
    }

    return nums; 
}

int findMin(vector<int> nums)
{
    int min = nums.at(0); 

    for (auto& num : nums)
    {
        if (num < min)
        {
            min = num; 
        }
    }

    return min; 

}

vector<int> out_of_place_sort(vector<int> unsortedNums) //10? elements = N (O(N) - > complexity of seq. search
{                                                               //binary search O(log(N)) - > BETTER than seq. search 
    vector<int> sortedNums; //extra space complexity 
    while (!unsortedNums.empty())
    {
        int currentMin = findMin(unsortedNums); //write your own `findMin`
        sortedNums.push_back(currentMin);

        auto positionOfCurrentMin = std::find(unsortedNums.begin(),unsortedNums.end(), currentMin);
      
        //unsortedNums.erase()
        unsortedNums.erase(positionOfCurrentMin);

        //std::erase(unsortedNums, currentMin);
    }

    return sortedNums; 
}


void print(vector<int> nums)
{
    for (auto& num : nums)
    {
        cout << num << " ";
    }
}

void nSquaredSort(std::vector<int>& nums, const int N)
{
    int comparisonCount = 0; 
    int swapCount = 0; 

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            comparisonCount++; 

            if (nums[i] > nums[j])//then swap
            {
                std::swap(nums[i], nums[j]); //#include<algorithm>
                swapCount++; 

                //cout << "\nMid-sorting algorithm: " << endl; 
                //print(nums);//print updated array for visualization:
                //system("pause");

            }
        }
        //cout << "Incrementing i to: " << i + 1 << endl;
    } //end outer for loop 
    
    
    cout << "\n\nTotal comparison count: " << comparisonCount << endl; 
    cout << "Total SWAP count: " << swapCount << endl; 

}



void measureSortTimeForN(int N)
{
    vector vectN = generateNRandomInts(N); 

    Timer* tn = new Timer;

    nSquaredSort(vectN, N);

    delete tn;
}

int main()
{
    
    vector<int> someNums = generateNRandomInts(10'000);
    

    cout.imbue(std::locale(""));

    /*generateNRandomInts(10);*/
    cout << "BEFORE calling the BUBBLE place sort!" << endl; 
    //print(someNums); 
 
    nSquaredSort(someNums, someNums.size());
    //std::sort(someNums.begin(), someNums.end());

    cout << "\n\nDone!" << endl; 
    //print(someNums); 

    cout << "\n\n";

}
