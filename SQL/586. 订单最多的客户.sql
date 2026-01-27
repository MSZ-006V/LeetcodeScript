SELECT customer_number
FROM Orders
GROUP BY customer_number -- 分组
ORDER BY COUNT(*) DESC -- 统计每一组的数量
LIMIT 1 -- 只显示第一个结果