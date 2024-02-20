from typing import (
    List,
)
from lintcode import (
    Interval,
)

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def min_meeting_rooms(self, intervals: List[Interval]) -> int:
        # Write your code here

        #bc 
        if(len(intervals)==0):
            return 0

        #sort by start
        intervals.sort(key= lambda i:i.start)
        #min heap
        end_times=[intervals[0].end]
        #loop thru intervals starting at 1
        for i in range(1,len(intervals)):
            #pop if startc > endp
            if(intervals[i].start >= end_times[0]):
                end_times.pop(0)
            # append to heap current end
            end_times.append(intervals[i].end)
            #sort iter(iterable)
            end_times.sort()
        return len(end_times)
