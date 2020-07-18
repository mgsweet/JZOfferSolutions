CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE var INT;
  SET var = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT (
        SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT var, 1
      ) AS getNthHighestSalary
  );
END