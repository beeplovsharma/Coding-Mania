CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE result INT;
    SET result = (
        SELECT salary 
        FROM (
            SELECT salary, dense_rank() OVER (ORDER BY salary DESC) AS rn 
            FROM Employee
        ) AS cte1
        WHERE cte1.rn = N
        LIMIT 1
    );
    RETURN result;
END;
