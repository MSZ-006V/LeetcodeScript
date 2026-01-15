
SELECT name AS Customers
FROM Customers AS c1
WHERE c1.id NOT IN
(
    SELECT c.id
    FROM Customers AS c, Orders AS o
    WHERE c.id = o.customerId
)

-- 也可以这么写，简单很多
SELECT name AS Customers
FROM Customers
WHERE Customers.id NOT IN
(
SELECT customerId FROM Orders
)
