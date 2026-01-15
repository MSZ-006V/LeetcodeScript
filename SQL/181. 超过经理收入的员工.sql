# Write your MySQL query statement below
SELECT name AS Employee
FROM Employee e1
WHERE e1.managerId IS NOT Null AND e1.salary > (
    SELECT e2.salary
    FROM Employee e2
    WHERE e2.id = e1.managerId
)