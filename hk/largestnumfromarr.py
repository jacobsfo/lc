from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Custom comparison function for sorting
        def compare(a, b):
            return int(b + a) - int(a + b)
        
        # Convert integers to strings
        nums = map(str, nums)
        
        # Sort the array using the custom comparison function
        nums.sort(key=compare)
        
        # Join the sorted array into a single string
        largest_num = ''.join(nums)
        
        # Remove leading zeros
        largest_num = largest_num.lstrip('0')
        
        # Return the result
        return largest_num if largest_num else '0'
