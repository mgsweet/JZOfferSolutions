# Write your MySQL query statement below
SELECT 
    c.Name AS Customers
FROM Customers c
WHERE c.ID NOT IN 
(
    SELECT CustomerId FROM Orders
)
;