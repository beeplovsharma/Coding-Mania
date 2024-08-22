-- Write your PostgreSQL query statement below
select query_name,round(avg(rating * 1.0/position),2) as quality,
        round(avg(CASE
        when rating<3 then 1
        else 0
        END
        )*100,2) as poor_query_percentage
 from queries
group by query_name
having query_name is not NULL