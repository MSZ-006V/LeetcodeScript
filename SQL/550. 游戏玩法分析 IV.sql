SELECT ROUND(SUM(IF(temp.player_id is null, 0, 1)) / COUNT(DISTINCT a.player_id), 2) AS 'fraction'
FROM Activity a 
LEFT JOIN (
    SELECT player_id, MIN(event_date) AS 'firstdate'
    FROM Activity
    GROUP BY player_id
) AS temp
ON a.player_id=temp.player_id
AND DATEDIFF(a.event_date, temp.firstdate)=1