# Databases

Database Design Steps:

- Conceptual Design
- Logical Design
- Physical Design
- Implementation
- Instance



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

3. When it comes to DATE, do not use `+1` to get the next date, Instead, use `DATE_ADD(w0.recorddate, interval 1 day)`. This is because when you subtract or add two dates in MySQL, they are treated as decimal numbers. Relevant functions include: `DATEDIFF(); DATE_ADD(w0.recorddate, interval 1 day) `.

4. `DISTINCT` can help get the exact rank of a row. Use `SELECT()` to cover a query can return`NULL`

5. Logic expression example:

   ```mysql
   # Write your MySQL query statement below
   UPDATE salary
   SET sex = CASE sex
           WHEN 'm' THEN 'f'
           ELSE 'm'
       END;
   ```

   

