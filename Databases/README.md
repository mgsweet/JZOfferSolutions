# Databases

## MySQL
1. Delete Duplicate example:

```mysql
# Write your MySQL query statement below
DELETE p1 FROM Person p1, Person p2
WHERE p1.email = p2.email AND p1.Id > p2.Id
```

2. Find Duplicate example:

```mysql
SELECT Email 
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1
```

3. When it comes to DATE, do not use `+1` to get the next date, Instead, use `DATE_ADD(w0.recorddate, interval 1 day)`.

   This is because when you subtract or add two dates in MySQL, they are treated as decimal numbers.

   Relevant function: `DATEDIFF(); DATE_ADD(w0.recorddate, interval 1 day) `

