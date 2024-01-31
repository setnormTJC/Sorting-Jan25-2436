

#include <iostream>
#include<vector>

using std::vector; 

using std::cout; 

using std::endl; 

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

vector<int> out_of_place_sort(vector<int> unsortedNums)
{
    vector<int> sortedNums;
    while (!unsortedNums.empty())
    {
        int currentMin = findMin(unsortedNums); //write your own `findMin`
        sortedNums.push_back(currentMin);

        auto positionOfCurrentMin = std::find(unsortedNums.begin(),unsortedNums.end(),
                                                currentMin);
        //unsortedNums.erase()
        unsortedNums.erase(positionOfCurrentMin);
    }

    return sortedNums; 
}

int main()
{
    //std::cout << "Hello World!\n";

    vector<int> someNums = { 1, -4, -5, 7, 5, 8, 10 };
    //std:: cout << findMin(someNums) << endl;
    vector<int> SORTEDnums = out_of_place_sort(someNums);

    auto a = 5.0f; //OpenGL
    
    vector<SomeClass> list


















    for (auto& num : list)
    {
        cout << num << " ";
    }
    cout << "\n\n";

}
