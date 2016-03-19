class Solution(object):
    """
    scan string from left to right
    setup the dict record val(key)->location, and treat this no repeating sub string as a 'bus'
    if meet same characters, cut of from breakpoint (the same characters location)
    eg:
        a b c d e f c ...
        0 1 2 3 4 5 | <- when walk here
                    because there is c in our record , and index is 2 , so remove all
                    elements before out bus_start to 2 , then refresh the maximum length of bus,
                    then continue walking until end


    """

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        index = 0
        bus_start = index
        bus = {}
        max_bus_length = 0
        while index < length:
            val = s[index]
            if val in bus:
                break_from = bus[val]
                for get_out in s[bus_start:break_from]:
                    bus.pop(get_out)
                bus_start = break_from + 1
            bus[val] = index
            index += 1
            bus_end = index
            max_bus_length = max(bus_end - bus_start, max_bus_length)
            # print "%s\n[%d:%d] %r %d" % (bus, bus_start, bus_end, s[bus_start:bus_end],max_bus_length)
        return max_bus_length


if __name__ == '__main__':
    print Solution().lengthOfLongestSubstring('abcdeafc') == 6
    print Solution().lengthOfLongestSubstring("ruowzgiooobpple") == 7
