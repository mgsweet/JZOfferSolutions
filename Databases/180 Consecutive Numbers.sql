# Write your MySQL query statement below
SELECT DISTINCT l1.Num AS ConsecutiveNums
FROM Logs l1
CROSS JOIN Logs l2
CROSS JOIN Logs l3
WHERE
    l1.Id = l2.Id + 1 AND l2.Id = l3.Id + 1 AND l1.Num = l2.Num AND l2.Num = l3.Num