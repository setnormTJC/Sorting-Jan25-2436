#include <iostream>
#include <vector>

#include<algorithm>

using namespace std;


bool isSorted(const std::vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1]) //checks for ascending sort
        {
            return false;
        }
    }
    return true; //only reached if all num[i] < num[i + 1]
}

void print(vector<int> nums)
{
    for (auto& num : nums)
    {
        cout << num << " ";
    }
}

//et al -> "and others" 
void bogoSort(std::vector<int>& nums)
{
    //std::is_sorted()
    while (!(isSorted(nums)))
    {
        //a shuffle algorithm:
        //std::shuffle();
        //std::random_shuffle()
        for (int i = 0; i < nums.size(); i++)
        {
            std::swap(nums[i], nums[rand() % nums.size()]);
        }

        //cout << "Is it sorted yet? " << endl; 
        //print(nums); 

    }
}

int main()
{
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "Attempting!" << endl; 
    bogoSort(nums); 
    cout << "Done!" << endl; 


    return 0;
}