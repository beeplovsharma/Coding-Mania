-- Write your PostgreSQL query statement below
-- SELECT s.student_id,s.student_name,e.subject_name,count(*) FROM Examinations as e
-- RIGHT JOIN Students as s
-- ON s.student_id = e.student_id
-- GROUP BY s.student_id,s.student_name,e.subject_name
-- ORDER BY student_id ASC

SELECT s.student_id,s.student_name,sub.subject_name,COUNT(e.student_id) as attended_exams FROM Students as s
CROSS JOIN Subjects sub
LEFT JOIN Examinations e
ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY s.student_id,s.student_name,sub.subject_name
ORDER BY s.student_id,sub.subject_name