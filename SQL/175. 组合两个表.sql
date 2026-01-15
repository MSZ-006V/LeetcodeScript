-- Write your PostgreSQL query statement below
SELECT FirstName, LastName, City, State
FROM Person left join Address
ON Person.PersonId = Address.PersonId

-- left join: 以左表（Person）为主，右表（Address）能连上就连，连不上就补 NULL
-- on: 连接条件，定义“两张表如何匹配成一行”的条件。