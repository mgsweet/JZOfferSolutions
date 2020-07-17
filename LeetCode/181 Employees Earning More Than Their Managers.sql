# Write your MySQL query statement below
SELECT e.Name AS Employee
FROM Employee e 
JOIN EMployee m
    ON e.ManagerId = m.Id
    AND e.Salary > m.Salary
;