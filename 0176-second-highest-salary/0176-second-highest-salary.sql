# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (
    SELECT MAX(salary) FROM Employee
);
-- SELECT MAX(salary) AS SecondHighestSalary
-- FROM Employee
-- WHERE salary NOT IN (
--     SELECT MAX(salary) FROM Employee
-- );

-- SELECT DISTINCT salary AS SecondHighestSalary
-- FROM Employee
-- ORDER BY salary DESC
-- LIMIT 1 OFFSET 1;

-- SELECT salary AS SecondHighestSalary
-- FROM Employee
-- GROUP BY salary
-- ORDER BY salary DESC
-- LIMIT 1 OFFSET 1;
