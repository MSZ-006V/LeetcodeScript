# https://leetcode.com/discuss/interview-question/5834140/TikTok-OA-Backend-Software-Engineer-2024
def count(str, k, engagementArray):
    res = 0
    array = [engagementArray[ord(str[i]) - ord('a')] for i in range(len(str))]
    print(array)
    for i in range(len(str)):
        non_viral_num = 0
        for j in range(i, len(str)):
            non_viral_num += array[i]
            if(non_viral_num < k):
                res += 1

    return res

def count_comb(str):
    return 0

exstr = "stream"
k = 2
array =   [0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
# print(count(exstr, k, array))
print(count_comb(exstr))
