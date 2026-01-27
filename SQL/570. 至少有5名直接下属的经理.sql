SELECT e1.name AS 'name'
FROM Employee e1
WHERE e1.id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*)>=5
)

-- HAVING: WHERE 过滤“行”，HAVING 过滤“组”