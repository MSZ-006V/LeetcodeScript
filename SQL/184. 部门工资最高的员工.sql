
SELECT 
    Department.name AS `Department`,
    Employee.name AS `Employee`,
    Salary
FROM Employee JOIN Department ON Employee.DepartmentId=Department.Id
WHERE (Employee.DepartmentId, Salary) IN
(
    SELECT DepartmentId, MAX(Salary)
    FROM Employee
    GROUP BY DepartmentId
)

-- 默认JOIN = INNER JOIN
-- INNER JOIN： 只保留两张表中能匹配上的行

- 手机征用算力，叫什么概念（和edge computing有关）
- 更新github，需要有visualization的东西
- edge computing（有一个简短slide，描述做什么，工作量，是否可以在2个quarter完成），目标，工作量，milestone
    - 是否有什么现有的框架（ray architecture），发现内部的问题，然后查看怎么解决
    - 可以不用重复造轮子
    - 寻找现有系统的问题，然后查看有什么缺陷，然后尝试解决
    - 分布式算力架构的程序（Go），或者使用cpp
    - 关键词: fog computing，edge computing，crowd computing