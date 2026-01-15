-- Write your PostgreSQL query statement below
SELECT
(
    SELECT DISTINCT Salary
    FROM Employee
    ORDER BY Salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary

-- limit: 控制最后输出几个数据
-- offet：控制跳过几个
-- DISTINCT：去掉重复行，保留唯一值。因为这里salary可能重复，所以要去重