/*Given an array of integers nums and an integer k, determine whether there are two distinct indices i and j in the array where nums[i] = nums[j] and the absolute difference between i and j is less than or equal to k.
*/
bool solution(vector<int> nums, int k) {
unordered_map<int, int>m;
//looop thru nums
int n = nums.size();
for(int i = 0; i<n;i++)
{
    //look for pair in map
    if(m.find(nums[i])!=m.end())
    {
        //check if condition true
        if(i-m[nums[i]]<=k)
        {
            return true;
        }
    }
    m[nums[i]]=i;
}
return false;
}
