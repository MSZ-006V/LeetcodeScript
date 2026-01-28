UPDATE Salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END

-- SET sex = ... 表示要更新sex这一列
-- CASE sex ... END SQl的条件表达式
-- WHEN 'm' THEN 'f' 如果当前行为'm'，则更新为'f'