class Solution(object):
    @staticmethod
    def mergeSortedArrays(nums1, nums2, sum_length):
        """
        all input arrays should sorted from small to big
        """
        merged_nums = []
        i = j = k = 0
        max_j = len(nums1)
        max_k = len(nums2)
        while i < sum_length:
            if j >= max_j:
                merged_nums.extend(nums2[k:])
                break
            if k >= max_k:
                merged_nums.extend(nums1[j:])
                break
            # print '%d,nums1[%d]=%d,nums2[%d]=%d, to:%s' % (i, j, nums1[j], k, nums2[k], merged_nums)
            if nums1[j] < nums2[k]:
                merged_nums.append(nums1[j])
                j += 1
            elif nums1[j] == nums2[k]:
                merged_nums.append(nums1[j])
                merged_nums.append(nums1[j])
                j += 1
                k += 1
            else:
                merged_nums.append(nums2[k])
                k += 1
            i += 1

        return merged_nums

    @staticmethod
    def getMedian(nums, sum_length):
        user_average = sum_length % 2 == 0
        if user_average:
            return (nums[sum_length / 2] + nums[sum_length / 2 - 1]) / 2.0
        else:

            return nums[sum_length / 2]

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n = len(nums1)
        m = len(nums2)
        sum_length = m + n
        if 0 in (n, m):
            return self.getMedian(nums1 + nums2, sum_length)
        if nums1[-1] <= nums2[0]:
            return self.getMedian(nums1 + nums2, sum_length)

        elif nums2[-1] <= nums1[0]:
            return self.getMedian(nums2 + nums1, sum_length)

        else:
            return self.getMedian(self.mergeSortedArrays(nums1, nums2, sum_length), sum_length)


if __name__ == '__main__':
    print Solution().findMedianSortedArrays([], [4, 5, 6]) == 5
    print Solution().findMedianSortedArrays([1, 2, 3], [4, 5, 6]) == 3.5
    print Solution().findMedianSortedArrays([4, 5, 6], [1, 2, 3]) == 3.5
    print Solution().findMedianSortedArrays([2, 4, 5, 6], [1, 3]) == 3.5
