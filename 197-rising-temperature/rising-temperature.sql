SELECT w1.id FROM Weather as w1
INNER JOIN Weather as w2
ON w1.recordDate = w2.recordDate + INTERVAL '1 DAY'
WHERE w1.temperature > w2.temperature