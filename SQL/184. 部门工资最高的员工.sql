
SELECT 
    Department.name AS `Department`,
    Employee.name AS `Employee`,
    Salary
FROM Employee JOIN Department ON Employee.DepartmentId=Department.Id
-- 这个ON的意思是根据什么条件来合并的两个表
WHERE (Employee.DepartmentId, Salary) IN
(
    SELECT DepartmentId, MAX(Salary)
    FROM Employee
    GROUP BY DepartmentId
)

-- 默认JOIN = INNER JOIN
-- INNER JOIN： 只保留两张表中能匹配上的行
-- LEFT JOIN: 