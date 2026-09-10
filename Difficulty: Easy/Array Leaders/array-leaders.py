class Solution:
    def leaders(self, nums):
        largest = nums[-1]
        leaders = [largest]

        for i in range(len(nums) - 2, -1, -1):
            if nums[i] >= largest:
                largest = nums[i]
                leaders.append(nums[i])

        leaders.reverse()
        return leaders