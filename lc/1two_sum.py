class Solution(object):
    def twoSum_1(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        index_dict = {}
        for i, v in enumerate(nums):
            if index_dict.has_key(v):
                index_dict[v].append(i)
            else:
                index_dict[v] = [i]
        i = 0

        _cached = set()
        while i < length:
            if nums[i] in _cached:
                i += 1
                continue
            expected_number = target - nums[i]
            candidate = index_dict.get(expected_number, [])
            if candidate:
                for j in candidate:
                    if j != i:
                        return [i + 1, j + 1]
            _cached.add(nums[i])
            i += 1
        return []

    def twoSum_2(self, nums, target):
        length = len(nums)
        index_dict = {}
        for i, v in enumerate(nums):
            if index_dict.has_key(v):
                index_dict[v].append(i)
            else:
                index_dict[v] = [i]
        i = 0
        while i < length:
            expected_number = target - nums[i]
            candidate = index_dict.get(expected_number, [])
            if candidate:
                for j in candidate:
                    if j != i:
                        return [i + 1, j + 1]
            i += 1
        return []

    def twoSum_3(self, nums, target):
        length = len(nums)
        index_dict = {}
        for i, v in enumerate(nums):
            if index_dict.has_key(v):
                index_dict[v].append(i)
            else:
                index_dict[v] = [i]
        i = 0
        cache = set()
        for num, locations in index_dict.items():
            candidates = index_dict.get(target - num, [])
            i = locations[0]
            for j in candidates:
                if j != i:
                    return sorted([i + 1, j + 1])
        return []

    def twoSum_4(self, nums, target):
        index_dict = {}
        _iter = []
        for i, v in enumerate(nums):
            if index_dict.has_key(v):
                index_dict[v].append(i)
            else:
                index_dict[v] = [i]
                _iter.append((i, v))
        i = 0
        for location, num in _iter:
            candidates = index_dict.get(target - num, [])
            i = location
            for j in candidates:
                if j > i:
                    return [i + 1, j + 1]
                elif i > j:
                    return [j + 1, i + 1]
        return []

    def twoSum_5(self, nums, target):
        nums2 = [None] * 100000
        i = 0
        l = len(nums)
        while i < l:
            nums2[nums[i] + 5000] = i
            i += 1
        i = 0
        while i < l:
            temp = nums2[target - nums[i] + 5000]
            if temp != None and temp > i:
                return [i + 1, temp + 1]
            i += 1
        return []
            
    twoSum = twoSum_5
