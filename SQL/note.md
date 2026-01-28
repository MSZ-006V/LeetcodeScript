## SQL笔记
1. INNER JOIN, LEFT JOIN, RIGHT JOIN
- 默认JOIN = INNER JOIN
- INNER JOIN: 只保留两张表中能匹配上的行，只返回两个表中 匹配条件 的行。如果某一行在任意一个表里没有匹配，就不会出现在结果里
    - 一般需要搭配 ON 使用，表示两个表合并的条件。如果没有相当于对两个表进行笛卡尔积运算（会把表A和表B每一行匹配）
- LEFT JOIN: 返回左表的所有行，即使右表没有匹配的行也会显示，未匹配的列用 NULL 填充
    - 如果想保留右表没有的，也可以使用 OR xx.xx IS NULL 来保留
- RIGHT JOIN: 返回右表的所有行，即使左表没有匹配的行也会显示，未匹配的列用 NULL 填充
- ON 在 LEFT/RIGHT JOIN中主要也是表达两个表合并的条件

2. 常用日期相关函数
- DATEDIFF(A, B) = A - B = 正数/负数: 两个日期之间相差的天数

3. 常用函数
- GROUP BY
    - 把“多行”按某个规则，折叠成“每组一行”
    - 依据GROUP BY id，通过把具有所有相同id的列放入同一个桶中，最终只输出一个结果
    - 通常可以搭配聚合函数使用，如 MIN(), MAX(), DISTINCT, COUNT(), SUM(), AVG()
    - 如果在GROUP BY后点出条件，一般编译器会随机挑选一行（也有可能报错，不允许）
    - 可以GROUP BY多个变量，如 GROUP BY lat, lon HAVING COUNT(*)=1 (即为找出这个(lat, lon)只出现过一次的组合)
- HAVING
    - 可以搭配GROUP BY使用，同时可以使用函数
- IF
    - 定义：IF(condition, value_if_true, value_if_false)
    - 可以把逻辑条件变成数值，比如 IF(temp.player_id is null, 0, 1)，如果是null那就是0，如果不是就是1
- SUM
    - 定义：SUM(expr)
    - 对一组行的expr求和，并且忽略NULL
- ROUND
    - 定义：ROUND(number, decimals), 前一个是数值，后面是保留的小数位数（支持对结果四舍五入）
- 聚合函数不能嵌套！！！如MAX(COUNT(*))
- 条件(CASE WHEN THEN END): 对column_or_expression进行匹配，如果有等于WHEN后的值，就返回THEN的结果。否则返回ELSE（相当于DEFAULT），如果没有ELSE则返回NULL
    - 也可以写 WHEN value IN ('c1', 'c2') THEN
```
CASE column_or_expression
    WHEN value1 THEN result1
    WHEN value2 THEN result2
    ...
    ELSE default_result  -- 可选
END
```
- GROUP_CONCAT(expression [ORDER BY ...] [SEPARATOR 'sep']): 把分组后的多行数据拼接成字符串，默认分隔符为 ',' , 用法GROUP_CONCAT(name ORDER BY name)

4. Update语句
- 题目：627

5. 好题
- 1141：包括GROUP BY，HAVING，WHERE，COUNT(DISTINCT *)等条件，复杂