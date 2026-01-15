# Write your MySQL query statement below
SELECT score, 
(
    SELECT COUNT(DISTINCT s2.score)
    FROM Scores s2
    WHERE s2.score >= s1.score
) AS `rank`
FROM Scores s1
ORDER BY s1.score DESC

-- 列别名最好使用 反引号 `rank`
-- 