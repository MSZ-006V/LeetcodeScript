SELECT
    CASE -- 用英文单引号包裹字符串，修正层级判断
        WHEN c.name IN ('Austria', 'Belgium', 'France', 'Germany') THEN 'A'
        WHEN c.name IN ('United Kingdom', 'United States') THEN 'B'
        ELSE 'C'
    END AS tier, -- 给输出列命名
    -- 拼接层级对应的国家列表
    GROUP_CONCAT(DISTINCT c.name ORDER BY c.name) AS countries,
    -- 统计交易总数（补充题目要求的transactions列）
    COUNT(t.customer_id) AS transactions,
    -- 计算交易总金额（保留2位小数）
    ROUND(SUM(t.amount), 2) AS total_amount,
    -- 计算总佣金（保留2位小数）
    ROUND(SUM(t.amount * c.commission), 2) AS total_commission
FROM transactions t
-- 关联客户表
JOIN customers cu ON t.customer_id = cu.id
-- 关联国家佣金表
JOIN countries c ON cu.country = c.name
-- 按层级分组聚合
GROUP BY tier
-- 按层级排序
ORDER BY tier;