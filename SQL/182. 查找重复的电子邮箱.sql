# Write your MySQL query statement below
SELECT email FROM 
(
    SELECT email, COUNT(email) AS cnt
    FROM Person
    GROUP BY email
) as Email
WHERE cnt > 1