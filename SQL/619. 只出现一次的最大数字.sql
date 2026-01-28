SELECT MAX(num) AS 'num'
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*)<2
) AS temp
