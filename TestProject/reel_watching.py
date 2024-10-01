# https://leetcode.com/discuss/interview-question/5836079/TikTok-or-OA-or-Optimize-TikTok-Reels-Viewing
# 非常好的一个想法，因为在观看的时候，观看顺序和次数一定是1, 1, 1, m - 3，重复观看的reel一定是最后一个观看的
# 算法是O(n)的，非常高效
def count(initwatch, rewatch, m):
    ans = float('inf')
    cur = 0
    left = m
    for i in range(len(initwatch)):
        cur += initwatch[i] + rewatch[i]
        left -= 1
        ans = min(ans, cur + left * rewatch[i])
        
    return ans

# ititial_watch = [6,8,9]
# re_watch = [4, 2, 10]
# m = 5

ititial_watch = [1, 5, 9, 11]
re_watch = [2, 7, 10, 11]
m = 4

print(count(ititial_watch, re_watch, m))